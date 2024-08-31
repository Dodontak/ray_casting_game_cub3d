/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:48:27 by byejeon           #+#    #+#             */
/*   Updated: 2022/12/01 17:09:05 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = malloc(sizeof(t_list) * 1);
	if (out == 0)
		return (0);
	out->content = content;
	out->next = 0;
	return (out);
}
/*
#include <stdio.h>
int	main()
{
	unsigned char *a = malloc(sizeof(unsigned char) * 1);
	a[0] = 'a';
	ft_lstnew((void *)a);
	printf("asd\n");
}
*/
