/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matrix_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:57:13 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:57:13 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_matrix_len(char ***matrix)
{
	int	count;

	count = 0;
	while (matrix[count])
		count++;
	return (count);
}
