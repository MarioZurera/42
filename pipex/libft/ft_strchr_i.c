/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:23:33 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/18 16:12:33 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchr_i(const char *s, int c)
{
	char	*res;

	res = ft_strchr(s, c);
	if (res == NULL)
		return (-1);
	return ((size_t)((size_t) res - (size_t) s));
}
