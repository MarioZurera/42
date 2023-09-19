/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:20 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/19 17:49:21 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	ft_printf(" %x %x %x %x %x %x %x \n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, (unsigned int) ULONG_MAX, 0, -42);
	printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, (unsigned int) LONG_MAX, (unsigned int) LONG_MIN, (unsigned int) ULONG_MAX, 0, -42);
	return (0);
}
