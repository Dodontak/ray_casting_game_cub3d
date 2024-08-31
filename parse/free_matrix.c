/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:54:18 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/09 15:55:52 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free_strs(matrix[i]);
		i++;
	}
	free(matrix);
}
