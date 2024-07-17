/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:25:22 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 15:41:10 by mzurera-         ###   ########.fr       */
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

typedef struct s_token
{
	char			*fullname;
	char			**args;
}	t_token;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	t_token	**tokens;
}	t_pipex;

/**
 * @brief Print n strings.
 * @param n_params Number of strings to be printed.
*/
void	print_error(unsigned int n_params, ...);

/**
 * @brief Get the fullname of the commands.
 * @param argv Name of the arguments, received by the program.
 * @param envp Environment variables in this terminal session.
 * @param NUM_COMMANDS Number of commands to be executed.
 * @return The absolute paths to the binaries of the commands.
*/
char	**ft_fullname(char **argv, char **envp, int NUM_COMMANDS);

/**
 * @brief Get the arguments of the commands.
 * @param argv Name of the arguments received by the program.
 * @param NUM_COMMANDS Number of commands to be executed.
 * @return An array with the arguments of the commands as a matrix per command.
*/
char	***ft_args(char **argv, int NUM_COMMANDS);

/**
 * @brief Initialize the pipex structure.
 * @param argv Name of the arguments received by the program.
 * @param envp Environment variables in this terminal session.
 * @param NUM_COMMANDS Number of commands to be executed.
 * @return A pointer to the pipex structure.
*/
t_pipex	*ft_init_pipex(char **argv, char **envp, int NUM_COMMANDS);

/**
 * @brief Free the pipex structure.
 * @param pipex The pipex structure to be freed.
*/
void	free_pipex(t_pipex **pipex);

int		main(int argc, char **argv, char **envp);

#endif /* PIPEX_H */
