/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:20 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 14:52:47 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	b;

	a = printf("%02d", 0);
	printf("\n");
	printf("%d\n", a);
	b = ft_printf("%02d", 0);
	ft_printf("\n");
	ft_printf("%d\n", a);
	return (0);
}
