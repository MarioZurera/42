/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:44:10 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/14 20:10:14 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_hex(long int addr, char letter)
{
	char	hex;

	hex = (addr % 16) * ((-1) * (addr < 0));
	if (addr >= 16 || addr <= -16)
		print_hex(addr / 16, letter);
	if (hex < 10)
		hex += '0';
	else
		hex += (letter - 10);
	ft_putchar_fd(hex, 1);
}

void	eval_hexlow(va_list arg, char flag)
{
	unsigned long	addr;

	addr = va_arg(arg, unsigned long);
	if (flag == '#')
		ft_putstr_fd("0x", 1);
	if (flag == '+' && addr > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && addr > 0)
		ft_putchar_fd(' ', 1);
	print_hex(addr, 'a');
}

void	eval_hexup(va_list arg, char flag)
{
	unsigned long	addr;

	addr = va_arg(arg, unsigned long);
	if (flag == '#')
		ft_putstr_fd("0X", 1);
	if (flag == '+' && addr > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && addr > 0)
		ft_putchar_fd(' ', 1);
	print_hex(addr, 'A');
}
