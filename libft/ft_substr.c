/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:33:11 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 15:49:29 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	howlong(char const *s, unsigned int start, size_t len);
static char		*exeption(void);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*out;
	size_t			outlen;
	unsigned int	slen;
	size_t			i;

	i = 0;
	slen = ft_strlen((char *)s);
	if (slen < start)
		return (exeption());
	outlen = howlong(s, start, len);
	out = (char *)malloc(sizeof(char) * (outlen + 1));
	if (out == 0)
		return (0);
	while (i < outlen)
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}

static char	*exeption(void)
{
	char	*out;

	out = malloc(sizeof(char));
	if (out == 0)
		return (0);
	out[0] = '\0';
	return (out);
}

static size_t	howlong(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start])
	{
		start++;
		i++;
	}
	if (i > len)
		return (len);
	return (i);
}
/*
#include <stdio.h>
int	main()
{
	char *s = "asdasdqweasd";
	printf("%s\n",ft_substr(s,100,3));
	printf("%s\n",ft_substr(s,6,1));
	printf("%s\n",ft_substr(s,6,2));
	printf("%s\n",ft_substr(s,6,6));
	printf("%s\n",ft_substr(s,6,10));
	printf("%s\n",ft_substr(s,6,0));
	return (0);
}
*/
