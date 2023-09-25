/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:55 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	get_lengths(char *flags, va_list arg, int *length, int *prec)
{
	int	i;
	int	j;

	i = 0;
	while (flags[i] && !ft_isdigit(flags[i]) && !ft_strchr("0.", flags[i]))
		i++;
	j = i;
	if (ft_isdigit(flags[i]))
		*length = ft_atoi(&flags[i]);
	else if (flags[i] == '*')
		*length = va_arg(arg, int);
	i += ft_nbrlen(*length);
	if (flags[i] == '.')
	{
		++i;
		if (ft_isdigit(flags[i]))
			*prec = ft_atoi(&flags[i + 1]);
		else if (flags[i] == '*')
			*prec = va_arg(arg, int);
	}
	flags[j] = '\0';
}

int	ft_conversion(const char *format, int *pos, va_list arg, t_conversion *data)
{
	int	n_print;

	n_print = 0;
	if (format[*pos] == 'c')
		n_print = eval_char(arg, data);
	else if (format[*pos] == 's')
		n_print = eval_string(arg, data);
	else if (format[*pos] == 'p')
		n_print = eval_pointer(arg, data);
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		n_print = eval_decimal(arg, data);
	else if (format[*pos] == 'u')
		n_print = eval_unsigned(arg, data);
	else if (format[*pos] == 'x')
		n_print = eval_hexlow(arg, data);
	else if (format[*pos] == 'X')
		n_print = eval_hexup(arg, data);
	else if (format[*pos] == '%')
	{
		++n_print;
		ft_putchar_fd('%', 1);
	}
	return (n_print);
}

int	padding(int n, char c)
{
	int	m;

	m = n;
	while (m--)
		ft_putchar_fd(c, 1);
	return (n);
}

int	check_flags(char *flags, char *set)
{
	while (*flags)
	{
		if (ft_strchr(set, *flags))
			return (0);
		flags++;
	}
	return (1);
}

int	ft_hexlen(unsigned long n)
{
	int	length;

	length = 0;
	while (n)
	{
		n /= 16;
		length++;
	}
	return (length);
}
