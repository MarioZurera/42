/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:29 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:30 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_char(va_list arg)
{
	unsigned char	c;

	c = (unsigned char) va_arg(arg, int);
	return (ft_putchar_fd(c, 1));
}

int	eval_string(va_list arg)
{
	const char	*s;

	s = va_arg(arg, const char *);
	return (ft_putstr_fd(s, 1));
}

int	eval_pointer(va_list arg)
{
	unsigned long	addr;
	int				printed_chars;

	addr = (unsigned long) va_arg(arg, void *);
	if (ft_putstr_fd("0x", 1) < 2)
		return (-1);
	printed_chars = print_hex(addr, 'a');
	return (printed_chars + 2);
}

int	eval_decimal(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	return (ft_putnbr_fd(d, 1));
}

int	eval_unsigned(va_list arg)
{
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	return (ft_putunbr_fd(u, 1));
}
