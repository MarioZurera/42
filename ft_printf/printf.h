#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		eval_conversion(const char *format, int pos, va_list arg);
char	eval_flag(const char *format, int *pos);

void	eval_char(const char *format, int pos, va_list arg, char flag);
void	eval_string(const char *format, int pos, va_list arg, char flag);
void	eval_pointer(const char *format, int pos, va_list arg, char flag);
void	eval_decimal(const char *format, int pos, va_list arg, char flag);
void	eval_unsigned(const char *format, int pos, va_list arg, char flag);
void	eval_hexlow(const char *format, int pos, va_list arg, char flag);
void	eval_hexup(const char *format, int pos, va_list arg, char flag);

void	print_hex(unsigned long addr, char letter);

#endif /* PRINTF_H */