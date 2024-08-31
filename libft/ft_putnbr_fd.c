/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:17:29 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:21:24 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	exception(int n, int fd);
static void	good_func(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648 || n == 0)
	{
		exception(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	good_func(n, fd);
	return ;
}

static void	good_func(int n, int fd)
{
	char	out;

	if (n <= 0)
		return ;
	out = n % 10 + '0';
	good_func(n / 10, fd);
	write(fd, &out, 1);
}

static void	exception(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	return ;
}
/*
#include <fcntl.h>
int	main()
{
	int	fd;

	fd = open("Atest", O_RDWR | O_APPEND);
	ft_putnbr_fd(99999, fd);
}
*/
