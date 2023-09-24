/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:06:42 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/24 07:03:37 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	eval_char(va_list arg, t_conversion *data)
{
	int	n_print;

	if (ft_strlen(data->flag) == 1 && data->flag[0] == '-')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		n_print = ft_pad(ft_max(0, data->length - 1));
	}
	else if (ft_strlen(data->flag) > 1)
		return (-1);
	else
	{
		n_print = print_padding(ft_max(0, data->length - 1));
		ft_putchar_fd(va_arg(arg, int), 1);
	}
	n_print++;
	return (n_print);
}

int	eval_string(va_list arg)
{
	char	*s;

	s = (char *) va_arg(arg, const char *);
	if (!check_flags(data->flags. "- "))
		return (-1);
	if (s == NULL)
		s = "(null)";
	if (data->precision > -1 && data->precision < ft_strlen(s))
		s[data->precision] = '\0';
	if (strnstr(data->flags, ' ', 2) != 0 && str[0] == '\0')
		s = " ":
	if (strnstr(data->flags. '-', 2) == 0)
		n_print = ft_pad(ft_max(0, data->length - ft_strlen(s)));
	ft_putstr_fd(s, 1);
	if (strnstr(data->flags, '-', 2) != 0)
		n_print = ft_pad(ft_max(0, data->length - ft_strlen(s)));
	n_print += ft_strlen(s);
	return (n_print);
}

int	eval_pointer(va_list arg)
{
	void			*ptr;
	unsigned long	addr;
	int				printed_chars;

	ptr = va_arg(arg, void *);
	addr = (unsigned long) ptr;
	ft_putstr_fd("0x", 1);
	printed_chars = ft_strlen("0x");
	print_hex(addr, 'a', &printed_chars);
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
	unsigned int	u;
	int				printed_chars;

	u = va_arg(arg, unsigned int);
	ft_putunbr_fd(u, 1);
	printed_chars = ft_unbrlen(u);
	return (printed_chars);
}
