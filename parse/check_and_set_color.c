/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:54:50 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:54:51 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	set_color(t_mapinfo *mapinfo, int idx);
static bool	is_wrong_color_numbers(char **strs);

void	check_and_set_color(t_mapinfo *mapinfo)
{
	if (set_color(mapinfo, C) == ERROR)
		print_err_and_exit(0, 1, "wrong ceiling floor color");
	if (set_color(mapinfo, F) == ERROR)
		print_err_and_exit(0, 1, "wrong ceiling floor color");
	if (mapinfo->color[C][0] == mapinfo->color[F][0]
			&& mapinfo->color[C][1] == mapinfo->color[F][1]
			&& mapinfo->color[C][2] == mapinfo->color[F][2])
		print_err_and_exit(0, 1, "ceiling floor color are same");
}

static bool	set_color(t_mapinfo *mapinfo, int idx)
{
	char	**strs;
	int		i;

	i = 0;
	if (count_char_in_str(mapinfo->texture[idx], ',') != 2)
		print_err_and_exit(0, 1, "wrong ceiling floor color");
	strs = ft_split(mapinfo->texture[idx], ',');
	if (strs == 0)
		print_err_and_exit(1, 1, "parsing set_color");
	if (get_strs_len(strs) != 3 || is_wrong_color_numbers(strs) == true)
		print_err_and_exit(0, 1, "wrong ceiling floor color");
	while (strs[i])
	{
		mapinfo->color[idx][i] = ft_atoi(strs[i]);
		if (mapinfo->color[idx][i] < 0 || mapinfo->color[idx][i] > 255)
			print_err_and_exit(0, 1, "wrong ceiling floor color");
		i++;
	}
	free_strs(strs);
	return (NORMAL);
}

static bool	is_wrong_color_numbers(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		if (ft_strlen(strs[i]) > 3)
			return (true);
		while (strs[i][j])
		{
			if (ft_isdigit(strs[i][j]) == false)
				return (true);
			j++;
		}
		if (ft_strlen(strs[i]) >= 2 && strs[i][0] == '0')
			return (true);
		i++;
	}
	return (false);
}
