/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:40:44 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/23 20:20:17 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

static void	sprite_pq_free(t_pq *pq)
{
	free(pq->min_heap);
}

static void	sprite_pq_init(t_pq *pq)
{
	ft_memset(pq, 0, sizeof(t_pq));
	pq->heap_capacity = 1;
	pq->min_heap = (t_pq_node **)safe_malloc(
			pq->heap_capacity * sizeof(t_pq_node *));
}

static void	sort(t_data *data, t_pq *pq)
{
	t_sprite	*new_sprite;
	t_pq_node	*node;
	int			i;

	new_sprite = (t_sprite *)safe_malloc(data->sprite_num * sizeof(t_sprite));
	i = 0;
	while (pq->heap_size)
	{
		node = pq_pop(pq);
		new_sprite[i++] = *node->addr;
		free(node);
	}
	free(data->sprite);
	data->sprite = new_sprite;
}

void	sort_sprite(t_data *data)
{
	t_pq		pq;
	t_pq_node	*node;
	int			i;

	sprite_pq_init(&pq);
	i = 0;
	while (i < data->sprite_num)
	{
		node = (t_pq_node *)safe_malloc(sizeof(t_pq_node));
		ft_memset(node, 0, sizeof(t_pq_node));
		node->addr = &data->sprite[i];
		node->score = -node->addr->dist;
		pq_push(&pq, node);
		i++;
	}
	sort(data, &pq);
	sprite_pq_free(&pq);
}
