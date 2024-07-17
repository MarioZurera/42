/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:17:20 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 14:57:53 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_pipex(t_pipex **pipex)
{
	int	i;

	if (pipex != NULL && *pipex != NULL && (*pipex)->tokens != NULL)
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
	pipex->tokens = (t_token **) malloc(sizeof(t_token *) * (NUM_COMMANDS + 1));
	if (pipex->tokens == NULL)
	{
		free_pipex(&pipex);
		return (NULL);
	}
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	ft_init_tokens(&pipex,
		ft_fullname(argv, envp, NUM_COMMANDS),
		ft_args(argv, NUM_COMMANDS)
		);
	return (pipex);
}
