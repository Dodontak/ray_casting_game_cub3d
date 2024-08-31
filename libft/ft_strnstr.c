/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:57:30 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 15:03:14 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0' && i + j <= len)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char	str[] = "asdqwe";
	char	tofind[] = "qwe";
	printf("%s\n",ft_strnstr(str, tofind, 5));
}
*/
