/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:18:49 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 16:16:34 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (dptr == sptr)
		return (dst);
	while (n--)
		*(dptr++) = *(sptr++);
	return (dst);
}
/*
int main()
{
	char src[] = "asdqwe";
	char *dst;
	dst = src + 1;
	printf("%s\n",src);
	ft_memcpy((void *)dst, (void *)src, 3);
	printf("%s\n",src);
}
*/
