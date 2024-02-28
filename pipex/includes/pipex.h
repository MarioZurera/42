/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:25:22 by mzurera-          #+#    #+#             */
/*   Updated: 2023/12/01 19:51:50 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	**cmd_paths;
	char	***cmd_args;
}	t_pipex;

/**
 * @brief Print n strings.
 * @param n_params Number of strings to be printed.
*/
void	print_error(unsigned int n_params, ...);

/**
 * @brief Get the paths to the commands.
 * @param argc Number of arguments recieved by the program.
 * @param argv Name of the arguments, recieved by the program.
 * @param envp Enviroment variables in this terminal session.
 * @return The absolute paths to the binaries of the commands.
*/
char	**ft_paths(int argc, char **argv, char **envp);

/**
 * @brief Get the arguments of the commands.
 * @param argc Number of arguments recieved by the program.
 * @param argv Name of the arguments recieved by the program.
 * @return An array with the arguments of the commands as a matrix per command.
*/
char	***ft_args(int argc, char **argv);

int		main(int argc, char **argv, char **envp);

#endif /* PIPEX_H */
