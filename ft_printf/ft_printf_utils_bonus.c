/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:06:42 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/22 18:06:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	eval_char(va_list arg, char *flg)
{
	unsigned char	c;
	int				i;
	int				n;

	i = 0;
	while (flg[i] && !ft_strchr(".#0+ ", flg[i]) && !ft_isdigit(flg[i]))
		i++;
	if (ft_strchr(".#0+ ", flg[i])
		return (-1);

	c = (unsigned char) va_arg(arg, int);

	ft_putchar_fd(c, 1);
	return (1);
}

int	eval_string(va_list arg)
{
	const char	*s;

	s = va_arg(arg, const char *);
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	else
	{
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
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
