#include "../includes/pipex.h"

static char	**ft_get_paths(char **envp)
{
	char	**paths;

	while (*envp != NULL && ft_strncmp(*envp, "PATH=", 4) != 0)
		envp++;
	(*envp) += ft_strlen("PATH=");
	return (ft_split(*envp, ':'));
}

static char	**ft_get_names(int argc, char **argv)
{
	int		i;
	int		j;
	char	**cmd_names;

	i = 1;
	j = 0;
	cmd_names = (char **) ft_calloc(argc - 1, sizeof(char *));
	if (cmd_names == NULL)
		return (NULL);
	while (argv[i] != NULL && argv[i + 1] != NULL)
	{
		while (ft_isspace(argv[i][j]))
			j++;
		cmd_names[i - 1] = ft_substr(argv[i], j, ft_strchr(&argv[i][j], ' '));
		if (cmd_names[i - 1] == NULL)
			return (ft_free_strs(cmd_names, 2), NULL);
		i++;
	}
	cmd_names[i - 1] = NULL;
	return (cmd_names);
}

static char	*get_cmd_fullname(char *cmd_name, char **path)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	while (path[i] != NULL && cmd_path == NULL)
	{
		cmd_path = ft_strjoin(cmd_path, cmd_name);
		if (access(cmd_path, F_OK) == -1)
		{
			free(cmd_path);
			cmd_path = NULL;
		}
		i++;
	}
	return (cmd_path);
}

static char	**ft_cmd_paths(int argc, char **cmd_names, char **path)
{
	int		i;
	char	**cmd_paths;

	cmd_paths = (char **) ft_calloc(argc - 1, sizeof(char*));
	if (cmd_names == NULL || path == NULL || cmd_paths == NULL)
	{
		ft_free_strs(cmd_names, 2);
		ft_free_strs(path, 2);
		return (free(cmd_paths), NULL);
	}
	i = -1;
	while (cmd_names[++i] != NULL)
	{
		cmd_paths[i] = get_cmd_fullpath(cmd_names[i], path);
		if (cmd_paths[i] == NULL)
		{
			ft_free_strs(cmd_paths, 2);
			cmd_paths = NULL;
			break ;
		}
	}
	cmd_paths[i] = NULL;
	ft_free_strs(cmd_names, 2);
	ft_free_strs(path, 2);
	return (cmd_paths);
}

char	**ft_paths(int argc, char **argv, char **envp)
{
	return (ft_cmd_paths(argc, ft_get_names(argc, argcv),
				ft_get_paths(envp));
}
