/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:31:22 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 15:45:13 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	c;

	c = ft_strlen(s);
	i = 0;
	if (s == NULL)
		return (0);
	if (start >= c)
		return (ft_strdup(""));
	if (len > (c - start))
		len = c - start;
	a = malloc((len + 1) * (sizeof(char)));
	if (a == NULL)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start];
		i++;
		start++;
	}
	a[i] = '\0';
	return (a);
}

//  int main()
// {
//     char *a = "01234";
//     printf("%s", ft_substr(a, 10, 10));
//     return (0);
// }
