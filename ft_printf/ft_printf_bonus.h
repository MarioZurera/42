/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:03 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:56:04 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_conversion
{
	char	*flags;
	int		length;
	int		precision;
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

void	print_hex(unsigned long int addr, char letter);
void	get_lengths(char *flags, va_list arg, int *length, int *prec);
int		ft_conversion(const char *format, int *pos, va_list arg,
			t_conversion *data);
int		padding(int length, char c);
int		ft_hexlen(unsigned long int addr);
int		check_flags(char *flags, char *valid_flags);

#endif /* FT_PRINTF_BONUS_H */
