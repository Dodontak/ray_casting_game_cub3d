/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_door_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:31:20 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/21 17:13:32 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delete_node(t_data *data, t_door **cur, t_door **front)
{
	t_door	*del;

	if (data->env_map[(*cur)->mpos.y][(*cur)->mpos.x].last_state == d_close)
		data->env_map[(*cur)->mpos.y][(*cur)->mpos.x].type = e_opened_door;
	else
		data->env_map[(*cur)->mpos.y][(*cur)->mpos.x].type = e_closed_door;
	del = *cur;
	if (*cur == data->door_list.head)
	{
		data->door_list.head = (*cur)->next;
		*cur = NULL;
	}
	else
	{
		(*front)->next = (*cur)->next;
		*cur = *front;
	}
	free(del);
}

void	progress_door_state(t_data *data)
{
	t_door	*cur;
	t_door	*front;

	front = NULL;
	cur = data->door_list.head;
	while (cur)
	{
		if (data->env_map[cur->mpos.y][cur->mpos.x].last_state == d_close)
			data->env_map[cur->mpos.y][cur->mpos.x].door_ratio += 1.0 / FPS * 2;
		else
			data->env_map[cur->mpos.y][cur->mpos.x].door_ratio -= 1.0 / FPS * 2;
		if ((data->env_map[cur->mpos.y][cur->mpos.x].last_state == d_close
			&& data->env_map[cur->mpos.y][cur->mpos.x].door_ratio >= 1)
		|| (data->env_map[cur->mpos.y][cur->mpos.x].last_state == d_open
			&& data->env_map[cur->mpos.y][cur->mpos.x].door_ratio <= 0))
			delete_node(data, &cur, &front);
		if (cur == NULL)
			cur = data->door_list.head;
		else
		{
			front = cur;
			cur = cur->next;
		}
	}
}
