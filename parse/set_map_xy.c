/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_xy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:58:03 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:58:04 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	set_map_xy(t_mapinfo *mapinfo)
{
	int	i;

	i = mapinfo->map_start_idx;
	while (mapinfo->rawdata[i])
	{
		if (mapinfo->map_x < ft_strlen(mapinfo->rawdata[i]))
			mapinfo->map_x = ft_strlen(mapinfo->rawdata[i]);
		i++;
	}
	i = mapinfo->map_start_idx;
	while (mapinfo->rawdata[i++])
		mapinfo->map_y++;
}
