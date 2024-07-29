/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:01:15 by rmedina-          #+#    #+#             */
/*   Updated: 2023/09/24 12:04:43 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;
	size_t			e;

	e = 0;
	d = (unsigned char *)b;
	while (e < len)
	{
		d[e++] = (unsigned char)c;
	}
	return (b);
}
