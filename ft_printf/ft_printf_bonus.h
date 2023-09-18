/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:44:14 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/14 20:11:43 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

int		eval_conversion(const char *format, int pos, va_list arg);
char	eval_flag(const char *format, int *pos);

void	eval_char(va_list arg);
void	eval_string(va_list arg, char flag);
void	eval_pointer(va_list arg, char flag);
void	eval_decimal(va_list arg, char flag);
void	eval_unsigned(va_list arg, char flag);
void	eval_hexlow(va_list arg, char flag);
void	eval_hexup(va_list arg, char flag);

void	print_hex(long int addr, char letter);

#endif /* FT_PRINTF_BONUS_H */
