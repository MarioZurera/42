/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:04:55 by mzurera-          #+#    #+#             */
/*   Updated: 2023/08/04 21:27:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	max_len;
	size_t	size;

	max_len = ft_strlen(s);
	max_len -= ft_min_size(max_len, start);
	size = ft_min_size(len, max_len) + 1;
	substr = (char *) malloc(size);
	if (substr == NULL)
		return (NULL);
	if (size > 1)
		ft_strlcpy(substr, s + start, size);
	else
		substr[0] = '\0';
	return (substr);
}
