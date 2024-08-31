/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix_from_rawdata.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:50:11 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/13 12:50:53 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	***make_matrix_from_rawdata(char **rawdata)
{
	char	***matrix;
	int		size;
	int		i;

	size = 0;
	while (rawdata[size])
		size++;
	matrix = malloc(sizeof(char **) * (size + 1));
	if (matrix == 0)
		print_err_and_exit(0, 1, "parsing is_invalid_file");
	i = -1;
	while (++i < size)
	{
		matrix[i] = ft_split(rawdata[i], ' ');
		if (matrix[i] == 0)
			print_err_and_exit(0, 1, "parsing is_invalid_file");
	}
	matrix[i] = 0;
	return (matrix);
}
