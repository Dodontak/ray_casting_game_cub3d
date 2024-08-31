/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:34:27 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:43:34 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	out = malloc(sizeof(char) * (len + 1));
	if (out == 0)
		return (0);
	while (*s1)
		out[i++] = *(s1++);
	while (*s2)
		out[i++] = *(s2++);
	out[i] = '\0';
	return (out);
}
/*
#include <stdio.h>
int	main()
{
	char s1[] = "asdasdasd";
	char s2[] = "01230123";
	printf("%s\n", ft_strjoin(s1, s2));
}
*/
