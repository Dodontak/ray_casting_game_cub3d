/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_base_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:57:33 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:57:34 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**make_base_map(t_mapinfo *mapinfo)
{
	char	**map;
	int		raw_i;
	int		map_idx;

	raw_i = mapinfo->map_start_idx;
	map = malloc(sizeof(char *) * (mapinfo->map_y + 1));
	if (map == 0)
		print_err_and_exit(1, 1, "parsing make_map");
	map_idx = 0;
	while (mapinfo->rawdata[raw_i])
	{
		map[map_idx] = malloc(sizeof(char) * (mapinfo->map_x + 1));
		if (map[map_idx] == 0)
			print_err_and_exit(1, 1, "parsing make_map");
		ft_memset(map[map_idx], 0, mapinfo->map_x + 1);
		ft_strlcpy(map[map_idx], mapinfo->rawdata[raw_i], mapinfo->map_x + 1);
		map_idx++;
		raw_i++;
	}
	map[map_idx] = 0;
	return (map);
}
