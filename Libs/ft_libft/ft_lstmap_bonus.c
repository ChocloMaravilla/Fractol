/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:41:59 by rmedina-          #+#    #+#             */
/*   Updated: 2024/05/14 13:45:36 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*mod_cont;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		mod_cont = f(lst->content);
		if (mod_cont == NULL)
			return (ft_lstclear(&head, del), NULL);
		new = ft_lstnew(mod_cont);
		if (new == NULL)
			return (ft_lstclear(&head, del), del(mod_cont), NULL);
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
