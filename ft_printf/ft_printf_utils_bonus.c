/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:36 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/14 20:10:54 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	eval_char(va_list arg)
{
	char	c;

	c = (char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
}

void	eval_string(va_list arg, char flag)
{
	char	*s;

	s = va_arg(arg, char *);
	if (flag == ' ' && !*s)
		ft_putchar_fd(' ', 1);
	else
		ft_putstr_fd(s, 1);
}

void	eval_pointer(va_list arg, char flag)
{
	void			*ptr;
	unsigned long	addr;

	ptr = va_arg(arg, void *);
	addr = (unsigned long) ptr;
	if (flag == '+' && addr > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && addr > 0)
		ft_putchar_fd(' ', 1);
	print_hex(addr, 'A');
}

void	eval_decimal(va_list arg, char flag)
{
	int	d;

	d = va_arg(arg, int);
	if (flag == '+' && d > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && d > 0)
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(d, 1);
}

void	eval_unsigned(va_list arg, char flag)
{
	unsigned int	d;

	d = va_arg(arg, unsigned int);
	if (flag == '+')
		ft_putchar_fd('+', 1);
	if (flag == ' ')
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(d, 1);
}
