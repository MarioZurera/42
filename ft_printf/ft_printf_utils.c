/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:36 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/18 19:38:22 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_char(va_list arg)
{
	unsigned char	c;

	c = (unsigned char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	eval_string(va_list arg)
{
	const char	*s;

	s = va_arg(arg, const char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	eval_pointer(va_list arg)
{
	void			*ptr;
	unsigned long	addr;
	int				printed_chars;

	ptr = va_arg(arg, void *);
	addr = (unsigned long) ptr;
	print_hex(addr, 'A', &printed_chars);
	return (printed_chars);
}

int	eval_decimal(va_list arg)
{
	int	d;
	int	printed_chars;

	d = va_arg(arg, int);
	ft_putnbr_fd(d, 1);
	printed_chars = ft_nbrlen(d);
	return (printed_chars);
}

int	eval_unsigned(va_list arg)
{
	unsigned int	d;
	int				printed_chars;

	d = va_arg(arg, unsigned int);
	ft_putnbr_fd(d, 1);
	printed_chars = ft_unbrlen(d);
	return (printed_chars);
}
