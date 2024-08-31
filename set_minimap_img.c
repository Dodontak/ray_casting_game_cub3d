/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minimap_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:53:52 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 15:25:17 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static const int	g_minimap_frame_r = MINIMAP_WALL_SIZE * MINIMAP_VIEW_RANGE;

void	set_minimap_img(t_data *data)
{
	const int	size = (g_minimap_frame_r + 3) * 2 + 1;
	t_img		*img;
	t_img		*wall_img;
	t_ipos		center;

	center.x = g_minimap_frame_r + 3;
	center.y = g_minimap_frame_r + 3;
	img = &data->minimap_background_img;
	wall_img = &data->minimap_wall_img;
	img->img = mlx_new_image(data->mlx, size, size);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
	wall_img->img = mlx_new_image(data->mlx, size, size);
	wall_img->addr = mlx_get_data_addr(wall_img->img, &wall_img->bits_per_pixel,
			&wall_img->line_len, &wall_img->endian);
	fill_clear_pixel(img, size, size);
	draw_circle(&data->minimap_background_img, &center, g_minimap_frame_r + 3,
		DARK_VIOLET);
	draw_circle(&data->minimap_background_img,
		&center, g_minimap_frame_r, WHITE);
	draw_circle(&data->minimap_background_img, &center, 3, RED);
}
