/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:17:20 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 19:36:39 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	create_in_out_fd(t_pipex *pipex, char **argv, int NUM_COMMANDS)
{
	pipex->in_fd = open(argv[1], O_RDONLY);
	pipex->out_fd = open(argv[NUM_COMMANDS + 2],
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->in_fd < 0)
		print_error_file(argv[1]);
	if (pipex->out_fd < 0)
		print_error_file(argv[NUM_COMMANDS + 2]);
	if (pipex->in_fd < 0 || pipex->out_fd < 0)
	{
		free_pipex(&pipex);
		return (0);
	}
	return (1);
}

void	free_pipex(t_pipex **pipex)
{
	int	i;

	if (pipex == NULL || *pipex == NULL)
		return ;
	if ((*pipex)->tokens != NULL)
	{
		i = 0;
		while ((*pipex)->tokens[i] != NULL)
		{
			free((*pipex)->tokens[i]->fullname);
			ft_deep_free((void **) &(*pipex)->tokens[i]->args, 2);
			free((*pipex)->tokens[i]);
			i++;
		}
		free((*pipex)->tokens);
	}
	if ((*pipex)->in_fd < 0)
		close((*pipex)->in_fd);
	if ((*pipex)->out_fd < 0)
		close((*pipex)->out_fd);
	free((*pipex)->pids);
	free(*pipex);
	*pipex = NULL;
}

static void	ft_init_tokens(t_pipex **ptr_pipex, char **paths, char ***args)
{
	int		i;
	t_pipex	*pipex;

	pipex = *ptr_pipex;
	i = 0;
	while (paths[i] && args[i])
	{
		pipex->tokens[i] = (t_token *) malloc(sizeof(t_token));
		if (pipex->tokens[i] == NULL)
		{
			free_pipex(ptr_pipex);
			return ;
		}
		pipex->tokens[i]->fullname = paths[i];
		pipex->tokens[i]->args = args[i];
		pipex->tokens[i]->number = i;
		i++;
	}
	pipex->tokens[i] = NULL;
	free(paths);
	free(args);
}

t_pipex	*ft_init_pipex(char **argv, char **envp, int NUM_COMMANDS)
{
	t_pipex	*pipex;

	pipex = (t_pipex *) malloc(sizeof(t_pipex));
	if (pipex == NULL)
		return (NULL);
	pipex->pids = ft_calloc(NUM_COMMANDS + 1, sizeof(int));
	pipex->envp = envp;
	create_in_out_fd(pipex, argv, NUM_COMMANDS);
	pipex->tokens = (t_token **) ft_calloc(NUM_COMMANDS + 1, sizeof(t_token *));
	if (pipex->tokens == NULL)
	{
		free_pipex(&pipex);
		return (NULL);
	}
	ft_init_tokens(&pipex,
		ft_fullname(argv, envp, NUM_COMMANDS),
		ft_args(argv, NUM_COMMANDS)
		);
	return (pipex);
}
