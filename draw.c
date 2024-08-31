/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:56:24 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/21 20:32:41 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>
#include <stdlib.h>

static void	draw_line2(
	t_img *img, t_ipos pos, const t_ipos *ed, const int color)
{
	t_ipos	d_pos;
	int		bresenham;

	d_pos.x = (int)fabs((float)ed->x - pos.x);
	d_pos.y = (int)fabs((float)ed->y - pos.y);
	bresenham = 2 * d_pos.x - d_pos.y;
	while (pos.y != ed->y && pos.y >= 0 && pos.y <= HEIGHT)
	{
		pixel_put(img, pos, color);
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
	while (pos.x != ed->x && pos.x >= 0 && pos.x <= WIDTH)
	{
		pixel_put(img, pos, color);
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

void	draw_line(
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

void	draw_square(
	t_img *img, const t_ipos *st, const t_ipos *ed, const unsigned int color)
{
	t_ipos	pos;

	pos.y = st->y;
	while (pos.y < ed->y)
	{
		pos.x = st->x;
		while (pos.x < ed->x)
		{
			pixel_put(img, pos, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	pixel_put(t_img *img, t_ipos pos, const unsigned int color)
{
	char	*dst;

	if (pos.x < 0 || pos.x >= WIDTH)
		return ;
	if (pos.y < 0 || pos.y >= HEIGHT)
		return ;
	pos.y = HEIGHT - pos.y;
	dst = img->addr
		+ (pos.y * img->line_len + pos.x * img->bits_per_pixel / PER_BYTE);
	*(unsigned int *)dst = color;
}
