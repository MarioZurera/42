/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:55 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/25 13:55:56 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

int		eval_conversion(const char *format, int pos, va_list arg);

int		eval_char(va_list arg);
int		eval_string(va_list arg);
int		eval_pointer(va_list arg);
int		eval_decimal(va_list arg);
int		eval_unsigned(va_list arg);
int		eval_hexlow(va_list arg);
int		eval_hexup(va_list arg);

int		print_hex(unsigned long int addr, char letter);

#endif /* FT_PRINTF_H */
