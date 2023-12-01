/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:25:00 by mzurera-          #+#    #+#             */
/*   Updated: 2023/12/01 17:30:50 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	***ft_cmd_args(int argc, char **argv)
{
	int		i;
	char	***cmd_args;

	cmd_args = (char ***) ft_calloc(argc - 1, sizeof(char **));
	if (cmd_args == NULL)
		return (NULL);
	i = 1;
	while (argv[i] != NULL && argv[i + 1] != NULL)
	{
		cmd_args[i - 1] = ft_split(argv[i], ' ');
		if (cmd_args[i - 1] == NULL)
		{
			ft_deep_free((void **) cmd_args, 3);
			return (NULL);
		}
		i++;
	}
	cmd_args[i - 1] = NULL;
	return (cmd_args);
}

void	check_pipex(t_pipex **pipex)
{
	if (
		pipex->in_fd == -1
		|| pipex->out_fd == -1
		|| pipex->cmd_paths == NULL
		|| pipex->cmd_args == NULL
	)
	{
		ft_deep_free((void **) pipex->cmd_paths, 2);
		ft_deep_free((void **) pipex->cmd_args, 3);
		free(pipex);
		pipex = NULL;
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
	pipex->cmd_args = ft_cmd_args(argc, argv);
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
