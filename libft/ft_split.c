/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:23:26 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/13 13:35:53 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strs_len(const char *s, char c)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		if (s[i] && s[i] != c)
			++length;
		while (s[i] && s[i] != c)
			++i;
	}
	return (length);
}

static void	ft_strclear(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	int		begin;
	int		end;
	int		index;

	strs = (char **) malloc((ft_strs_len(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	index = 0;
	begin = 0;
	end = 0;
	while (s[end] && (begin = end))
	{
		while ((s[begin] && s[begin] == c) || ((end = begin) && 0))
			++begin;
		while (s[end] && s[end] != c)
			++end;
		if (begin != end)
			strs[index++] = ft_substr(s, begin, end - begin);
		if (strs[index - 1] == NULL)
			return (ft_strclear(strs), NULL);�
	}
	strs[index] = NULL;
	return (strs);
}
