/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:20:42 by rmedina-          #+#    #+#             */
/*   Updated: 2023/12/07 17:55:57 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *string_args, ...);
void	ft_putstr_fd(char *s, int *strlen);
void	ft_putnbr_fd(unsigned long n, int *strlen, char c);
void	ft_putchar(char c, int *strlen);

#endif
