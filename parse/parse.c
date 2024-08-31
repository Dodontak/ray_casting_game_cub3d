/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:22:19 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 14:04:09 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	parse_free_things(t_mapinfo *mapinfo);

void	parse(int ac, char **av, t_map *map)
{
	t_mapinfo	mapinfo;

	check_input_error(ac, av);
	ft_memset(&mapinfo, 0, sizeof(t_mapinfo));
	mapinfo.rawdata = make_rawdata(av);
	mapinfo.matrix = make_matrix_from_rawdata(mapinfo.rawdata);
	mapinfo.map_start_idx = get_map_start_idx_in_matrix(mapinfo.matrix);
	check_invalid_file(mapinfo.matrix, mapinfo.map_start_idx);
	set_texture_names(&mapinfo);
	check_and_set_color(&mapinfo);
	set_map_xy(&mapinfo);
	mapinfo.map = make_base_map(&mapinfo);
	check_invalid_map(mapinfo.map);
	set_pos_xy(mapinfo.map, &mapinfo);
	check_path(mapinfo.map, &mapinfo);
	set_map(map, &mapinfo);
	check_invalid_textures(&mapinfo);
	parse_free_things(&mapinfo);
}

static void	parse_free_things(t_mapinfo *mapinfo)
{
	free_strs(mapinfo->rawdata);
	free_matrix(mapinfo->matrix);
	free(mapinfo->texture[C]);
	free(mapinfo->texture[F]);
}
