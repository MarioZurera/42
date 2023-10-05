/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:03 by mzurera-          #+#    #+#             */
/*   Updated: 2023/10/05 18:50:34 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_conversion
{
	char				*flags;
	unsigned int		length;
	int					precision;
}	t_conversion;

int		ft_printf(const char *format, ...);

int		eval_conversion(const char *format, int *pos, va_list arg);
int		eval_char(va_list arg, t_conversion *data);
int		eval_string(va_list arg, t_conversion *data);
int		eval_pointer(va_list arg, t_conversion *data);
int		eval_decimal(va_list arg, t_conversion *data);
int		eval_unsigned(va_list arg, t_conversion *data);
int		eval_hexlow(va_list arg, t_conversion *data);
int		eval_hexup(va_list arg, t_conversion *data);
int		eval_percentage(t_conversion *data);

int		print_hex(unsigned long int n, char letter);
void	get_lengths(char *flags, va_list arg, unsigned int *length, int *prec);
int		ft_conversion(const char *format, int *pos, va_list arg,
			t_conversion *data);
int		padding(int length, char c);
int		ft_hexlen(unsigned long n);
int		check_flags(char *flags, char *valid_flags);
int		ignore_flags(char *flags);
void	add_n(int *n_print, int res);
void	print_sign(int d, int *n_print, char *flags);
void	print_sign_u(int *n_print, char *flags);
int		has_sign(char *flags);
ssize_t write(int fd, const void *buf, size_t count);

#endif /* FT_PRINTF_BONUS_H */
