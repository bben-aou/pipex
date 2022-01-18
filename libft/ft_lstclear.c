/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-aou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:47:56 by bben-aou          #+#    #+#             */
/*   Updated: 2021/12/07 18:52:54 by bben-aou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*act;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		act = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(act, del);
	}
	*lst = NULL;
}
