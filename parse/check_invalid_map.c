/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:55:23 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 13:20:38 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_invalid_char_in_map(char **map);
static bool	is_not_one_player(char **map);
static bool	is_invalid_door(char **map);
static int	count_enemy(char **map);

void	check_invalid_map(char **map)
{
	if (is_invalid_char_in_map(map) == true)
		print_err_and_exit(0, 1, "imvalid char in map");
	if (is_not_one_player(map) == true)
		print_err_and_exit(0, 1, "imvalid map player is not one");
	if (is_invalid_door(map) == true)
		print_err_and_exit(0, 1, "invalid map door error");
	if (count_enemy(map) > 1)
		print_err_and_exit(0, 1, "invalid map too many enemy");
}

static int	count_enemy(char **map)
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
			if (map[y][x] == 'M')
				count++;
	}
	return (count);
}

static bool	is_invalid_door(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'D')
			{
				if (y - 1 < 0 || x - 1 < 0 || map[y + 1] == 0
					|| map[y][x + 1] == 0)
					return (true);
				else if ((map[y][x - 1] != '1' || map[y][x + 1] != '1')
						&& (map[y - 1][x] != '1' || map[y + 1][x] != '1'))
					return (true);
			}
		}
	}
	return (false);
}

static bool	is_invalid_char_in_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != ' ' && map[y][x] != '0' && map[y][x] != '1'
					&& map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'W'
					&& map[y][x] != 'E' && map[y][x] != 'D' && map[y][x] != 'M'
					&& map[y][x] != 'K' && map[y][x] != 'X')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

static bool	is_not_one_player(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
					|| map[y][x] == 'E' || map[y][x] == 'W')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (true);
	return (false);
}
