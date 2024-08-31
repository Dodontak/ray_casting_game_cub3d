/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:09:52 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 12:52:58 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cc = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == cc)
			return ((void *)ptr);
		ptr += 1;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
//	char *s = "asdasdqweasd";
	int	s[7] = {-49, 49, 1, -1, 0, -2, 2};	
	printf("%s\n", (char *)ft_memchr(s, -1, 7));
}
*/
