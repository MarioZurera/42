/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:23:33 by mzurera-          #+#    #+#             */
/*   Updated: 2023/11/30 21:20:27 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_i(const char *s, int c)
{
	char	*res;

	res = ft_strchr(s, c);
	if (res == NULL)
		return (-1);
	return ((size_t) ((size_t) ft_strchr(s, c) - (size_t) s));
}
