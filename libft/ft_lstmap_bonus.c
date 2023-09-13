/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:33:31 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/13 13:16:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*current;

	if (lst == NULL)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (new_lst == NULL)
		return (NULL);
	current = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		current->next = ft_lstnew((*f)(lst->content));
		if (current->next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (new_lst);
}
