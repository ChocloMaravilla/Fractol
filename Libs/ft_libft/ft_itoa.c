/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruben <ruben@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:12:50 by ruben             #+#    #+#             */
/*   Updated: 2023/10/23 14:49:05 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_size(int n, int *negative)
{
	int	count;

	count = 0;
	*negative = n < 0;
	if (*negative)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	write_num(char *a, int n, int negative, int size)
{
	int	i;
	int	min;

	i = size - 1;
	min = 0;
	if (negative)
	{
		a[0] = '-';
		n *= -1;
		min = 1;
	}
	a[size] = '\0';
	while (i >= min)
	{
		a[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*a;
	int		size;
	int		negative;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = calc_size(n, &negative);
	a = (char *)malloc(size + 1);
	if (!a)
		return (0);
	write_num(a, n, negative, size);
	return (a);
}
