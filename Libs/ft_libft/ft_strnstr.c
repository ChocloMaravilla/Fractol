/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:03:50 by ruben             #+#    #+#             */
/*   Updated: 2023/10/22 18:57:18 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	len2;

	j = 0;
	len2 = ft_strlen(needle);
	if (!needle || !*needle)
	{
		return ((char *)haystack);
	}
	while (j < len && haystack[j] != 0)
	{
		i = 0;
		while (i < len2 && i + j < len && haystack[j + i] == needle[i])
		{
			i++;
		}
		if (i == len2)
		{
			return ((char *)haystack + j);
		}
		j++;
	}
	return (0);
}

// int main()
// {
//     char *str = "Buenos dias";
//     char *cha = "o";
//     char *result;
//     size_t len = ft_strlen(str);

//     result = ft_strnstr(str, cha, len);
//     printf("%s", result);
//     return (0);
// }
