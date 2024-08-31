/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:29:33 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/12 12:38:05 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	t_list lst[5];

	lst[0].next = &lst[4];
	lst[4].next = &lst[2];
	lst[2].next = &lst[1];
	lst[1].next = &lst[3];
	lst[3].next = 0;
	printf("%d\n",ft_lstsize(lst));
}
*/
