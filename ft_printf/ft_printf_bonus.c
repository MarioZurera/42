/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:16:58 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/22 02:20:28 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_strdelchr(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

static void	get_lengths(char *flags, int *length, int *precision)
{
	int	i;
	int	j;

	i = 0;
	while (flags[i] && !ft_isdigit(flags[i]) && !ft_strchr("0.", flags[i]))
		i++;
	j = i;
	if (ft_isdigit(flags[i]))
		*length = ft_atoi(&flags[i]);
	i += ft_nbrlen(*length);
	if (flags[i] == '.')
		*precision = ft_atoi(&flags[i + 1]);
	flags[j] = '\0';
}

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
	while (ft_isdigit(format[*pos])
		(*pos)++;
	if (!ft_strchr(conversion, format[*pos]))
		return (NULL);
	result = ft_substr(format, start, *pos - start);
	if (result == NULL)
		return (NULL);
	return (result);
}

static char	*format_flags(char *flags, int *length, int *precision)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (flags[i])
	{
		if (!ft_strnchr(flags, flags[i], j) || ft_isdigit(flags[i]))
		{
			flags[j] = flags[i];
			j++;
		}
		i++;
	}
	flags[j] = '\0';
	if (ft_strchr(flags, '0') && ft_strchr(flags, '-'))
		ft_strdelchr(flags, '0');
	if (ft_strchr(flags, ' ') && ft_strchr(flags, '+'))
		ft_strdelchr(flags, ' ');
	get_lengths(flags, length, precision);
	return (flags);
}

static char *eval_flags(const char *format, int *pos, int *length, int *prec)
{
	flags = get_flags(format, pos);
	if (flags == NULL)
		return (-1);
	flags = format_flags(flags, &length, &precision);
}

int	eval_conversion(const char *format, int *pos, va_list arg)
{
	int		printed_chars;
	char	*flags // Cambiar estas 3 variables por el struct t_flags;
	int	length;
	int	precision; // END

	flags = eval_flags(format, pos, &length, &precision);
	if (flags == NULL)
		return (-1);
	printed_chars = 0; 
	if (format[pos] == 'c') // printed_chars = print_conversion(format, *pos, arg, t_flags);
		printed_chars = eval_char(arg, flags, length, precision);
	else if (format[pos] == 's')
		printed_chars = eval_string(arg, flags, length, precision);
	else if (format[pos] == 'p')
		printed_chars = eval_pointer(arg, flags, length, precision);
	else if (format[pos] == 'd' || format[pos] == 'i')
		printed_chars = eval_decimal(arg, flags, length, precision);
	else if (format[pos] == 'u')
		printed_chars = eval_unsigned(arg, flags, length, precision);
	else if (format[pos] == 'x')
		printed_chars = eval_hexlow(arg, flags, length, precision);
	else if (format[pos] == 'X')
		printed_chars = eval_hexup(arg, flags, length, precision);
	else if (format[pos] == '%')
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
