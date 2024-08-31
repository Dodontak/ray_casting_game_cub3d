/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:34:49 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 13:20:16 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_sprites1(t_data *data, t_img *escape, t_img *key_img,
				t_img *enemy);
static void	set_sprites2(t_data *data, t_img *enemy);
static void	set_sprites3(t_data *data, t_ipos pos, t_sprite *sprite,
				char **map);
static int	count_sprites_in_map(char **map);

void	set_sprites(t_data *data)
{
	char	**map;
	t_ipos	pos;

	map = data->map.map;
	data->enemy = safe_malloc(sizeof(t_img) * 8);
	data->sprite_num = count_sprites_in_map(map);
	data->sprite = safe_malloc(sizeof(t_sprite) * data->sprite_num);
	set_sprites1(data, &data->escape, &data->key_img, data->enemy);
	set_sprites2(data, data->enemy);
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == s_enemy || map[pos.y][pos.x] == s_key ||
					map[pos.y][pos.x] == 'O' || map[pos.y][pos.x] == s_escape)
				set_sprites3(data, pos, data->sprite, map);
			if (map[pos.y][pos.x] == s_key)
				data->key_left++;
		}
	}
}

static int	count_sprites_in_map(char **map)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == s_enemy || map[y][x] == s_key ||
					map[y][x] == 'O' || map[y][x] == s_escape)
				count++;
		}
	}
	return (count);
}

static void	set_sprites1(t_data *data, t_img *escape, t_img *key_img,
				t_img *enemy)
{
	escape->img = mlx_xpm_file_to_image(data->mlx, "assets/ladder.xpm",
			&escape->width, &escape->height);
	escape->addr = mlx_get_data_addr(escape->img, &escape->bits_per_pixel,
			&escape->line_len, &escape->endian);
	key_img->img = mlx_xpm_file_to_image(data->mlx, "assets/key.xpm",
			&key_img->width, &key_img->height);
	key_img->addr = mlx_get_data_addr(key_img->img, &key_img->bits_per_pixel,
			&key_img->line_len, &key_img->endian);
	enemy[0].img = mlx_xpm_file_to_image(data->mlx, "assets/Green1.xpm",
			&enemy[0].width, &enemy[0].height);
	enemy[0].addr = mlx_get_data_addr(enemy[0].img, &enemy[0].bits_per_pixel,
			&enemy[0].line_len, &enemy[0].endian);
	enemy[1].img = mlx_xpm_file_to_image(data->mlx, "assets/Green2.xpm",
			&enemy[1].width, &enemy[1].height);
	enemy[1].addr = mlx_get_data_addr(enemy[1].img, &enemy[1].bits_per_pixel,
			&enemy[1].line_len, &enemy[1].endian);
	enemy[2].img = mlx_xpm_file_to_image(data->mlx, "assets/Green3.xpm",
			&enemy[2].width, &enemy[2].height);
	enemy[2].addr = mlx_get_data_addr(enemy[2].img, &enemy[2].bits_per_pixel,
			&enemy[2].line_len, &enemy[2].endian);
	enemy[3].img = mlx_xpm_file_to_image(data->mlx, "assets/Green4.xpm",
			&enemy[3].width, &enemy[3].height);
	enemy[3].addr = mlx_get_data_addr(enemy[3].img, &enemy[3].bits_per_pixel,
			&enemy[3].line_len, &enemy[3].endian);
}

static void	set_sprites2(t_data *data, t_img *enemy)
{
	enemy[4].img = mlx_xpm_file_to_image(data->mlx, "assets/Green5.xpm",
			&enemy[4].width, &enemy[4].height);
	enemy[4].addr = mlx_get_data_addr(enemy[4].img, &enemy[4].bits_per_pixel,
			&enemy[4].line_len, &enemy[4].endian);
	enemy[5].img = mlx_xpm_file_to_image(data->mlx, "assets/Green6.xpm",
			&enemy[5].width, &enemy[5].height);
	enemy[5].addr = mlx_get_data_addr(enemy[5].img, &enemy[5].bits_per_pixel,
			&enemy[5].line_len, &enemy[5].endian);
	enemy[6].img = mlx_xpm_file_to_image(data->mlx, "assets/Green7.xpm",
			&enemy[6].width, &enemy[6].height);
	enemy[6].addr = mlx_get_data_addr(enemy[6].img, &enemy[6].bits_per_pixel,
			&enemy[6].line_len, &enemy[6].endian);
	enemy[7].img = mlx_xpm_file_to_image(data->mlx, "assets/Green8.xpm",
			&enemy[7].width, &enemy[7].height);
	enemy[7].addr = mlx_get_data_addr(enemy[7].img, &enemy[7].bits_per_pixel,
			&enemy[7].line_len, &enemy[7].endian);
}

static void	set_sprites3(t_data *data, t_ipos pos, t_sprite *sprite, char **map)
{
	static int	count = 0;

	sprite[count].pos.x = (double)pos.x + 0.5;
	sprite[count].pos.y = (double)pos.y + 0.5;
	sprite[count].type = map[pos.y][pos.x];
	sprite[count].num_of_texture = 1;
	if (sprite[count].type == s_enemy)
	{
		data->enemy_pos = sprite[count].pos;
		sprite[count].texture = data->enemy;
	}
	if (sprite[count].type == s_key)
		sprite[count].texture = &data->key_img;
	if (sprite[count].type == s_escape)
		sprite[count].texture = &data->escape;
	count++;
}
