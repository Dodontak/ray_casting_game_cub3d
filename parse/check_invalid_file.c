/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:20:52 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/23 14:55:08 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	count_not_map_line(char ***matrix);
static bool	is_six_elements_error(char ***matrix, int map_start_idx);
static bool	is_right_element(char **strs, const char *type);
static bool	is_empty_line_after_map_start_idx(char ***matrix, int start_idx);

void	check_invalid_file(char ***matrix, int map_start_idx)
{
	if (map_start_idx == get_matrix_len(matrix))
		print_err_and_exit(0, 1, "there is no map");
	if (is_six_elements_error(matrix, map_start_idx) == true)
		print_err_and_exit(0, 1, "invalid file contents");
	if (is_empty_line_after_map_start_idx(matrix, map_start_idx))
		print_err_and_exit(0, 1, "empty line in map");
}

static bool	is_empty_line_after_map_start_idx(char ***matrix, int start_idx)
{
	int	i;

	i = start_idx;
	while (matrix[i])
	{
		if (matrix[i][0] == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool	is_six_elements_error(char ***matrix, int map_start_idx)
{
	int	i;
	int	arr[6];

	i = -1;
	ft_memset(arr, 0, sizeof(int) * 6);
	while (++i < map_start_idx)
	{
		if (matrix[i][0] != 0 && is_right_element(matrix[i], "NO"))
			arr[NO]++;
		else if (matrix[i][0] != 0 && is_right_element(matrix[i], "SO"))
			arr[SO]++;
		else if (matrix[i][0] != 0 && is_right_element(matrix[i], "WE"))
			arr[WE]++;
		else if (matrix[i][0] != 0 && is_right_element(matrix[i], "EA"))
			arr[EA]++;
		else if (matrix[i][0] != 0 && is_right_element(matrix[i], "F"))
			arr[F]++;
		else if (matrix[i][0] != 0 && is_right_element(matrix[i], "C"))
			arr[C]++;
	}
	if (count_not_map_line(matrix) != 6 || arr[NO] != 1 || arr[SO] != 1
		|| arr[WE] != 1 || arr[EA] != 1 || arr[F] != 1 || arr[C] != 1)
		return (true);
	return (false);
}

static bool	is_right_element(char **strs, const char *type)
{
	int	i;

	i = 0;
	if (ft_strncmp(strs[0], type, ft_strlen(type) + 1) != 0)
		return (false);
	if (get_strs_len(strs) != 2)
		return (false);
	return (true);
}

static int	count_not_map_line(char ***matrix)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		if (matrix[i][0] == 0)
			;
		else if (!(matrix[i][0][0] == '0' || matrix[i][0][0] == '1'))
			count++;
		i++;
	}
	return (count);
}
