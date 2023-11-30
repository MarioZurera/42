/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:25:22 by mzurera-          #+#    #+#             */
/*   Updated: 2023/11/30 20:19:29 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct s_pipex {
	int		in_fd;
	int		out_fd;
	char	**cmd_paths;
	char	***cmd_args;
}	t_pipex;

/**
 * @brief Get the paths to the commands.
 * @param argc Number of arguments recieved by the program.
 * @param argv Name of the arguments, recieved by the program.
 * @param envp Enviroment variables in this terminal session.
*/
char	**ft_paths(int argc, char **argv, char **envp);

int		main(int argc, char **argv, char **envp);

#endif /* PIPEX_H */
