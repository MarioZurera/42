/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:33:20 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/05 18:58:41 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf_bonus.h"

ssize_t write(int fd, const void *buf, size_t count)
{
	static int i;

	if (i++ > 1) // Works with > 17
		return (-1);
	return (1);
}

int	main(void)
{
	printf("RESULT: %d", ft_printf("%-5c, %-5c, %-5c", '5', 'x', '\n'));
	os.system("leaks");
	return (0);
}
