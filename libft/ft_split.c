/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:29:02 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 18:49:44 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	how_many_chunk(char const *str, char c);
static char		**make_strs(char **strs, char const *str, char c, size_t size);
static char		**make_allfree(char **strs, size_t y);

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**strs;

	size = how_many_chunk(s, c);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (strs == 0)
		return (0);
	return (make_strs(strs, s, c, size));
}

static char	**make_strs(char **strs, char const *str, char c, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	i;

	y = 0;
	while (y < size)
	{
		x = 0;
		i = 0;
		while (*str && *str == c)
			str++;
		while (str[i] && str[i] != c)
			i++;
		strs[y] = (char *)malloc(sizeof(char) * (i + 1));
		if (strs[y] == 0)
			return (make_allfree(strs, y));
		while (i--)
			strs[y][x++] = *(str++);
		strs[y][x] = '\0';
		y++;
	}
	strs[y] = 0;
	return (strs);
}

static size_t	how_many_chunk(char const *str, char c)
{
	size_t	count;
	int		on;

	on = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && on == 0)
		{
			count++;
			on = 1;
		}
		else if (*str == c && on == 1)
			on = 0;
		str++;
	}
	return (count);
}

static char	**make_allfree(char **strs, size_t y)
{
	size_t	i;

	i = 0;
	while (i < y)
		free(strs[i++]);
	free(strs);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char c = '0';
	char *str = "00asd0qwe0z0xc0";
	char **strs = 	ft_split(str, c);

	for(int i = 0, size = how_many_chunk(str, c); i < size; i++)
		printf("%s\n", strs[i]);
}
*/
