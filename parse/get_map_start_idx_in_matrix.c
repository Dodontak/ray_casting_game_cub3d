/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_start_idx_in_matrix.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:56:59 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:56:59 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_map_start_idx_in_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][0] == 0)
			;
		else if (matrix[i][0][0] == '0' || matrix[i][0][0] == '1')
			return (i);
		i++;
	}
	return (i);
}
