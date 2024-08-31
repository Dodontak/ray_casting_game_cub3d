/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:50:55 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/29 15:49:52 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set);
static int	find_front(char const *s1, char const *set);
static int	find_back(char const *s1, char const *set);
static char	*exeption(void);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		front_idx;
	int		back_idx;
	int		i;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (exeption());
	front_idx = find_front(s1, set);
	back_idx = find_back(s1, set);
	if (front_idx > back_idx)
		return (exeption());
	out = (char *)malloc(sizeof(char) * (back_idx - front_idx + 1 + 1));
	if (out == 0)
		return (0);
	while (front_idx <= back_idx)
		out[i++] = s1[front_idx++];
	out[i] = '\0';
	return (out);
}

static char	*exeption(void)
{
	char	*out;

	out = (char *)malloc(sizeof(char));
	if (out == 0)
		return (0);
	out[0] = '\0';
	return (out);
}

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	find_front(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	return (i);
}

static int	find_back(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	i--;
	while (i >= 0 && is_in_set(s1[i], set))
		i--;
	return (i);
}
/*
int	main()
{
	printf("%s\n",ft_strtrim("asdasd","asd"));
}
*/
