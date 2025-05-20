/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hinel-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:03:35 by hinel-mo          #+#    #+#             */
/*   Updated: 2024/11/21 12:59:01 by hinel-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!del || !lst || !(*lst))
		return ;
	if ((*lst)-> next)
		ft_lstclear((&(*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
