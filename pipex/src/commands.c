/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:47 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 19:32:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	set_in_out(int input_fd, int output_fd)
{
	int	res;

	res = (dup2(input_fd, STDIN_FILENO) < 0
			|| dup2(output_fd, STDOUT_FILENO) < 0);
	close(input_fd);
	close(output_fd);
	if (!res)
		print_error_dup();
	return (res);
}

static void	exec_command(t_pipex *pipex, t_token *token, int pid, int *fd)
{
	if (pid < 0)
	{
		print_error(1, "Cannot create child process");
		free_pipex(&pipex);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	if (access(token->fullname, F_OK) == -1)
	{
		pipex->pids[token->number] = -1;
		if (ft_strchr(token->fullname, '/'))
			print_error_file(token->fullname);
		else
			print_error_command(token->fullname);
		return ;
	}
	if (pid == 0)
	{
		execve(token->fullname, token->args, pipex->envp);
	}
	if (pid > 0)
	{
		pipex->pids[token->number] = pid;
	}
}

static int	wait_commands(t_pipex *pipex)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (pipex->pids[i])
	{
		if (pipex->pids[i] == -1)
		{
			i++;
			continue ;
		}
		waitpid(pipex->pids[i], &status, 0);
		if (WIFEXITED(status))
			WEXITSTATUS(status);
		if (WIFSIGNALED(status))
		{
			WTERMSIG(status);
			status += 128;
		}
		i++;
	}
	return (status);
}

static void	create_pipe(int fd[2])
{
	if (pipe(fd) < 0)
		print_error_pipe();
	return (fd);
}

int	run_commands(t_pipex *pipex)
{
	int	i;
	int	fd[2];
	int	last_input;

	i = 0;
	last_input = pipex->in_fd;
	while (pipex->tokens[i])
	{
		create_pipe(fd);
		if (pipex->tokens[i + 1] == NULL)
		{
			close(fd[1]);
			fd[1] = pipex->out_fd;
		}
		set_in_out(last_input, fd[1]);
		exec_command(pipex, pipex->tokens[i], fork(), fd);
		close(last_input);
		last_input = dup(fd[0]);
		if (last_input < 0)
			print_error_dup();
		close(fd[0]);
		i++;
	}
	return (wait_commands(pipex));
}