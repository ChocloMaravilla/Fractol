/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:28:47 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 14:55:27 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static char test_func(unsigned int n, char c)
// {)
//     if (n % 2 == 0)
//         return (ft_toupper(c));
//     return (ft_tolower(c));
// }
// int main()
// {
//     char a[] = "aaazzzzzzzzzzzzaholaaaaa";
//     ft_striteri(a, &test_func);
//     printf("%s", a);
//     return (0);
// }
