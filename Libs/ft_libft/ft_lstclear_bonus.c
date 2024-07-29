/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:17:45 by rmedina-          #+#    #+#             */
/*   Updated: 2024/05/14 13:28:18 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*aux;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	aux = *lst;
	while (aux)
	{
		tmp = aux->next;
		del(aux->content);
		free(aux);
		aux = tmp;
	}
	*lst = NULL;
}
