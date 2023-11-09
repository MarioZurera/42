/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:18:53 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/24 19:47:29 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	contains_new_line(char *buffer, char **str)
{
	int		pos;
	int		new_len;
	char	*temp;

	pos = ft_strchr_index(str, '\n');
	new_len = ft_strlen(*str) - pos;
	if (pos != -1)
	{
		ft_strlcpy(buffer, ft_substr(*str, pos, new_len), new_len);
		temp = ft_substr(*str, 0, pos);
		if (temp == NULL)
			return (0);
		free(*str);
		*str = temp;
	}
	return (pos != 1);
}

static int	contains_null_character(char *buffer, char **str)
{
	int		pos;
	char	*temp;

	pos = ft_strlen(buffer);
	if (pos < BUFFER_SIZE)
	{
		buffer[0] = '\0';
		temp = ft_substr(*str, 0, pos);
		if (temp == NULL)
			return (0);
		free(*str);
		*str = temp;
	}
	return (pos < BUFFER_SIZE);
}

static int	read_line(char *buffer, char **str)
{
	int	bytes;

	if (buffer[0] == '\0')
		bytes = read(fd, &buffer, BUFFER_SIZE);
	else
		bytes = 1;
	while (bytes > 0)
	{
		str = ft_strjoin(str, buffer);
		if (contains_new_line(buffer, &str))
			break ;
		if (contains_null_character(buffer, &str))
			break ;
		bytes = read(fd, &buffer, BUFFER_SIZE);
	}
	return (bytes > 0);
}

unsigned int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str && str[length])
		++length;
	return (length);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	int			control;

	str = (char *) malloc(1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	control = read_line(buffer, &strs);
	if (!control)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	return (str);
}
