/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:11:55 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/23 15:05:48 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "parse/parse.h"
#include <math.h>

static void	vertical_texture(t_data *data, t_ray *ray, t_wall *wall)
{
	if (ray->hit_door_v)
	{
		wall->texture = &data->textures[ti_door];
		if (data->env_map[ray->map_v.y][ray->map_v.x].type == e_trans_door)
			wall->x_off = data->env_map[ray->map_v.y][ray->map_v.x].door_ratio;
	}
	else if ((ray->map_v.x - 1 >= 0
			&& (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
			&& (data->map.map[ray->map_v.y][ray->map_v.x - 1] == m_door))
		|| (ray->map_v.x + 1 < data->map.map_x_len
			&& (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
			&& (data->map.map[ray->map_v.y][ray->map_v.x + 1] == m_door)))
		wall->texture = &data->textures[ti_door_side];
	else if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
		wall->texture = &data->textures[ti_west];
	else
		wall->texture = &data->textures[ti_east];
	wall->ray = ray->vertical;
	wall->dist = ray->vertical_dist * cos(wall->normal_angle);
}

static void	horiznal_texture(t_data *data, t_ray *ray, t_wall *wall)
{
	if (ray->hit_door_h)
	{
		wall->texture = &data->textures[ti_door];
		if (data->env_map[ray->map_h.y][ray->map_h.x].type == e_trans_door)
			wall->x_off = data->env_map[ray->map_h.y][ray->map_h.x].door_ratio;
	}
	else if ((ray->map_h.y - 1 >= 0
			&& (ray->angle < PI)
			&& (data->map.map[ray->map_h.y - 1][ray->map_h.x] == m_door))
		|| (ray->map_h.y + 1 < data->map.map_y_len
			&& (ray->angle > PI)
			&& (data->map.map[ray->map_h.y + 1][ray->map_h.x] == m_door)))
		wall->texture = &data->textures[ti_door_side];
	else if (ray->angle > 0 && ray->angle < PI)
		wall->texture = &data->textures[ti_north];
	else
		wall->texture = &data->textures[ti_south];
	wall->ray = ray->horiznal;
	wall->dist = ray->horiznal_dist * cos(wall->normal_angle);
}

static void	set_numbers(t_data *data, t_ray *ray, t_wall *wall)
{
	const double	line_len = (double)WIDTH / RAY_NUM;
	static double	last_x = 0;

	if (ray->index == 0)
		last_x = 0;
	wall->height = HEIGHT / wall->dist;
	wall->ratio = (double)wall->texture->height / wall->height;
	wall->st.x = last_x;
	wall->st.y = data->wall_st - (wall->height / 2);
	if (wall->st.y < 0)
	{
		wall->y_off = -wall->st.y;
		wall->st.y = 0;
	}
	wall->ed.x = last_x + line_len;
	last_x += line_len;
	wall->ed.y = data->wall_st + (wall->height / 2);
	if (wall->ed.y > HEIGHT)
		wall->ed.y = HEIGHT;
}

void	set_wall(t_data *data, t_ray *ray, t_wall *wall)
{
	ft_memset(wall, 0, sizeof(t_wall));
	wall->normal_angle = data->player_angle - ray->angle;
	if (wall->normal_angle < 0)
		wall->normal_angle += 2 * PI;
	if (ray->horiznal_dist < ray->vertical_dist)
		horiznal_texture(data, ray, wall);
	else
		vertical_texture(data, ray, wall);
	set_numbers(data, ray, wall);
}
