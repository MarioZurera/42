/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:13:46 by mzurera-          #+#    #+#             */
/*   Updated: 2023/12/01 17:28:38 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**ft_get_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*temp;

	while (*envp != NULL && ft_strncmp(*envp, "PATH=", 4) != 0)
		envp++;
	paths = ft_split((*envp) + ft_strlen("PATH="), ':');
	i = -1;
	while (paths[++i])
	{
		temp = paths[i];
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			paths[i] = ft_strjoin(paths[i], "/");
		free(temp);
		if (paths[i] == NULL)
			ft_deep_free((void **) &paths, 2);
	}
	return (paths);
}

/**
 * @brief Get the name of the commands.
 * @param argc Amount of parameters pass to the program.
 * @param argv The array of parameters pass to the program.
 * @return An array of strings with the name of the commands.
 * @note Take into consideration an argv with the program name,
 * and extra in/out files.
*/
static char	**ft_get_names(int argc, char **argv)
{
	int		i;
	int		j;
	char	**cmd_names;

	i = 0;
	j = 0;
	cmd_names = (char **) ft_calloc(argc - 3, sizeof(char *));
	if (cmd_names == NULL || argv[i] == NULL || argv[i + 1] == NULL)
		return (NULL);
	while (argv[i + 1] != NULL && argv[i + 2] != NULL)
	{
		while (ft_isspace(argv[i + 2][j]))
			j++;
		cmd_names[i] = ft_substr(argv[i + 2], j,
				ft_strchr_i(&argv[i + 2][j], ' '));
		if (cmd_names[i] == NULL)
		{
			ft_deep_free((void **) &cmd_names, 2);
			return (NULL);
		}
		i++;
	}
	cmd_names[i - 1] = NULL;
	return (cmd_names);
}

static char	*get_cmd_fullname(char *cmd_name, char **path)
{
	int		i;
	char	*fullname;

	i = 0;
	fullname = NULL;
	while (path[i] != NULL && fullname == NULL)
	{
		fullname = ft_strjoin(path[i], cmd_name);
		if (fullname == NULL)
			return (NULL);
		if (access(fullname, F_OK) == -1)
		{
			free(fullname);
			fullname = NULL;
		}
		i++;
	}
	if (fullname == NULL)
		fullname = "none";
	return (fullname);
}

static char	**ft_cmd_paths(int argc, char **cmd_names, char **path)
{
	int		i;
	char	**cmd_paths;

	cmd_paths = (char **) ft_calloc(argc - 3, sizeof(char *));
	if (cmd_names == NULL || path == NULL || cmd_paths == NULL)
	{
		ft_deep_free((void **) &cmd_names, 2);
		ft_deep_free((void **) &path, 2);
		return (free(cmd_paths), NULL);
	}
	i = -1;
	while (cmd_names[++i] != NULL)
	{
		cmd_paths[i] = get_cmd_fullname(cmd_names[i], path);
		if (ft_strncmp(cmd_paths[i], "none", 4) == 0)
			print_error(3, "pipex: ", cmd_names[i], ": command not found\n");
	}
	cmd_paths[i] = NULL;
	ft_deep_free((void **) &cmd_names, 2);
	ft_deep_free((void **) &path, 2);
	return (cmd_paths);
}

char	**ft_paths(int argc, char **argv, char **envp)
{
	return (ft_cmd_paths(argc, ft_get_names(argc, argv),
			ft_get_paths(envp)));
}
