/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:56:41 by ruben             #+#    #+#             */
/*   Updated: 2023/12/07 17:42:05 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(unsigned long n, int *strlen, char c)
{
	if ((int)n < 0 && c != 'u')
	{
		ft_putchar('-', strlen);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, strlen, c);
	ft_putchar(n % 10 + '0', strlen);
}
