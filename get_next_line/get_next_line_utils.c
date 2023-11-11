/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:36:00 by mzurera-          #+#    #+#             */
/*   Updated: 2023/11/10 20:00:59 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	char			*c_dest;
	char			*c_src;
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	c_dest = (char *) dest;
	c_src = (char *) src;
	i = 0;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		++i;
	}
	return (dest);
}

int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	cpy_len;

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

char	*ft_strjoin(const char *s1, const char *s2, unsigned int extra_size)
{
	char			*str;
	unsigned int	length;
	unsigned int	dest_len;
	unsigned int	cat_len;

	length = ft_strlen(s1) + ft_strlen(s2) + extra_size;
	str = (char *) malloc(sizeof(char) * length);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, length);
	free((char *) s1);
	dest_len = ft_strlen(str);
	if (dest_len + ft_strlen(s2) < length)
		cat_len = ft_strlen(s2);
	else
		cat_len = length - dest_len - 1;
	ft_memcpy(str + dest_len, s2, cat_len);
	str[dest_len + cat_len] = '\0';
	return (str);
}

int	ft_strchr_index(char *str, int c)
{
	char	*s;

	s = str;
	c %= 128;
	while (*s && *s != c)
		++s;
	if (*s != c)
		return (-1);
	return ((unsigned long) s - (unsigned long) str);
}

char	*ft_substr(const char *s, unsigned int start, unsigned int len)
{
	char			*substr;
	unsigned int	max_len;
	unsigned int	size;

	if (ft_strlen(s) < start)
		max_len = 0;
	else
		max_len = ft_strlen(s) - start;
	if (len < max_len)
		size = len + 1;
	else
		size = max_len + 1;
	substr = (char *) malloc(size);
	if (substr == NULL)
		return (NULL);
	if (size > 1)
		ft_strlcpy(substr, s + start, size);
	else
		substr[0] = '\0';
	return (substr);
}
