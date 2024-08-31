/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:37:18 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/21 12:42:02 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_circle(t_img *img, t_ipos *center, int r, const unsigned int color)
{
	const t_ipos	start = {center->x - r, center->y - r};
	const t_ipos	end = {center->x + r, center->y + r};
	t_ipos			point;

	point.y = start.y - 1;
	while (++point.y <= end.y)
	{
		point.x = start.x - 1;
		if (point.y < 0)
			continue ;
		while (++point.x <= end.x)
		{
			if (point.x < 0)
				continue ;
			if (is_in_circle(&point, center->x, center->y, r) == true)
				pixel_put_in_map(img, point, color);
		}
	}
}
