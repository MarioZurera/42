/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:25:40 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/19 16:46:59 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	eval_conversion(const char *format, int pos, va_list arg)
{
	int	printed_chars;

	printed_chars = 0;
	if (format[pos] == 'c')
		printed_chars = eval_char(arg);
	else if (format[pos] == 's')
		printed_chars = eval_string(arg);
	else if (format[pos] == 'p')
		printed_chars = eval_pointer(arg);
	else if (format[pos] == 'd' || format[pos] == 'i')
		printed_chars = eval_decimal(arg);
	else if (format[pos] == 'u')
		printed_chars = eval_unsigned(arg);
	else if (format[pos] == 'x')
		printed_chars = eval_hexlow(arg);
	else if (format[pos] == 'X')
		printed_chars = eval_hexup(arg);
	else if (format[pos] == '%')
	{
		++printed_chars;
		ft_putchar_fd('%', 1);
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		printed_chars;
	int		pos;

	va_start(arg, format);
	printed_chars = 0;
	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			printed_chars += eval_conversion(format, pos, arg);
		}
		else
		{
			ft_putchar_fd(format[pos], 1);
			++printed_chars;
		}
		++pos;
	}
	va_end(arg);
	return (printed_chars);
}
