/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:58:22 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 15:29:03 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static const int	g_minimap_frame_r = MINIMAP_WALL_SIZE * MINIMAP_VIEW_RANGE;

static void	draw_line2(
	t_img *img, t_ipos pos, const t_ipos *ed, const int color)
{
	t_ipos	d_pos;
	int		bresenham;

	d_pos.x = (int)fabs((float)ed->x - pos.x);
	d_pos.y = (int)fabs((float)ed->y - pos.y);
	bresenham = 2 * d_pos.x - d_pos.y;
	while (pos.y != ed->y && pos.y >= 0)
	{
		pixel_put_in_map(img, pos, color);
		if (bresenham < 0)
			bresenham += 2 * d_pos.x;
		else
		{
			bresenham += 2 * (d_pos.x - d_pos.y);
			if (pos.x < ed->x)
				pos.x++;
			else
				pos.x--;
		}
		if (pos.y < ed->y)
			pos.y++;
		else
			pos.y--;
	}
}

static void	draw_line1(
	t_img *img, t_ipos pos, const t_ipos *ed, const int color)
{
	t_ipos	d_pos;
	int		bresenham;

	d_pos.x = (int)fabs((float)ed->x - pos.x);
	d_pos.y = (int)fabs((float)ed->y - pos.y);
	bresenham = 2 * d_pos.y - d_pos.x;
	while (pos.x != ed->x && pos.x >= 0)
	{
		pixel_put_in_map(img, pos, color);
		if (bresenham < 0)
			bresenham += 2 * d_pos.y;
		else
		{
			bresenham += 2 * (d_pos.y - d_pos.x);
			if (pos.y < ed->y)
				pos.y++;
			else
				pos.y--;
		}
		if (pos.x < ed->x)
			pos.x++;
		else
			pos.x--;
	}
}

static void	draw_line_in_map(
	t_img *img, const t_ipos *st, const t_ipos *ed, const unsigned int color)
{
	t_ipos	d_pos;

	d_pos.x = (int)fabs((float)ed->x - st->x);
	d_pos.y = (int)fabs((float)ed->y - st->y);
	if (d_pos.y <= d_pos.x)
		draw_line1(img, *st, ed, color);
	else
		draw_line2(img, *st, ed, color);
}

static void	draw_minimap_ray(t_data *data, t_ray *ray, int color)
{
	const t_ipos	st = {g_minimap_frame_r + 3, g_minimap_frame_r + 3};
	t_ipos			ed;
	double			shortest_dist;

	if (ray->shortest_dist * MINIMAP_WALL_SIZE > g_minimap_frame_r)
		shortest_dist = (double)g_minimap_frame_r / MINIMAP_WALL_SIZE;
	else
		shortest_dist = ray->shortest_dist;
	ed.x = st.x + MINIMAP_WALL_SIZE * shortest_dist * cos(ray->angle);
	ed.y = st.y + MINIMAP_WALL_SIZE * shortest_dist * sin(ray->angle);
	if (ed.x < 0)
		ed.x = 0;
	if (ed.y >= HEIGHT)
		ed.y = HEIGHT - 1;
	draw_line_in_map(&data->minimap_wall_img, &st, &ed, color);
}

void	draw_rays(t_data *data)
{
	int		i;
	t_ray	*ray;

	i = 0;
	while (i < RAY_NUM)
	{
		ray = &data->ray[i];
		if (ray->vertical_dist < ray->horiznal_dist)
		{
			ray->hit = ray->vertical;
			ray->shortest_dist = ray->vertical_dist;
			draw_minimap_ray(data, ray, DARK_GREEN);
		}
		else
		{
			ray->hit = ray->horiznal;
			ray->shortest_dist = ray->horiznal_dist;
			draw_minimap_ray(data, ray, BRIGHT_GREEN);
		}
		i++;
	}
}
