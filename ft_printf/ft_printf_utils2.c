/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:44:10 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/18 19:31:42 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(long int addr, char letter, int *printed_chars)
{
	char	hex;

	hex = (addr % 16) * ((-1) * (addr < 0));
	if (addr >= 16 || addr <= -16)
		print_hex(addr / 16, letter, printed_chars);
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

	addr = va_arg(arg, unsigned long);
	print_hex(addr, 'a', &printed_chars);
	return (printed_chars);
}

int	eval_hexup(va_list arg)
{
	unsigned long	addr;
	int				printed_chars;

	addr = va_arg(arg, unsigned long);
	print_hex(addr, 'A', &printed_chars);
	return (printed_chars);
}
