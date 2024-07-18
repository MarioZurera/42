/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:34:44 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/18 16:31:50 by mzurera-         ###   ########.fr       */
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

static void	print_error_fd(char *name)
{
	if (ft_strncmp(name, "pipe", 4) == 0)
		print_error(2, "pipex: cannot make pipe for process substitution: ",
			"Too many open files");
	else
		print_error(2, "pipex: redirection error: cannot duplicate fd:",
			" Too many open files");
}

static void	print_error_permissions(char *name)
{
	print_error(3, "pipex: ", name, ": Permission denied\n");
}

static void	print_error_command(char *name)
{
	if (ft_strchr(name, '/') != NULL)
		print_error(3, "pipex: ", name, ": No such file or directory\n");
	else
		print_error(3, "pipex: ", name, ": command not found\n");
}

void	print_error_code(char *name, int code, t_pipex *pipex)
{
	if (code == NO_CHILD_PROCESS)
		print_error(1, "pipex: fork: retry: No child processes");
	if (code == MANY_FD_OPEN)
		print_error_fd(name);
	if (code == PERMISSION_DENIED)
		print_error_permissions(name);
	if (code == COMMAND_NOT_FOUND || code == NO_FILE_OR_DIR)
		print_error_command(name);
	free_pipex(&pipex);
	exit(code);
}