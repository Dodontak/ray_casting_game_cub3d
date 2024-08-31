/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:32:00 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 15:35:15 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*out;
	size_t	i;
	char	cc;

	cc = (char)c;
	i = 0;
	out = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			out = (char *)&s[i];
		i++;
	}
	if (cc == '\0')
		out = (char *)&s[i];
	return (out);
}
/*
#include <stdio.h>
int	main()
{
	char	s[] = "asdasd";
	printf("%s\n",ft_strrchr(s, 's'));
	return (0);
}
*/
