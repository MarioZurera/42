/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:25:00 by mzurera-          #+#    #+#             */
/*   Updated: 2023/12/01 19:54:02 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_pipex(t_pipex **pipex)
{
	if (
		(*pipex)->in_fd == -1
		|| (*pipex)->out_fd == -1
		|| (*pipex)->cmd_paths == NULL
		|| (*pipex)->cmd_args == NULL
	)
	{
		ft_deep_free((void **)(*pipex)->cmd_paths, 2);
		ft_deep_free((void **)(*pipex)->cmd_args, 3);
		free(*pipex);
		*pipex = NULL;
	}
}

t_pipex	*ft_init_pipex(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = (t_pipex *) malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (NULL);
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->cmd_paths = ft_paths(argc, argv, envp);
	pipex->cmd_args = ft_args(argc, argv);
	check_pipex(&pipex);
	return (pipex);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 3)
		return (0);
	argv++;
	argc--;
	(void) envp;
	return (0);
}
