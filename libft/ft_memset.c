/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:23 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:11:45 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len--)
	{
		*ptr = c;
		ptr++;
	}
	return (b);
}
/*
#include <stdlib.h>
int	main()
{
	char *str = malloc(sizeof(char) * 7);
	int	i = 0;
	while (i < 6)
	{
		str[i] = 'a' + i;
		i++;
	}
	str[i] = 0;
	str = (char *)ft_memset(str, 'k', 0);
	while (*str)
		printf("%c",*(str++));
	printf("\n");
}
*/
