/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:25:00 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 13:54:13 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	unsigned int NUM_COMMANDS;

	if (argc < 3)
		return (0);
	NUM_COMMANDS = (argc - 3);
	pipex = ft_init_pipex(argv, envp, NUM_COMMANDS);
	for (int i = 0; i < (int) NUM_COMMANDS; i++)
	{
		printf("Command %d:\n", i);
		printf("  Fullname: %s\n", pipex->tokens[i]->fullname);
		printf("  Args:\n");
		for (int j = 0; pipex->tokens[i]->args[j]; j++)
				printf("    %s\n", pipex->tokens[i]->args[j]);
	}
	ft_printf("%p\n", pipex);
	free_pipex(&pipex);
	return (0);
}
