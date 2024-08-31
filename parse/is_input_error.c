/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:22:11 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/09 13:58:53 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool		is_invalid_extension(char **av);

void	check_input_error(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		print_err_and_exit(0, 1, "argument is not 2");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		print_err_and_exit(1, 1, av[1]);
	close(fd);
	if (is_invalid_extension(av) == true)
		print_err_and_exit(1, 1, "invalid extension");
}

static bool	is_invalid_extension(char **av)
{
	size_t	len;

	len = ft_strlen(av[1]);
	if (len < 4)
		return (true);
	if (av[1][len - 4] != '.' || av[1][len - 3] != 'c' ||
			av[1][len - 2] != 'u' || av[1][len - 1] != 'b')
		return (true);
	return (false);
}
