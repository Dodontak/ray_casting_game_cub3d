/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:04:14 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 15:20:59 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static const int	g_minimap_frame_r = MINIMAP_WALL_SIZE * MINIMAP_VIEW_RANGE;

static int	corners_out_of_circle(t_ipos *start, int center_x,
		int center_y, int r)
{
	t_ipos	point;
	int		count;

	point.x = start->x;
	point.y = start->y;
	count = 0;
	if (is_in_circle(&point, center_x, center_y, r) == false)
		count++;
	point.x = start->x + MINIMAP_WALL_SIZE;
	point.y = start->y;
	if (is_in_circle(&point, center_x, center_y, r) == false)
		count++;
	point.x = start->x;
	point.y = start->y + MINIMAP_WALL_SIZE;
	if (is_in_circle(&point, center_x, center_y, r) == false)
		count++;
	point.x = start->x + MINIMAP_WALL_SIZE;
	point.y = start->y + MINIMAP_WALL_SIZE;
	if (is_in_circle(&point, center_x, center_y, r) == false)
		count++;
	return (count);
}

static void	draw_wall_in_minimap_frame(t_img *img, t_ipos *start,
		const t_ipos *center, const unsigned int color)
{
	const t_ipos	end = {start->x + MINIMAP_WALL_SIZE - 1,
		start->y + MINIMAP_WALL_SIZE - 1};
	int				out_of_corner_count;
	t_ipos			point;

	point.y = start->y;
	out_of_corner_count = corners_out_of_circle(start, g_minimap_frame_r + 3,
			g_minimap_frame_r + 3, g_minimap_frame_r);
	if (out_of_corner_count == 4)
		return ;
	while (++point.y <= end.y)
	{
		point.x = start->x;
		if (point.y < 0 || point.y >= HEIGHT)
			continue ;
		while (++point.x <= end.x)
		{
			if (point.x < 0 || point.x >= WIDTH)
				continue ;
			if (out_of_corner_count == 0
				|| is_in_circle(&point, center->x, center->y, g_minimap_frame_r)
				== true)
				pixel_put_in_map(img, point, color);
		}
	}
}

static void	draw_minimap_wall(t_data *data, t_ipos *d, const t_ipos *center,
			const unsigned int color)
{
	const t_ipos	p_idx = {(int)data->player_pos.x, (int)data->player_pos.y};
	t_ipos			wall;

	wall.x = center->x
		- (data->player_pos.x - p_idx.x - d->x) * MINIMAP_WALL_SIZE;
	wall.y = center->y
		- (data->player_pos.y - p_idx.y - d->y) * MINIMAP_WALL_SIZE;
	draw_wall_in_minimap_frame(&data->minimap_wall_img, &wall,
		center, color);
}

void	draw_minimap(t_data *data)
{
	const t_ipos	p_idx = {(int)data->player_pos.x, (int)data->player_pos.y};
	const t_ipos	center = {g_minimap_frame_r + 3, g_minimap_frame_r + 3};
	t_ipos			d;

	d.y = -MINIMAP_VIEW_RANGE - 1;
	fill_clear_pixel(&data->minimap_wall_img, (g_minimap_frame_r + 3) * 2 + 1,
		(g_minimap_frame_r + 3) * 2 + 1);
	while (++d.y <= MINIMAP_VIEW_RANGE)
	{
		d.x = -MINIMAP_VIEW_RANGE - 1;
		if (p_idx.y + d.y < 0 || p_idx.y + d.y >= data->map.map_y_len)
			continue ;
		while (++d.x <= MINIMAP_VIEW_RANGE)
		{
			if (p_idx.x + d.x < 0 || p_idx.x + d.x > data->map.map_x_len - 1)
				continue ;
			else if (data->map.map[p_idx.y + d.y][p_idx.x + d.x] == '1')
				draw_minimap_wall(data, &d, &center, VIOLET);
			else if (data->map.map[p_idx.y + d.y][p_idx.x + d.x] == 'D' ||
						data->map.map[p_idx.y + d.y][p_idx.x + d.x] == 'd')
				draw_minimap_wall(data, &d, &center, GREEN);
		}
	}
}
