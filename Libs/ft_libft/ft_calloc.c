/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:53:44 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 15:36:56 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*a;

	a = (malloc(nmemb * size));
	if (!a)
		return (NULL);
	ft_bzero(a, nmemb * size);
	return (a);
}

// int main()
// {
//     char *a;
//     a = ft_calloc(5, 4);
//     printf("tu string da: %s", a);
//     return (0);
// }
