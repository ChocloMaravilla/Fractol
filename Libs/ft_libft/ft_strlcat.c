/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:49:47 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 14:55:03 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c;
	size_t	f;

	f = ft_strlen(dst);
	if (!src || f >= size)
		return (ft_strlen(src) + size);
	c = 0;
	while (src[c] && c + f < size - 1)
	{
		dst[f + c] = src[c];
		c++;
	}
	dst[f + c] = '\0';
	return (f + ft_strlen(src));
}
/*
int	main(void)
{
	char	src[5] = "hola" ;
	char	dst[14] = "caracola";

	ft_strlcat(dst, src, 5);
	printf("%s", dst);
	return (0);
}
*/
