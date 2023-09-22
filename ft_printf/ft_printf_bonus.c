/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:01:58 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/22 19:02:03 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*get_flags(const char *format, int *pos)
{
	char	*flags;
	char	*conversions;
	int		start;
	char	*result;

	conversions = "cspdiuxX%";
	flags = "-0# +";
	start = *pos;
	while (ft_strchr(flags, format[*pos]))
		(*pos)++;
	while (ft_isdigit(format[*pos]))
		(*pos)++;
	if (format[*pos] == '.')
		(*pos)++;
	while (ft_isdigit(format[*pos]))
		(*pos)++;
	if (!ft_strchr(conversions, format[*pos]))
		return (NULL);
	result = ft_substr(format, start, *pos - start);
	if (result == NULL)
		return (NULL);
	return (result);
}

static void	format_flags(t_conversion *data, va_list arg)
{
	int		i;
	int		j;
	char	*flg;

	i = 0;
	j = 0;
	flg = data->flags;
	while (flg[i])
	{
		if (ft_isdigit(flg[i]) || !ft_strnchr(flg, flg[i], j))
		{
			flg[j] = flg[i];
			j++;
		}
		i++;
	}
	flg[j] = '\0';
	if (ft_strchr(flg, '0') && ft_strchr(flg, '-'))
		ft_strdelchr(flg, '0');
	if (ft_strchr(flg, ' ') && ft_strchr(flg, '+'))
		ft_strdelchr(flg, ' ');
	get_lengths(flg, arg, &data->length, &data->precision);
}

static t_conversion	*eval_flags(const char *format, int *pos, va_list arg)
{
	t_conversion	*data;

	data = (t_conversion *) malloc(sizeof(t_conversion));
	if (data == NULL)
		return (NULL);
	data->flags = get_flags(format, pos);
	if (data->flags == NULL)
		return (NULL);
	format_flags(data, arg);
}

int	eval_conversion(const char *format, int *pos, va_list arg)
{
	int				printed_chars;
	t_conversion	*data;

	data = eval_flags(format, pos);
	if (data == NULL)
		return (-1);
	printed_chars = 0; 
	if (format[*pos] == 'c') // printed_chars = print_conversion(format, *pos, arg, t_flags);
		printed_chars = eval_char(arg, data);
	else if (format[*pos] == 's')
		printed_chars = eval_string(arg, data);
	else if (format[*pos] == 'p')
		printed_chars = eval_pointer(arg, data);
	else if (format[*pos] == 'd' || format[*pos] == 'i')
		printed_chars = eval_decimal(arg, data);
	else if (format[*pos] == 'u')
		printed_chars = eval_unsigned(arg, data);
	else if (format[*pos] == 'x')
		printed_chars = eval_hexlow(arg, data);
	else if (format[*pos] == 'X')
		printed_chars = eval_hexup(arg, data);
	else if (format[*pos] == '%')
	{
		++printed_chars;
		ft_putchar_fd('%', 1);
	} // END
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		printed_chars;
	int		pos;
	int		temp;

	va_start(arg, format);
	printed_chars = 0;
	pos = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			temp = eval_conversion(format, &(++pos), arg);
			if (temp < 0)
				return (-1);
			printed_chars += temp - 1;
		}
		else
			ft_putchar_fd(format[pos], 1);
		++printed_chars;
		++pos;
	}
	va_end(arg);
	return (printed_chars);
}
