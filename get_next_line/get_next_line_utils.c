/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:36:00 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/24 20:05:29 by mzurera-         ###   ########.fr       */
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

int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	cat_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	if (dest_len + src_len < size)
		cat_len = src_len;
	else
		cat_len = size - dest_len - 1;
	ft_memcpy(dest + dest_len, src, cat_len);
	dest[dest_len + cat_len] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*str;
	unsigned int	length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc(sizeof(char) * length);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, length);
	ft_strlcat(str, s2, length);
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
