/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:28:09 by rmedina-          #+#    #+#             */
/*   Updated: 2024/07/29 17:27:35 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_header.h"

double	ft_atod(char *num)
{
	int		i;
	int		sign;
	double	nbr;

	i = 0;
	sign = -1;
	nbr = 0;
	if (num[0] == '-' || num[0] == '+')
	{
		if (num[0] == '-')
			sign = -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		nbr = nbr * 10 + num[i] - '0';
		i++;
	}
	if (num[i] == '.')
		nbr = nbr + get_decimals(&num[i + 1]);
	return (nbr * sign);
}

double	get_decimals(char *num)
{
	double	dec;
	int		i;

	dec = 0;
	i = 0;
	while (num[i])
	{
		dec = dec * 10 + num[i] - '0';
		i++;
	}
	while (i != 0)
	{
		dec = dec / 10;
		i--;
	}
	return (dec);
}
