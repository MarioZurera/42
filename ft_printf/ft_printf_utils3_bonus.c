#include "ft_printf_bonus.h"

void	get_lengths(char *flags, va_list arg, int *length, int *prec)
{
	int	i;
	int	j;

	i = 0;
	while (flags[i] && !ft_isdigit(flags[i]) && !ft_strchr("0.", flags[i]))
		i++;
	j = i;
	if (ft_isdigit(flags[i]))
		*length = ft_atoi(&flags[i]);
	else if (flags[i] == '*')
		*length = va_arg(arg, int);
	i += ft_nbrlen(*length);
	if (flags[i] == '.')
	{
		++i;
		if (ft_isdigit(flags[i]))
			*prec = ft_atoi(&flags[i + 1]);
		else if (flags[i] == '*')
			*prec = va_arg(arg, int);
	}
	flags[j] = '\0';
}

int		print_conversion(const char *format, int *pos, va_list arg, t_conversion *flags)
{
    char    printed_chars;

    printed_chars = 0;
    if (format[*pos] == 'c')
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
	}
}