/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:34:44 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 19:35:20 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr_fd(buffer, STDERR_FILENO);
	free(buffer);
	va_end(args);
}

void	print_error_file(char *name)
{
	print_error(3, "pipex: ", name, ": No such file or directory\n");
}

void	print_error_command(char *name)
{
	print_error(2, name, ": command not found\n");
}

void	print_error_dup(void)
{
	print_error(2, "pipex: redirection error: cannot duplicate fd:",
		" Too many open files");
}

void	print_error_pipe(void)
{
	print_error(2, "pipex: cannot make pipe for process substitution: ",
		"Too many open files");
}
