/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:08:01 by mzurera-          #+#    #+#             */
/*   Updated: 2023/08/04 21:27:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	if (size < 1)
		return (src_len);
	if (size <= src_len)
		cpy_len = size - 1;
	else
		cpy_len = src_len;
	ft_memcpy(dest, src, cpy_len);
	dest[cpy_len] = '\0';
	return (src_len);
}
