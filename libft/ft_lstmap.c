/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:08:02 by byejeon           #+#    #+#             */
/*   Updated: 2022/11/22 13:10:37 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*new;
	void	*content;

	out = 0;
	while (lst)
	{
		content = f(lst->content);
		if (content == 0)
		{
			if (out != 0)
				ft_lstclear(&out, del);
			return (0);
		}
		new = ft_lstnew(content);
		if (new == 0)
		{
			free(content);
			ft_lstclear(&out, del);
			return (0);
		}
		ft_lstadd_back(&out, new);
		lst = lst->next;
	}
	return (out);
}
