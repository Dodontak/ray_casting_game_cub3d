/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:52:26 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:52:49 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	i = 0;
	while (tmps1[i] && tmps2[i] && i < n)
	{
		if (tmps1[i] != tmps2[i])
			return (tmps1[i] - tmps2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (tmps1[i] - tmps2[i]);
}
/*
#include <stdio.h>
int	main()
{
	//char	s1[] = "asd";
	//char	s2[] = "a";

	printf("%d\n",ft_strncmp("\200", "\0", 6));
}
*/
