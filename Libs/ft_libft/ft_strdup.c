/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 22:53:44 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 08:27:11 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	count;
	char	*a;
	size_t	len;

	count = 0;
	len = ft_strlen(s);
	a = malloc((len + 1) * (sizeof(char)));
	if (!a)
		return (NULL);
	while (s[count] != '\0')
	{
		a[count] = (char)s[count];
		count++;
	}
	a[count] = '\0';
	return (a);
}

// int main()
// {
//     char *a = "hola";
//     char *b;
//     b = ft_strdup(a);
//     printf("%s", b);
//     return (0);
// }
