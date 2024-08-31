/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_in_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:41:19 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 15:12:36 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static const int	g_minimap_frame_r = MINIMAP_WALL_SIZE * MINIMAP_VIEW_RANGE;

void	pixel_put_in_map(t_img *img, t_ipos pos, const unsigned int color)
{
	char	*dst;

	pos.y = (g_minimap_frame_r + 3) * 2 - pos.y;
	if (pos.x < 0 || pos.x >= (g_minimap_frame_r + 3) * 2 + 1)
		return ;
	if (pos.y < 0 || pos.y >= (g_minimap_frame_r + 3) * 2 + 1)
		return ;
	dst = img->addr
		+ (pos.y * img->line_len + pos.x * img->bits_per_pixel / PER_BYTE);
	*(unsigned int *)dst = color;
}
