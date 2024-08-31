/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:23:03 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:42:30 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(s1);
	out = (char *)malloc(sizeof(char) * (slen + 1));
	if (out == 0)
		return (0);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
/*
#include <stdio.h>
int	main()
{
	char	*s1 = "asdasdqwe";

	printf("%s\n",s1);
	printf("%s\n",ft_strdup(s1));
}
*/
