/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:36 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/14 20:14:55 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	eval_char(va_list arg)
{
	char	c;

	c = (char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
}

void	eval_string(va_list arg)
{
	char	*s;

	s = va_arg(arg, char *);
	ft_putstr_fd(s, 1);
}

void	eval_pointer(va_list arg)
{
	void			*ptr;
	unsigned long	addr;

	ptr = va_arg(arg, void *);
	addr = (unsigned long) ptr;
	print_hex(addr, 'A');
}

void	eval_decimal(va_list arg)
{
	int	d;

	d = va_arg(arg, int);
	ft_putnbr_fd(d, 1);
}

void	eval_unsigned(va_list arg)
{
	unsigned int	d;

	d = va_arg(arg, unsigned int);
	ft_putnbr_fd(d, 1);
}
