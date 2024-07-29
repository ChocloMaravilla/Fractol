/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:53:38 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 14:51:30 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	c = (char)c;
	len = ft_strlen(s);
	if (!c)
		return ((char *)&s[len]);
	while (s[len] != c)
	{
		if (len <= 0)
			return (NULL);
		len--;
	}
	return ((char *)&s[len]);
}
