/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:30:32 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/18 17:30:11 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parse/parse.h"

#include <math.h>

static void	shoot_horizontal_ray(t_data *data, t_ray *ray)
{
	int	depth;

	depth = 0;
	while (depth < data->map.map_y_len)
	{
		ray->map_h.x = (int)ray->horiznal.x;
		ray->map_h.y = (int)ray->horiznal.y;
		if ((ray->map_h.x >= 0 && ray->map_h.x < data->map.map_x_len)
			&& (ray->map_h.y >= 0 && ray->map_h.y < data->map.map_y_len))
			check_horizontal_ray(data, ray);
		if (ray->horiznal_dist != MAX_DISTANCE)
			return ;
		ray->horiznal.x += ray->dh.x;
		ray->horiznal.y += ray->dh.y;
		depth++;
	}
}

static void	make_horizontal_ray(t_data *data, t_ray *ray)
{
	ray->horiznal_dist = MAX_DISTANCE;
	if (ray->angle == 0 || ray->angle == PI)
		return ;
	ray->ratio = -1 / tan(ray->angle);
	if (ray->angle < PI)
	{
		ray->horiznal.y = (int)(data->player_pos.y) + 1;
		ray->horiznal.x = data->player_pos.x
			+ (data->player_pos.y - ray->horiznal.y) * ray->ratio;
		ray->dh.y = 1;
		ray->dh.x = -ray->dh.y * ray->ratio;
	}
	else if (ray->angle > PI)
	{
		ray->horiznal.y = (int)(data->player_pos.y) - 0.000001;
		ray->horiznal.x = data->player_pos.x
			+ (data->player_pos.y - ray->horiznal.y) * ray->ratio;
		ray->dh.y = -1;
		ray->dh.x = -ray->dh.y * ray->ratio;
	}
	shoot_horizontal_ray(data, ray);
}

static void	shoot_vertical_ray(t_data *data, t_ray *ray)
{
	int	depth;

	depth = 0;
	while (depth < data->map.map_x_len)
	{
		ray->map_v.x = (int)ray->vertical.x;
		ray->map_v.y = (int)ray->vertical.y;
		if ((ray->map_v.x >= 0 && ray->map_v.x < data->map.map_x_len)
			&& (ray->map_v.y >= 0 && ray->map_v.y < data->map.map_y_len))
			check_vertical_ray(data, ray);
		if (ray->vertical_dist != MAX_DISTANCE)
			return ;
		ray->vertical.x += ray->dv.x;
		ray->vertical.y += ray->dv.y;
		depth++;
	}
}

static void	make_vertical_ray(t_data *data, t_ray *ray)
{
	ray->vertical_dist = MAX_DISTANCE;
	ray->ratio = -tan(ray->angle);
	if (ray->angle == PI / 2 || ray->angle == 3 * PI / 2)
		return ;
	else if (ray->angle < PI / 2 || ray->angle > 3 * PI / 2)
	{
		ray->vertical.x = (int)data->player_pos.x + 1;
		ray->vertical.y = data->player_pos.y
			+ (data->player_pos.x - ray->vertical.x) * ray->ratio;
		ray->dv.x = 1;
		ray->dv.y = -ray->dv.x * ray->ratio;
	}
	else if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
	{
		ray->vertical.x = (int)data->player_pos.x - 0.000001;
		ray->vertical.y = data->player_pos.y
			+ (data->player_pos.x - ray->vertical.x) * ray->ratio;
		ray->dv.x = -1;
		ray->dv.y = -ray->dv.x * ray->ratio;
	}
	shoot_vertical_ray(data, ray);
}

void	ray_casting(t_data *data)
{
	int		i;

	i = 0;
	while (i < RAY_NUM)
	{
		data->ray[i].index = i;
		if (i == 0)
			data->ray[i].angle = data->player_angle + FOV / 2 * DEGREE;
		else
			data->ray[i].angle
				= data->ray[i - 1].angle - FOV / RAY_NUM * DEGREE;
		if (data->ray[0].angle >= 2 * PI)
			data->ray[0].angle -= 2 * PI;
		else if (data->ray[i].angle < 0)
			data->ray[i].angle += 2 * PI;
		make_horizontal_ray(data, &data->ray[i]);
		make_vertical_ray(data, &data->ray[i]);
		draw_wall(data, &data->ray[i]);
		i++;
	}
}
