/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:36 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:37 by mzurera-         ###   ########.fr       */
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
	unsigned int	hex;
	int				printed_chars;

	printed_chars = 0;
	hex = va_arg(arg, unsigned int);
	print_hexint(hex, 'a', &printed_chars);
	return (printed_chars);
}

int	eval_hexup(va_list arg)
{
	unsigned int	hex;
	int				printed_chars;

	printed_chars = 0;
	hex = va_arg(arg, unsigned int);
	print_hexint(hex, 'A', &printed_chars);
	return (printed_chars);
}
