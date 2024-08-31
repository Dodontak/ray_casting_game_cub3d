/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:51:54 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:20:37 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}
/*
int	main()
{
	char str[] = "asdqwe";
	int	i = 0;

	ft_bzero(str, 2);
	while (str[i])
		printf("%c",str[i++]);
	printf("%c", str[3]);
	printf("\n");
}
*/
