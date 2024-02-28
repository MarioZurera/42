#include "../includes/pipex.h"

void	print_error(unsigned int n_params, ...)
{
	va_list	args;
	char	*buffer;
	char	*temp;

	va_start(args, n_params);
	buffer = ft_strdup("");
	while (n_params--)
	{
		temp = buffer;
		buffer = ft_strjoin(buffer, va_arg(args, char *));
		free(temp);
	}
	ft_putstr_fd(buffer, 1);
	free(buffer);
	va_end(args);
}
