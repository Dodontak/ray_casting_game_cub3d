/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_door_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:14:41 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 14:34:14 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

#include <math.h>

static void	door_list_add(t_data *data, const t_ipos *door_pos)
{
	t_door	*new;

	new = safe_malloc(sizeof(t_door));
	ft_memset(new, 0, sizeof(t_door));
	new->mpos = *door_pos;
	if (data->door_list.head == NULL)
	{
		data->door_list.head = new;
		data->door_list.tail = new;
		return ;
	}
	data->door_list.tail->next = new;
	data->door_list.tail = data->door_list.tail->next;
}

bool	enemy_change_door(t_data *data, t_fpos *pos, t_fpos *d)
{
	const t_ipos	colision = {(int)(pos->x + 3 * d->x),
		(int)(pos->y + 3 * d->y)};

	if (data->env_map[colision.y][colision.x].type == e_closed_door)
	{
		door_list_add(data, &colision);
		data->env_map[colision.y][colision.x].type = e_trans_door;
		data->env_map[colision.y][colision.x].last_state = d_close;
		data->env_map[colision.y][colision.x].door_ratio = 0;
		return (true);
	}
	else if (data->env_map[colision.y][colision.x].type == e_trans_door)
		return (true);
	return (false);
}

void	change_door_state(t_data *data, t_fpos *pos, double angle)
{
	const t_ipos	colision = {pos->x + cos(angle), pos->y + sin(angle)};

	if (colision.x == (int)pos->x && colision.y == (int)pos->y)
		return ;
	if (data->env_map[colision.y][colision.x].type == e_closed_door)
	{
		door_list_add(data, &colision);
		data->env_map[colision.y][colision.x].type = e_trans_door;
		data->env_map[colision.y][colision.x].last_state = d_close;
		data->env_map[colision.y][colision.x].door_ratio = 0;
	}
	else if (data->env_map[colision.y][colision.x].type == e_opened_door)
	{
		door_list_add(data, &colision);
		data->env_map[colision.y][colision.x].type = e_trans_door;
		data->env_map[colision.y][colision.x].last_state = d_open;
		data->env_map[colision.y][colision.x].door_ratio = 1;
	}
}
