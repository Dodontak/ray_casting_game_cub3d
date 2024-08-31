/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:05:40 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:09:41 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*minman(void);
static char		*zeroman(void);
static char		*exeption(int n);
static int		howlong(int n);

char	*ft_itoa(int n)
{
	char	*out;
	int		outlen;
	int		i;
	int		tmp;

	if (n == -2147483648 || n == 0)
		return (exeption(n));
	outlen = howlong(n);
	out = (char *)malloc(sizeof(char) * (outlen + 1));
	if (out == 0)
		return (0);
	i = outlen - 1;
	if (n < 0)
	{
		n *= -1;
		out[0] = '-';
	}
	while (n)
	{
		tmp = n % 10 + '0';
		out[i--] = tmp;
		n /= 10;
	}
	out[outlen] = '\0';
	return (out);
}

static int	howlong(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*exeption(int n)
{
	if (n == -2147483648)
		return (minman());
	else
		return (zeroman());
}

static char	*minman(void)
{
	char	*out;

	out = (char *)malloc(sizeof(char) * (11 + 1));
	if (out == 0)
		return (0);
	out[0] = '-';
	out[1] = '2';
	out[2] = '1';
	out[3] = '4';
	out[4] = '7';
	out[5] = '4';
	out[6] = '8';
	out[7] = '3';
	out[8] = '6';
	out[9] = '4';
	out[10] = '8';
	out[11] = '\0';
	return (out);
}

static char	*zeroman(void)
{
	char	*out;

	out = (char *)malloc(sizeof(char) * (1 + 1));
	if (out == 0)
		return (0);
	out[0] = '0';
	out[1] = '\0';
	return (out);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n",ft_itoa(-2147483648));
	printf("%s\n",ft_itoa(2147483647));
	printf("%s\n",ft_itoa(0));
	printf("%s\n",ft_itoa(10));
	printf("%s\n",ft_itoa(-10));
	printf("%s\n",ft_itoa(1234));
	printf("%s\n",ft_itoa(-1234));
}
*/
