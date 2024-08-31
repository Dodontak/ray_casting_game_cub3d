/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:29:35 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/21 16:54:06 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_vertical_ray(t_data *data, t_ray *ray)
{
	if (data->env_map[ray->map_v.y][ray->map_v.x].type == e_wall)
	{
		ray->hit_door_v = false;
		ray->vertical_dist
			= get_euclidian_dist(&data->player_pos, &ray->vertical);
	}
	else if (data->env_map[ray->map_v.y][ray->map_v.x].type == e_closed_door
		|| (data->env_map[ray->map_v.y][ray->map_v.x].type == e_trans_door
		&& ray->vertical.y + ray->dv.y / 2
		< ray->map_v.y
		+ (1 - data->env_map[ray->map_v.y][ray->map_v.x].door_ratio)))
	{
		ray->hit_door_v = true;
		ray->vertical.x += ray->dv.x / 2;
		ray->vertical.y += ray->dv.y / 2;
		ray->vertical_dist
			= get_euclidian_dist(&data->player_pos, &ray->vertical);
	}
}

void	check_horizontal_ray(t_data *data, t_ray *ray)
{
	if (data->env_map[ray->map_h.y][ray->map_h.x].type == e_wall)
	{
		ray->hit_door_h = false;
		ray->horiznal_dist
			= get_euclidian_dist(&data->player_pos, &ray->horiznal);
	}
	else if (data->env_map[ray->map_h.y][ray->map_h.x].type == e_closed_door
		|| (data->env_map[ray->map_h.y][ray->map_h.x].type == e_trans_door
		&& ray->horiznal.x + ray->dh.x / 2
		< ray->map_h.x
		+ (1 - data->env_map[ray->map_h.y][ray->map_h.x].door_ratio)))
	{
		ray->hit_door_h = true;
		ray->horiznal.x += ray->dh.x / 2;
		ray->horiznal.y += ray->dh.y / 2;
		ray->horiznal_dist
			= get_euclidian_dist(&data->player_pos, &ray->horiznal);
	}
}
