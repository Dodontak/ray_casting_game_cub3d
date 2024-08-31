/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:06:28 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/16 19:15:13 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	replace_space_with_0(char **map, size_t map_x, size_t map_y);
static void	reverse_map(t_map *map);

void	set_map(t_map *map, t_mapinfo *mapinfo)
{
	replace_space_with_0(mapinfo->map, mapinfo->map_x, mapinfo->map_y);
	map->map = mapinfo->map;
	map->map_x_len = (int)mapinfo->map_x;
	map->map_y_len = (int)mapinfo->map_y;
	map->player_x = mapinfo->pos_x;
	map->player_y = mapinfo->pos_y;
	map->texture_path[NO - 2] = mapinfo->texture[NO];
	map->texture_path[SO - 2] = mapinfo->texture[SO];
	map->texture_path[WE - 2] = mapinfo->texture[WE];
	map->texture_path[EA - 2] = mapinfo->texture[EA];
	map->floor_color = (mapinfo->color[F][0] << 16)
		+ (mapinfo->color[F][1] << 8) + mapinfo->color[F][2];
	map->ceiling_color = (mapinfo->color[C][0] << 16)
		+ (mapinfo->color[C][1] << 8) + mapinfo->color[C][2];
	reverse_map(map);
}

static void	reverse_map(t_map *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < map->map_y_len / 2)
	{
		tmp = map->map[i];
		map->map[i] = map->map[map->map_y_len - i - 1];
		map->map[map->map_y_len - i - 1] = tmp;
		i++;
	}
	map->player_y = map->map_y_len - map->player_y - 1;
}

static void	replace_space_with_0(char **map, size_t map_x, size_t map_y)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			if (map[y][x] == ' ' || map[y][x] == '\0')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
}
