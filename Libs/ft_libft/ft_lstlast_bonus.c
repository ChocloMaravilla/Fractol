/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:20:53 by rmedina-          #+#    #+#             */
/*   Updated: 2024/05/14 13:26:24 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
void add_list(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
t_list *create_node()
{
	t_list *head;

	head = malloc(sizeof(t_list));
	head->content = "jaja";
	head->next = NULL;
	return (head);
}
int main(int argc, char **argv)
{
	t_list *head;
	t_list *new;
	int i;

	argv = NULL;
	if(argc != 2)
		return (1);
	i = 0;
	head = NULL;
	while(i < 10)
	{
		new = create_node();
		add_list(&head, new);
		i++;
	}
	new = ft_lstlast(new);
	printf("content: %s\n",new->content);
	return (0);
}*/
