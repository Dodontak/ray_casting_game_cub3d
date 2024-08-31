/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:55:23 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 14:56:44 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>
#include <stdlib.h>

void	angled_moving(t_fpos *pos, double range, double angle)
{
	pos->x += range * cos(angle);
	pos->y += range * sin(angle);
}

void	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		exit(EXIT_FAILURE);
	return (ret);
}

unsigned int	get_texture_color(t_img *img, t_ipos pos)
{
	char	*color;

	if ((pos.x < 0 || pos.x >= img->width)
		|| (pos.y < 0) || pos.y >= img->height)
		return (CLEAR);
	pos.y = img->height - pos.y;
	color = img->addr
		+ (pos.y * img->line_len + pos.x * img->bits_per_pixel / PER_BYTE);
	return (*((unsigned int *)color));
}

double	get_euclidian_dist(const t_fpos *st, const t_fpos *ed)
{
	const double	dist_x = ed->x - st->x;
	const double	dist_y = ed->y - st->y;

	return (sqrt(dist_y * dist_y + dist_x * dist_x));
}

void	init_img(t_img *img, t_data *data)
{
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_len, &img->endian);
}
