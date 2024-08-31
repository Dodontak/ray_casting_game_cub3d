/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:59:06 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/23 13:00:24 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static void	draw_background(t_data *data, const t_ipos *st, const t_ipos *ed)
{
	t_ipos	left_bot;
	t_ipos	right_top;

	left_bot.x = st->x;
	left_bot.y = 0;
	right_top.x = ed->x;
	right_top.y = st->y;
	draw_square(&data->img, &left_bot, &right_top, data->map.floor_color);
	left_bot.y = ed->y;
	right_top.y = HEIGHT;
	draw_square(&data->img, &left_bot, &right_top, data->map.ceiling_color);
}

static void	draw_horizantal_wall(t_data *data, t_wall *wall)
{
	t_ipos	cur;

	cur.y = wall->st.y;
	wall->texture_pos.x
		= (wall->x_off + wall->ray.x - (int)wall->ray.x) * wall->texture->width;
	wall->tex_y = wall->ratio * wall->y_off;
	while (cur.y < wall->ed.y)
	{
		wall->texture_pos.y = (int)wall->tex_y;
		wall->color = get_texture_color(wall->texture, wall->texture_pos);
		cur.x = wall->st.x;
		while (cur.x < wall->ed.x)
		{
			pixel_put(&data->img, cur, wall->color);
			cur.x++;
		}
		wall->tex_y += wall->ratio;
		cur.y++;
	}
}

static void	draw_vertical_wall(t_data *data, t_wall *wall)
{
	t_ipos	cur;

	cur.y = wall->st.y;
	wall->texture_pos.x
		= (wall->x_off + wall->ray.y - (int)wall->ray.y) * wall->texture->width;
	wall->tex_y = wall->ratio * wall->y_off;
	while (cur.y < wall->ed.y)
	{
		wall->texture_pos.y = (int)wall->tex_y;
		wall->color = get_texture_color(wall->texture, wall->texture_pos);
		cur.x = wall->st.x;
		while (cur.x < wall->ed.x)
		{
			pixel_put(&data->img, cur, wall->color);
			cur.x++;
		}
		wall->tex_y += wall->ratio;
		cur.y++;
	}
}

void	draw_wall(t_data *data, t_ray *ray)
{
	t_wall			wall;

	set_wall(data, ray, &wall);
	if (ray->horiznal_dist < ray->vertical_dist)
		draw_horizantal_wall(data, &wall);
	else
		draw_vertical_wall(data, &wall);
	draw_background(data, &wall.st, &wall.ed);
}
