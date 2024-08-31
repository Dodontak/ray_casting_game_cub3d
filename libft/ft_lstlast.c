/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:46:05 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/18 20:01:54 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int	main()
{
	t_list	elem[4];
	elem[0].next = &elem[1];
	elem[1].next = &elem[2];
	elem[2].next = &elem[3];
	elem[3].next = 0;

	printf("%p\n",elem);
	printf("%p\n",&elem[0]);
}
*/
