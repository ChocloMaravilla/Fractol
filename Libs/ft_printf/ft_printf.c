/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:50:41 by rmedina-          #+#    #+#             */
/*   Updated: 2023/12/07 17:55:23 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *strlen)
{
	if (*strlen != -1)
	{
		if (write (1, &c, 1) == -1)
			*strlen = -1;
		else
			*strlen += 1;
	}
}

void	ft_printhexa(unsigned long nmb, int *count, char form)
{
	char	*stru;
	char	*strl;

	stru = "0123456789ABCDEF";
	strl = "0123456789abcdef";
	if (nmb >= 16)
		ft_printhexa (nmb / 16, count, form);
	if (*count != -1)
	{
		if (form == 'x' || form == 'p')
			ft_putchar (strl[nmb % 16], count);
		else if (form == 'X')
			ft_putchar (stru[nmb % 16], count);
	}
}

void	ft_strswitch(char c, int *strlen, va_list args)
{
	if (c == 'c')
		ft_putchar (va_arg(args, int), strlen);
	else if (c == 'p')
	{
		ft_putstr_fd ("0x", strlen);
		ft_printhexa (va_arg(args, unsigned long), strlen, c);
	}
	else if (c == 's')
		ft_putstr_fd (va_arg(args, char *), strlen);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd (va_arg(args, int), strlen, c);
	else if (c == 'u')
		ft_putnbr_fd (va_arg(args, unsigned int), strlen, c);
	else if (c == 'x' || c == 'X')
		ft_printhexa (va_arg(args, unsigned int), strlen, c);
	else if (c == '%')
		ft_putchar(c, strlen);
}

int	ft_printf(char const *string_args, ...)
{
	int		strlen;
	va_list	args;

	strlen = 0;
	va_start(args, string_args);
	while (*string_args && strlen != -1)
	{
		if (*string_args == '%')
		{
			string_args++;
			ft_strswitch(*string_args, &strlen, args);
		}
		else
			ft_putchar(*string_args, &strlen);
		string_args++;
	}
	va_end(args);
	return (strlen);
}
