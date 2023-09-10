/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:05:40 by mzurera-          #+#    #+#             */
/*   Updated: 2023/08/04 21:27:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	c_dest = (char *) dest;
	c_src = (char *) src;
	i = 0;
	while (i < n && c_src[i] != c)
	{
		c_dest[i] = c_src[i];
		++i;
	}
	if (c_src[i] == c)
	{
		c_dest[i] = c;
		return (&c_src[i + 1]);
	}
	return (NULL);
}
