/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:21:16 by hinel-mo          #+#    #+#             */
/*   Updated: 2024/11/21 13:50:40 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new_lst;
	void	*content;

	if (!lst)
		return (NULL);
	new_lst = 0;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (!content && new_lst)
			return (ft_lstclear(&new_lst, del), NULL);
		start = ft_lstnew(content);
		if (!start)
		{
			del(content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, start);
		lst = lst->next;
	}
	return (new_lst);
}
