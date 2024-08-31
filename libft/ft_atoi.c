/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:27:27 by byejeon           #+#    #+#             */
/*   Updated: 2023/03/15 19:29:14 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(char c);
static int	is_digit(char c);

int	ft_atoi(const char *str)
{
	int			sign;
	long long	sum;

	sign = 1;
	sum = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (is_digit(*str))
	{
		sum = sum * 10 + *str - '0';
		str++;
	}
	return (sum * sign);
}

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n",ft_atoi("   \n123"));
}
*/
