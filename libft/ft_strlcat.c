/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:07:37 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 19:00:51 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(const char *dest, const char *src, size_t size)
{
	size_t			d_index;
	size_t			s_index;
	size_t			d_len;
	size_t			s_len;
	unsigned char	*tmp;

	tmp = (unsigned char *)dest;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	d_index = 0;
	s_index = 0;
	if (size <= d_len)
		return (size + s_len);
	while (dest[d_index])
		d_index++;
	while (src[s_index] && d_index + 1 < size)
	{
		tmp[d_index] = src[s_index];
		s_index++;
		d_index++;
	}
	tmp[d_index] = '\0';
	return (s_len + d_len);
}
