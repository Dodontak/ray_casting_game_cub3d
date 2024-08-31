/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:31:47 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 16:11:03 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_src;
	unsigned char	*c_dst;
	size_t			i;

	if (src > dst)
	{
		c_src = (unsigned char *)src;
		c_dst = (unsigned char *)dst;
		i = 0;
		while (++i <= len)
			*(c_dst++) = *(c_src++);
	}
	else if (src < dst)
	{
		i = 0;
		c_src = (unsigned char *)src + len - 1;
		c_dst = (unsigned char *)dst + len - 1;
		while (++i <= len)
			*(c_dst--) = *(c_src--);
	}
	return (dst);
}
/*
#include <stdlib.h>
int	main()
{
	char src[] = "abcdef";
	char *out = src + 1;
	
	ft_memmove((void *)out, (void *)src, sizeof(char) * 7);
	while (*out)
		printf("%c",*(out++));
	printf("\n");
}
*/
