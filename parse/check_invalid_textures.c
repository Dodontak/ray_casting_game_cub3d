/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:03:47 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 14:13:24 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	check_invalid_wall_texture(t_mapinfo *mapinfo);
static void	check_invalid_sprite_textures1(void);
static void	check_invalid_sprite_textures2(void);
static void	check_invalid_sprite_textures3(void);

void	check_invalid_textures(t_mapinfo *mapinfo)
{
	check_invalid_wall_texture(mapinfo);
	check_invalid_sprite_textures1();
	check_invalid_sprite_textures2();
	check_invalid_sprite_textures3();
}

static void	check_invalid_wall_texture(t_mapinfo *mapinfo)
{
	int	i;
	int	fd;

	i = 2;
	while (i < 6)
	{
		fd = open(mapinfo->texture[i], O_RDONLY);
		if (fd < 0)
			print_err_and_exit(1, 1, mapinfo->texture[i]);
		close(fd);
		i++;
	}
}

static void	check_invalid_sprite_textures1(void)
{
	int	fd;

	fd = open(DOOR_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, DOOR_TEXTURE);
	close(fd);
	fd = open(DOOR_SIDE_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, DOOR_SIDE_TEXTURE);
	close(fd);
	fd = open(GREEN1_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN1_TEXTURE);
	close(fd);
	fd = open(GREEN2_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN2_TEXTURE);
	close(fd);
	fd = open(GREEN3_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN3_TEXTURE);
	close(fd);
}

static void	check_invalid_sprite_textures2(void)
{
	int	fd;

	fd = open(GREEN4_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN4_TEXTURE);
	close(fd);
	fd = open(GREEN5_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN5_TEXTURE);
	close(fd);
	fd = open(GREEN6_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN6_TEXTURE);
	close(fd);
	fd = open(GREEN7_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN7_TEXTURE);
	close(fd);
	fd = open(GREEN8_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, GREEN8_TEXTURE);
	close(fd);
}

static void	check_invalid_sprite_textures3(void)
{
	int	fd;

	fd = open(KEY_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, KEY_TEXTURE);
	close(fd);
	fd = open(LADDER_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, LADDER_TEXTURE);
	close(fd);
	fd = open(YOU_DIE_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, YOU_DIE_TEXTURE);
	close(fd);
	fd = open(WIN_TEXTURE, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(1, 1, WIN_TEXTURE);
	close(fd);
}
