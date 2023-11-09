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

	pos = ft_strchr_index(*str, '\n');
	new_len = ft_strlen(*str) - pos;
	if (pos != -1)
	{
		temp = ft_substr(*str, pos, new_len);
		ft_strlcpy(buffer, temp, new_len);
		free(temp);
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

static int	read_line(int fd, char *buffer, char **str)
{
	int		bytes;
	char	*temp_str;

	if (buffer[0] == '\0')
		bytes = read(fd, &buffer, BUFFER_SIZE);
	else
		bytes = ft_strlen(buffer);
	while (bytes > 0)
	{
		temp_str = (char *) malloc(bytes + ft_strlen(*str) + 1);
		if (temp_str == NULL)
			return (0);
		free(*str);
		*str = temp_str;
		ft_strlcpy(str, s1, length);
		ft_strlcat(str, s2, length);
		
		if (temp_str == NULL)
			return (0);
		*str = temp_str;
		if (contains_new_line(buffer, str))
			break ;
		if (contains_null_character(buffer, str))
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
	/*char		*temp_str;*/

	str = (char *) malloc(1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	control = read_line(fd, buffer, &str);
	if (!control)
	{
		buffer[0] = '\0';
		free(str);
		return (NULL);
	}
	/*temp_str = ft_strjoin(str, "\n");
	free(str);
	if (temp_str == NULL)
		return (0);
	str = temp_str;*/
	return (str);
}
