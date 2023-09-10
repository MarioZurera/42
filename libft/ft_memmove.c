/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:06:03 by mzurera-          #+#    #+#             */
/*   Updated: 2023/08/04 21:27:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == dest)
		return (dest);
	if ((size_t)(dest - src) < n && src < dest)
	{
		i = dest - src;
		ft_memrcpy(dest + i, src + i, n - i);
		ft_memrcpy(dest, src, i);
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
