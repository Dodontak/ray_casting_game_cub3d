/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_clear_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:29:55 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/21 14:30:26 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_clear_pixel(t_img *img, int size_x, int size_y)
{
	t_ipos	pos;

	pos.y = -1;
	while (++pos.y < size_y)
	{
		pos.x = -1;
		while (++pos.x < size_x)
			pixel_put_in_map(img, pos, CLEAR);
	}
}
