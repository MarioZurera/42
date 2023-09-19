/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:26:04 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/19 17:52:11 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned long int addr, char letter, int *printed_chars)
{
	char	hex;

	hex = addr % 16;
	if (addr >= 16)
		print_hex(addr / 16, letter, printed_chars);
	if (hex < 10)
		hex += '0';
	else
		hex += (letter - 10);
	ft_putchar_fd(hex, 1);
	(*printed_chars)++;
}

static void	print_hexint(unsigned int addr, char letter, int *printed_chars)
{
	char	hex;

	hex = addr % 16;
	if (addr >= 16)
		print_hexint(addr / 16, letter, printed_chars);
	if (hex < 10)
		hex += '0';
	else
		hex += (letter - 10);
	ft_putchar_fd(hex, 1);
	(*printed_chars)++;
}

int	eval_hexlow(va_list arg)
{
	unsigned long	addr;
	int				printed_chars;

	addr = va_arg(arg, unsigned int);
	print_hexint(addr, 'a', &printed_chars);
	return (printed_chars);
}

int	eval_hexup(va_list arg)
{
	unsigned long	addr;
	int				printed_chars;

	addr = va_arg(arg, unsigned int);
	print_hexint(addr, 'A', &printed_chars);
	return (printed_chars);
}
