/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:02 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/13 13:43:23 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	eval_flag(const char *format, int *pos)
{
	char	flag;

	flag = '\0';
	while (format[*pos] == '#' || format[*pos] == ' ' || format[*pos] == '+')
	{
		if (format[*pos] == '#')
			flag = '#';
		else if (format[*pos] == '+' && flag != '#')
			flag = '+';
		else if (format[*pos] == ' ' && flag == '\0')
			flag = ' ';
	}
}

int	eval_conversion(const char *format, int pos, va_list arg)
{
	char	flag;

	flag = eval_flag(format, &pos);
	if (format[pos++] == 'c')
		eval_char(format, pos, arg, flag);
	else if (format[pos++] == 's')
		eval_string(format, pos, arg, flag);
	else if (format[pos++] == 'p')
		eval_pointer(format, pos, arg, flag);
	else if (format[pos++] == 'd' || format[pos] == 'i')
		eval_decimal(format, pos, arg, flag);
	else if (format[pos++] == 'u')
		eval_unsigned(format, pos, arg, flag);
	else if (format[pos++] == 'x')
		eval_hexlow(format, pos, arg, flag);
	else if (format[pos++] == 'X')
		eval_hexup(format, pos, arg, flag);
	else if (format[pos++] == '%')
		ft_putchar_fd('%', 1);
	return (pos);
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
			++pos;
			pos = eval_conversion(format, pos, arg);
		}
		else
		{
			ft_putchar_fd(format[pos], 1);
			++pos;
		}
		++printed_chars;
	}
	va_end(arg);
	return (printed_chars);
}
