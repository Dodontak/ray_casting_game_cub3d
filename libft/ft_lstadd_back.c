/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:46:19 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/18 20:56:32 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	t_list	elem[4];

	t_list	*begin = 0;
	printf("%p\n", begin);
	ft_lstadd_back(&begin, &elem[0]);
	printf("%p\n", begin);
    ft_lstadd_back(&begin, &elem[1]);
	printf("%p\n", begin);
    ft_lstadd_back(&begin, &elem[2]);
	printf("%p\n", begin);
    ft_lstadd_back(&begin, &elem[3]);
	printf("%p\n\n", begin);
	while (begin)
	{
		printf("%p\n", begin);
		begin = begin->next;
	}
}
*/
