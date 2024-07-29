/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:06:34 by rmedina-          #+#    #+#             */
/*   Updated: 2023/09/25 22:10:12 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			c;
	unsigned char	*o;
	unsigned char	*d;

	d = (unsigned char *)dst;
	o = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return ((char *)dst);
	if (d < o)
	{
		c = 0;
		while (c < len)
		{
			d[c] = o[c];
			c++;
		}
	}
	else if (o <= d)
	{
		while (len--)
			d[len] = o[len];
	}
	return ((char *)dst);
}
