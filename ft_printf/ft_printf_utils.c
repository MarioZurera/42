#include "printf.h"

void	eval_char(const char *format, int pos, va_list arg, char flag)
{
	char	c;

	c = va_arg(arg, char);
	ft_putchar_fd(c, 1);
	return (pos + 1);
}

void	eval_string(const char *format, int pos, va_list arg, char flag)
{
	char	*s;

	s = va_arg(arg, char*);
	if (flag == ' ' && !*s)
		ft_putchar_fd(' ', 1);
	else
		ft_putstr_fd(s, 1);
	return (pos + 1);
}

void	eval_pointer(const char *format, int pos, va_list arg, char flag)
{
	void			*ptr;
	unsigned long	addr;
	char			hex;

	ptr = va_arg(arg, void*);
	addr = (unsigned long) ptr;
	if (flag == '+' && addr > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && addr > 0)
		ft_putchar_fd(' ', 1);
	print_hex(addr, 'A');
}

void	eval_decimal(const char *format, int pos, va_list arg, char flag)
{
	int	d;

	d = va_arg(arg, int);
	if (flag == '+' && d > 0)
		ft_putchar_fd('+', 1);
	if (flag == ' ' && d > 0)
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(d, 1);
	return (pos + 1);
}

void	eval_unsigned(const char *format, int pos, va_list arg, char flag)
{
	unsigned int	d;

	d = va_arg(arg, unsigned int);
	if (flag == '+')
		ft_putchar_fd('+', 1);
	if (flag == ' ')
		ft_putchar_fd(' ', 1);
	ft_putnbr_fd(d, 1);
	return (pos + 1);
}