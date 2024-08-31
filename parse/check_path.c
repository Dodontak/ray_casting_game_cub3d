/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:56:15 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 14:21:36 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

static char	**copy_map(char **map, t_mapinfo *mapinfo);
static void	paint_x(char **map, int posx, int posy, t_mapinfo *mapinfo);

void	check_path(char **map, t_mapinfo *mapinfo)
{
	char	**copied_map;

	copied_map = copy_map(map, mapinfo);
	paint_x(copied_map, mapinfo->pos_x, mapinfo->pos_y, mapinfo);
	free_strs(copied_map);
}

static void	paint_x(char **map, int posx, int posy, t_mapinfo *mapinfo)
{
	int	mv;

	if (posx < 0 || posy < 0 || (size_t)posx >= mapinfo->map_x
		|| (size_t)posy >= mapinfo->map_y || map[posy][posx] == ' '
		|| map[posy][posx] == '\0')
		print_err_and_exit(0, 1, "invalid map");
	if (map[posy][posx] == '1' || map[posy][posx] == '*')
		return ;
	map[posy][posx] = '*';
	mv = DOWN;
	while (mv < 4)
	{
		if (mv == DOWN)
			paint_x(map, posx, posy + 1, mapinfo);
		else if (mv == UP)
			paint_x(map, posx, posy - 1, mapinfo);
		else if (mv == RIGHT)
			paint_x(map, posx + 1, posy, mapinfo);
		else
			paint_x(map, posx - 1, posy, mapinfo);
		mv++;
	}
}

static char	**copy_map(char **map, t_mapinfo *mapinfo)
{
	char	**copied_map;
	int		i;

	i = 0;
	copied_map = malloc(sizeof(char *) * (mapinfo->map_y + 1));
	if (copied_map == 0)
		print_err_and_exit(1, 1, "parsing copy_map");
	while (map[i])
	{
		copied_map[i] = malloc(sizeof(char) * (mapinfo->map_x + 1));
		if (copied_map[i] == 0)
			print_err_and_exit(1, 1, "parsing copy_map");
		ft_strlcpy(copied_map[i], map[i], mapinfo->map_x + 1);
		i++;
	}
	copied_map[i] = 0;
	return (copied_map);
}
