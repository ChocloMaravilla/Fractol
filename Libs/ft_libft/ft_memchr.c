/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:33:00 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 08:22:12 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		if (str[count] == (char)c)
		{
			return ((void *)str + count);
		}
		count++;
	}
	return (NULL);
}
// int main()
// {
//     char *str = "hola";
//     char character = 'o';
//     size_t len = ft_strlen(str);
//     char *result;

//     result = ft_memchr(str, character, len);
//     printf("%s", result);
//     return (0);
// }
