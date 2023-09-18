/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:02 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/14 20:10:25 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
	return (flag);
}

int	eval_conversion(const char *format, int pos, va_list arg)
{
	char	flag;

	flag = eval_flag(format, &pos);
	if (format[pos++] == 'c')
		eval_char(arg);
	else if (format[pos++] == 's')
		eval_string(arg, flag);
	else if (format[pos++] == 'p')
		eval_pointer(arg, flag);
	else if (format[pos++] == 'd' || format[pos] == 'i')
		eval_decimal(arg, flag);
	else if (format[pos++] == 'u')
		eval_unsigned(arg, flag);
	else if (format[pos++] == 'x')
		eval_hexlow(arg, flag);
	else if (format[pos++] == 'X')
		eval_hexup(arg, flag);
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
