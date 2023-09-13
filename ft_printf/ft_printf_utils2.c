/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:44:10 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/13 13:44:11 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_hex(unsigned long addr, char letter)
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

void	eval_hexlow(const char *format, int pos, va_list arg, char flag)
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

void	eval_hexup(const char *format, int pos, va_list arg, char flag)
{
	unsigned long	addr;
	char			hex;

	addr = va_arg(arg, unsigned long);
	if (flag == '#')
		ft_putstr_fd("0X", 1);
	if (flag == '+' && addr > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && addr > 0)
		ft_putchar_fd(' ', 1);
	print_hex(addr, 'A');
}
