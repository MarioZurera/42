/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:16:32 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/23 13:21:41 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif /* BUFFER_SIZE */

# include <unistd.h>
# include <stdlib.h>

int				ft_strlcpy(char *dest, const char *src, unsigned int size);
int				ft_strlcat(char *dest, const char *src, unsigned int size);
char			*ft_strjoin(const char *s1, const char *s2);
int				ft_strchr_index(char *str, int c);
char			*ft_substr(const char *s, unsigned int start, unsigned int len);
unsigned int	ft_strlen(const char *str);
char			*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
