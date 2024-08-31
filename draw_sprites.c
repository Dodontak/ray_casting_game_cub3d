/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:37:24 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 15:04:07 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

static double	get_relative_angle(t_fpos *player_pos, t_sprite *sprite,
					double pa);
static void		draw_sprite_line(t_img *img, t_img *texture, t_sprite_arg arg);
static void		init_sprite_info(t_data *data, t_sprite *sprite,
					t_sprite_arg *arg, int tex_no);
static int		get_tex_no(t_data *data, t_sprite *sprite);

void	draw_sprite(t_data *data, t_sprite *sprite)
{
	t_sprite_arg	arg;

	if (sprite->type == 'R')
		return ;
	arg.tex_no = get_tex_no(data, sprite);
	sprite->dist = get_euclidian_dist(&data->player_pos, &sprite->pos);
	if (sprite->dist <= 0.0625)
		return ;
	init_sprite_info(data, sprite, &arg, arg.tex_no);
	if (sprite->type == 'M' && sprite->dist <= 0.5)
		game_over(data, false);
	if (sprite->angle < -PI / 4 || sprite->angle > PI / 4)
		return ;
	while (++arg.img_d.x < arg.modified_size.x)
	{
		arg.draw_point.x = arg.start.x + arg.img_d.x;
		if (arg.draw_point.x >= WIDTH)
			return ;
		if (arg.draw_point.x < 0 || data->ray[arg.draw_point.x * RAY_NUM
				/ WIDTH].shortest_dist < sprite->dist)
			continue ;
		draw_sprite_line(&data->img, &sprite->texture[arg.tex_no], arg);
	}
}

static void	init_sprite_info(t_data *data, t_sprite *sprite, t_sprite_arg *arg,
		int tex_no)
{
	if (sprite->type == 'K' && sprite->dist <= 1)
	{
		sprite->type = 'R';
		data->key_left--;
	}
	if (sprite->type == s_escape && data->key_left == 0 && sprite->dist <= 0.5)
		game_over(data, true);
	sprite->angle = get_relative_angle(&data->player_pos, sprite,
			data->player_angle);
	arg->center.x = WIDTH * (sprite->angle + PI / 6) / (PI / 3) - 1;
	arg->center.y = data->wall_st;
	arg->tex_size.x = sprite->texture[tex_no].width;
	arg->tex_size.y = sprite->texture[tex_no].height;
	arg->modified_size.x = (int)(arg->tex_size.x / sprite->dist);
	arg->modified_size.y = (int)(arg->tex_size.y / sprite->dist);
	arg->start.x = (int)(arg->center.x) - arg->modified_size.x / 2;
	arg->start.y = (int)(arg->center.y) - arg->modified_size.y / 2;
	arg->img_d.x = 0;
	arg->tex_dy = (double)sprite->texture[tex_no].height
		/ (double)arg->modified_size.y;
}

static double	get_relative_angle(t_fpos *player_pos, t_sprite *sprite,
		double pa)
{
	double	abs_angle;
	double	angle;

	abs_angle = acos((sprite->pos.x - player_pos->x) / sprite->dist);
	if (player_pos->y > sprite->pos.y)
		abs_angle = 2 * PI - abs_angle;
	if (pa < abs_angle)
		angle = (2 * PI + pa) - abs_angle;
	else
		angle = pa - abs_angle;
	if (angle > 5 * PI / 6)
		angle = -(2 * PI - angle);
	return (angle);
}

static void	draw_sprite_line(t_img *img, t_img *texture, t_sprite_arg arg)
{
	t_ipos			get_color;
	unsigned int	color;

	get_color.x = (texture->width - 1) * arg.img_d.x
		/ (arg.modified_size.x - 1);
	arg.img_d.y = -1;
	while (++arg.img_d.y < arg.modified_size.y)
	{
		if (arg.start.y + arg.img_d.y < 0)
			continue ;
		if (arg.start.y + arg.img_d.y >= HEIGHT)
			return ;
		get_color.y = (int)(arg.tex_dy * arg.img_d.y) + 1;
		color = get_texture_color(texture, get_color);
		if (color == CLEAR)
			continue ;
		arg.draw_point.y = arg.start.y + arg.img_d.y;
		arg.draw_point.x = arg.start.x + arg.img_d.x;
		pixel_put(img, arg.draw_point, color);
	}
}

static int	get_tex_no(t_data *data, t_sprite *sprite)
{
	int	tex_no;

	tex_no = 0;
	if (sprite->type == 'M')
	{
		sprite->pos = data->enemy_pos;
		if (data->frame % 30 < 4)
			tex_no = 0;
		else if (data->frame % 30 < 8)
			tex_no = 1;
		else if (data->frame % 30 < 12)
			tex_no = 2;
		else if (data->frame % 30 < 16)
			tex_no = 3;
		else if (data->frame % 30 < 20)
			tex_no = 4;
		else if (data->frame % 30 < 24)
			tex_no = 5;
		else if (data->frame % 30 < 18)
			tex_no = 6;
		else
			tex_no = 7;
	}
	return (tex_no);
}
