/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:49:41 by rmedina-          #+#    #+#             */
/*   Updated: 2024/05/14 13:40:54 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while (head)
	{
		if (head->next == NULL)
		{
			head->next = new;
			return ;
		}
		head = head->next;
	}
	return ;
}
