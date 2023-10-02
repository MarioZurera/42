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

int	eval_hexlow(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (print_hex(hex, 'a'));
}

int	eval_hexup(va_list arg)
{
	unsigned int	hex;

	hex = va_arg(arg, unsigned int);
	return (print_hex(hex, 'A'));
}
