/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:47 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:48 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	eval_char(va_list arg, t_conversion *data)
{
	int	n_print;

	n_print = 0;
	if (ft_strlen(data->flags) == 1 && data->flags[0] == '-')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		n_print = padding(ft_max(0, data->length - 1), ' ');
	}
	else if (ft_strlen(data->flags) > 1)
		return (-1);
	else
	{
		n_print = padding(ft_max(0, data->length - 1), ' ');
		ft_putchar_fd(va_arg(arg, int), 1);
	}
	n_print++;
	return (n_print);
}

int	eval_string(va_list arg, t_conversion *data)
{
	char	*s;
	int		n_print;

	n_print = 0;
	s = (char *) va_arg(arg, const char *);
	if (!check_flags(data->flags, "- "))
		return (-1);
	if (s == NULL)
		s = "(null)";
	if (data->precision > -1 && data->precision < ft_strlen(s))
		s[data->precision] = '\0';
	if (ft_strnstr(data->flags, ' ', 2) != 0 && s[0] == '\0')
		s = " ";
	if (ft_strnstr(data->flags, '-', 2) == 0)
		n_print += padding(ft_max(0, data->length - ft_strlen(s)), ' ');
	ft_putstr_fd(s, 1);
	n_print += ft_strlen(s);
	if (ft_strnstr(data->flags, '-', 2) != 0)
		n_print += padding(ft_max(0, data->length - ft_strlen(s)), ' ');
	return (n_print);
}

int	eval_pointer(va_list arg, t_conversion *data)
{
	unsigned long	addr;
	int				n_print;

	n_print = 0;
	if (!check_flags(data->flags, "-0"))
		return (-1);
	addr = (unsigned long) va_arg(arg, void *);
	n_print += ft_strlen("0x") + ft_hexlen(addr);
	if (ft_strnstr(data->flags, '-', 2) == 0)
	{
		if (ft_strnstr(data->flags, '0', 2) != 0 && data->precision == 0)
			n_print += padding(ft_max(0, data->length - n_print), '0');
		else
			n_print += padding(ft_max(0, data->length - n_print), ' ');
	}
	ft_putstr_fd("0x", 1);
	print_hex(addr, 'a');
	if (ft_strnstr(data->flags, '-', 2) != 0)
		n_print += padding(ft_max(0, data->length - n_print), ' ');
	return (n_print);
}

int	eval_decimal(va_list arg, t_conversion *data)
{
	int	d;
	int	n_print;

	if (!check_flags(data->flags, "-0 +"))
		return (-1);
	d = va_arg(arg, int);
	n_print = ft_nbrlen(d);
	if ((ft_strnstr(data->flags, '+', 3) != 0
			|| ft_strnstr(data->flags, ' ', 3) != 0) && d >= 0)
		n_print += 1;
	if (ft_strnstr(data->flags, '-', 2) == 0)
	{
		if (ft_strnstr(data->flags, '0', 2) != 0 && data->precision == 0)
			n_print += padding(ft_max(0, data->length - n_print), '0');
		else
			n_print += padding(ft_max(0, data->length - n_print), ' ');
	}
	if (ft_strnstr(data->flags, '+', 3) != 0)
		ft_putchar_fd('+', 1);
	else if (ft_strnstr(data->flags, ' ', 3) != 0)
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(d, 1);
	if (ft_strnstr(data->flags, '-', 2) != 0)
		n_print += padding(ft_max(0, data->length - n_print), ' ');
	return (n_print);
}

int	eval_unsigned(va_list arg)
{
	unsigned int	u;
	int				printed_chars;

	u = va_arg(arg, unsigned int);
	ft_putunbr_fd(u, 1);
	printed_chars = ft_unbrlen(u);
	return (printed_chars);
}
