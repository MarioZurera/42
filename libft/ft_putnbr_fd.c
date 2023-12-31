/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:22:46 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/12 19:22:47 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_putnbr_fd(int n, int fd)
{
	if (n <= -10 || n >= 10)
		recursive_putnbr_fd(n / 10, fd);
	if (n < 0)
		ft_putchar_fd(((n % 10) * -1) + '0', fd);
	else
		ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	recursive_putnbr_fd(n, fd);
}
