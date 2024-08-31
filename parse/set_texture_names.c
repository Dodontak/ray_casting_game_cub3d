/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:58:31 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:59:13 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	set_a_texture_name(t_mapinfo *mapinfo, char **strs,
				const char *type, int idx);

void	set_texture_names(t_mapinfo *mapinfo)
{
	int	i;

	i = -1;
	while (++i < mapinfo->map_start_idx)
	{
		if (mapinfo->matrix[i][0] == 0)
			continue ;
		set_a_texture_name(mapinfo, mapinfo->matrix[i], "NO", NO);
		set_a_texture_name(mapinfo, mapinfo->matrix[i], "SO", SO);
		set_a_texture_name(mapinfo, mapinfo->matrix[i], "WE", WE);
		set_a_texture_name(mapinfo, mapinfo->matrix[i], "EA", EA);
		set_a_texture_name(mapinfo, mapinfo->matrix[i], "F", F);
		set_a_texture_name(mapinfo, mapinfo->matrix[i], "C", C);
	}
}

static void	set_a_texture_name(t_mapinfo *mapinfo, char **strs,
				const char *type, int idx)
{
	if (ft_strncmp(strs[0], type, ft_strlen(type) + 1) == 0)
	{
		mapinfo->texture[idx] = ft_strdup(strs[1]);
		if (mapinfo->texture[idx] == 0)
			print_err_and_exit(1, 1, "set_texture_names");
	}
}
