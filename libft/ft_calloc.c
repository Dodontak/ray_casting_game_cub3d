/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:47:06 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:29:29 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*out;
	unsigned char	*ptr;
	size_t			n;

	n = size * count;
	out = malloc(n);
	if (out == 0)
		return (0);
	ptr = (unsigned char *)out;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
	return (out);
}
/*
#include <stdio.h>
int	main()
{
	int *str = ft_calloc(5, sizeof(int));
	str[0] = 1;
	str[1] = 2;
	str[2] = 3;
	str[3] = 4;
	str[4] = 5;
	for(int i = 0; i < 5; i++)
		printf("%d\n", str[i]);
}
*/
