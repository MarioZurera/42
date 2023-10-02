/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:41:02 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 14:41:03 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_hex(unsigned long int n, char letter)
{
	char	hex;
	int		length;

	length = 0;
	hex = n % 16;
	if (n >= 16)
		length = print_hex(n / 16, letter);
	if (hex < 10)
		hex += '0';
	else
		hex += (letter - 10);
	if (length < 0 || ft_putchar_fd(hex, 1) < 0)
		return (-1);
	return (length + 1);
}

int	eval_hexlow(va_list arg, t_conversion *data)
{
	unsigned int	hex;
	int				n_print;

	if (!check_flags(data->flags, "#0-"))
		return (-1);
	hex = va_arg(arg, unsigned int);
	n_print = ft_hexlen(hex);
	if (ft_strchr(data->flags, '#') != 0 && hex != 0)
		n_print += 2;
	if (ft_strchr(data->flags, '-') == 0)
	{
		if (ft_strchr(data->flags, '0') != 0)
			n_print += padding(ft_max(0, data->length - n_print), '0');
		else
			n_print += padding(ft_max(0, data->length - n_print), ' ');
	}
	if (ft_strchr(data->flags, '#') != 0 && hex != 0)
		ft_putstr_fd("0x", 1);
	print_hex(hex, 'a');
	if (ft_strchr(data->flags, '-') != 0)
		n_print += padding(ft_max(0, data->length - n_print), ' ');
	return (n_print);
}

int	eval_hexup(va_list arg, t_conversion *data)
{
	unsigned int	hex;
	int				n_print;

	if (!check_flags(data->flags, "#0-"))
		return (-1);
	hex = va_arg(arg, unsigned int);
	n_print = ft_hexlen(hex);
	if (ft_strchr(data->flags, '#') != 0 && hex != 0)
		n_print += 2;
	if (ft_strchr(data->flags, '-') == 0)
	{
		if (ft_strchr(data->flags, '0') != 0)
			n_print += padding(ft_max(0, data->length - n_print), '0');
		else
			n_print += padding(ft_max(0, data->length - n_print), ' ');
	}
	if (ft_strchr(data->flags, '#') != 0 && hex != 0)
		ft_putstr_fd("0X", 1);
	print_hex(hex, 'A');
	if (ft_strchr(data->flags, '-') != 0)
		n_print += padding(ft_max(0, data->length - n_print), ' ');
	return (n_print);
}
