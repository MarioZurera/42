/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 04:06:32 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/10 18:22:46 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "list.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
	// Memory allocation functions.
*/
void	*ft_calloc(size_t num, size_t size);
/*
	// Memory functions.
*/
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memrcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/*
	// String functions.
*/
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *str, const char *substr);
char	*ft_strnstr(const char *str, const char *substr, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isblank(int c);
int		ft_isspace(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *s);
char	*ft_itoa(int n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_strdel(char *s, unsigned int start, unsigned int end);
/*
	// Stdout functions.
*/
void	ft_putchar(char c);
void	ft_putstr(const char *s);
void	ft_putnbr(int n);
void	ft_putendl(const char *s);
/*
	// File descriptor functions.
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(const char *s, int fd);

#endif /* LIBFT_H */
