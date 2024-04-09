/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:38:19 by mzurera-          #+#    #+#             */
/*   Updated: 2023/12/01 20:04:44 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static unsigned int	ft_count_args(char *args)
{
	unsigned int	count;
	int				new_argument;

	count = 0;
	new_argument = 0;
	while (*args)
	{
		if (new_argument)
		{
			count++;
			new_argument = 0;
		}
		while (*args == ' ')
			args++;
		if (*args == 34 || *args == 39)
		{
			args += ft_strchr_i(args + 1, *args) + 1;
			new_argument = 1;
		}
		if (*args && *args != ' ')
			args++;
	}
	if (new_argument)
		count++;
	return (count);
}

static int	push_element(char **cmd_arg, char *args, int start, int len)
{
	unsigned int	pos;

	pos = 0;
	while (cmd_arg[pos] != NULL)
		pos++;
	cmd_arg[pos] = ft_substr(args, start, len);
	if (cmd_arg[pos] == NULL)
		ft_deep_free((void **) &cmd_arg, 2);
	return (cmd_arg[pos] != NULL);
}

static int	pass_quotes(char *args, int i)
{
	int		res;

	res = 0;
	if (args[i] == 34 || args[i] == 39)
		res = ft_strchr_i(&args[i + 1], args[i]);
	if (res < 0)
		res = 0;
	return (res);
}

static char	**ft_parse_args(char *args)
{
	char			**cmd_arg;
	unsigned int	i;
	unsigned int	len;
	unsigned int	temp;

	cmd_arg = ft_calloc(ft_count_args(args), sizeof(char *));
	if (cmd_arg == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (args[i])
	{
		if (args[i] == ' ' && len && !push_element(cmd_arg, args, i - len, len))
			return (NULL);
		if (args[i] == ' ' && len > 0)
			len = 0;
		while (args[i] == ' ')
			i++;
		temp = pass_quotes(args, i) + 1;
		i += temp;
		len += temp;
	}
	if (len > 0 && !push_element(cmd_arg, args, i - len, len))
		return (NULL);
	return (cmd_arg);
}

char	***ft_args(int argc, char **argv)
{
	int		i;
	char	***cmd_args;

	cmd_args = (char ***) ft_calloc(argc - 3, sizeof(char **));
	if (cmd_args == NULL)
		return (NULL);
	i = 0;
	while (argv[i + 1] != NULL && argv[i + 2] != NULL)
	{
		cmd_args[i] = ft_parse_args(argv[i + 2]);
		if (cmd_args[i] == NULL)
		{
			ft_deep_free((void **) &cmd_args, 2);
			return (NULL);
		}
		i++;
	}
	cmd_args[i] = NULL;
	return (cmd_args);
}
