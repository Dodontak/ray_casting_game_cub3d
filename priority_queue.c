/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:06:54 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/23 18:34:32 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

t_pq_node	*pq_pop(t_pq *pq)
{
	t_pq_node	*ret;
	t_pq_node	*biggest;
	int			cur;
	int			child;

	biggest = pq->min_heap[pq->heap_size - 1];
	ret = pq->min_heap[0];
	cur = 0;
	child = 2 * cur + 1;
	while (child < pq->heap_size)
	{
		if (child + 1 < pq->heap_size
			&& pq->min_heap[child]->score > pq->min_heap[child + 1]->score)
			child++;
		if (biggest->score <= pq->min_heap[child]->score)
			break ;
		pq->min_heap[cur] = pq->min_heap[child];
		cur = child;
		child = 2 * cur + 1;
	}
	pq->min_heap[cur] = biggest;
	pq->heap_size--;
	return (ret);
}

static void	allocate_double_array(t_pq *pq)
{
	t_pq_node	**tmp;
	int			i;

	tmp = (t_pq_node **)safe_malloc(
			2 * pq->heap_capacity * sizeof(t_pq_node *));
	i = 0;
	while (i < pq->heap_size)
	{
		tmp[i] = pq->min_heap[i];
		i++;
	}
	free(pq->min_heap);
	pq->min_heap = tmp;
	pq->heap_capacity *= 2;
}

void	pq_push(t_pq *pq, t_pq_node *new)
{
	int			i;

	if (pq->heap_size == pq->heap_capacity)
		allocate_double_array(pq);
	i = pq->heap_size;
	while (i > 0 && new->score < pq->min_heap[(i - 1) / 2]->score)
	{
		pq->min_heap[i] = pq->min_heap[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	pq->min_heap[i] = new;
	pq->heap_size++;
}

void	pq_free(t_data *data, t_pq *pq)
{
	int	i;

	i = 0;
	while (i < data->map.map_y_len)
	{
		free(pq->visit[i]);
		i++;
	}
	i = 0;
	while (i < pq->heap_size)
	{
		free(pq->min_heap[i]);
		i++;
	}
	free(pq->visit);
	free(pq->min_heap);
}

void	pq_init(t_data *data, t_pq *pq)
{
	int			y;
	t_pq_node	*current_position;

	ft_memset(pq, 0, sizeof(t_pq));
	pq->visit = (bool **)safe_malloc(data->map.map_y_len * sizeof(bool *));
	y = 0;
	while (y < data->map.map_y_len)
	{
		pq->visit[y]
			= (bool *)safe_malloc(data->map.map_x_len * sizeof(bool));
		ft_memset(pq->visit[y], 0, data->map.map_x_len * sizeof(bool));
		y++;
	}
	pq->heap_capacity = 1;
	pq->min_heap = (t_pq_node **)safe_malloc(
			pq->heap_capacity * sizeof(t_pq_node *));
	current_position = (t_pq_node *)safe_malloc(sizeof(t_pq_node));
	current_position->dir = p_zero;
	current_position->dist = 0;
	current_position->pos = data->enemy_pos;
	current_position->score = current_position->dist
		+ get_euclidian_dist(&current_position->pos, &data->player_pos);
	pq_push(pq, current_position);
}
