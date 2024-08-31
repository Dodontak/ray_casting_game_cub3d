/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:54:47 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/13 12:17:19 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *s1, char *s2)
{
	size_t	size;
	char	*nlptr;
	char	*out;

	nlptr = (ft_strchr(s2, '\n'));
	if (nlptr)
		size = ft_strlen(s1) + find_nl_idx(s2) + 1;
	else
		size = ft_strlen(s1) + ft_strlen(s2);
	out = malloc(sizeof(char) * (size + 1));
	if (out == 0)
		return (free_str(s1, s2));
	ft_strlcpy(out, s1, size + 1);
	ft_strlcat(out, s2, size + 1);
	free_str(s1, s2);
	if (out[0] == '\0')
		return (free_str(out, NULL));
	return (out);
}
