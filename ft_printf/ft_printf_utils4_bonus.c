/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:55 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ignore_flags(char *flags)
{
	int	i;

	i = 0;
	while (flags[i] && (!ft_isdigit(flags[i])
			|| flags[i] == '0') && flags[i] != '.')
		i++;
	return (i);
}

void	add_n(int *n_print, int res)
{
	if (*n_print < 0 || res < 0)
		*n_print = -1;
	else
		*n_print += res;
}

void	print_sign(int d, int *n_print, int *n_print_unsign, char *flags)
{
	*n_print_unsign = *n_print;
	if (d < 0)
		add_n(n_print, ft_putchar_fd('-', 1));
	else if (ft_strchr(flags, '+') != 0)
		add_n(n_print, ft_putchar_fd('+', 1));
	else if (ft_strchr(flags, ' ') != 0)
		add_n(n_print, ft_putchar_fd(' ', 1));
}
