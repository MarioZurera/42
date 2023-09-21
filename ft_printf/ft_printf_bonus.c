/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:16:58 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/21 19:34:50 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*get_flags(const char *format, int *pos)
{
	char	*flags;
	char	*conversions;
	int		start;
	char	*result;

	conversions = "cspdiuxX%";
	flags = "-0# +";
	start = *pos;
	while (ft_strchr(flags, format[*pos]))
		(*pos)++;
	if (format[*pos] == '.')
		(*pos)++;
	while (isdigit(format[*pos]))
		(*pos)++;
	if (!ft_strchr(conversion, format[*pos]))
		return (NULL);
	result = ft_substr(format, start, *pos - start);
	if (result == NULL)
		return (NULL);
	return (result);
}

static char	*eval_flags(char *flags)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flags[i])
	{
		if (!ft_strnchr(flags, flags[i], j) || ft_isdigit(flags[i]))
		{
			flags[j] = flags[i];
			j++;
		}
		i++;
	}
	flags[j] = '\0';
	return (flags);
}

int	eval_conversion(const char *format, int *pos, va_list arg)
{
	int		printed_chars;
	char	*flags;

	flags = get_flags(format, pos);
	if (flags == NULL)
		return (-1);
	flags = eval_flags(flags);
	printed_chars = 0;
	if (format[pos] == 'c')
		printed_chars = eval_char(arg, flags);
	else if (format[pos] == 's')
		printed_chars = eval_string(arg, flags);
	else if (format[pos] == 'p')
		printed_chars = eval_pointer(arg, flags);
	else if (format[pos] == 'd' || format[pos] == 'i')
		printed_chars = eval_decimal(arg, flags);
	else if (format[pos] == 'u')
		printed_chars = eval_unsigned(arg, flags);
	else if (format[pos] == 'x')
		printed_chars = eval_hexlow(arg, flags);
	else if (format[pos] == 'X')
		printed_chars = eval_hexup(arg, flags);
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
	int		temp;

	va_start(arg, format);
	printed_chars = 0;
	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			temp = eval_conversion(format, &(++pos), arg);
			if (temp < 0)
				return (-1);
			printed_chars += temp - 1;
		}
		else
			ft_putchar_fd(format[pos], 1);
		++printed_chars;
		++pos;
	}
	va_end(arg);
	return (printed_chars);
}
