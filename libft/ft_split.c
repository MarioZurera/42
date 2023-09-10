/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:12:14 by mzurera-          #+#    #+#             */
/*   Updated: 2023/08/04 21:27:39 by mzurera-         ###   ########.fr       */
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
	while (s[begin])
	{
		while (s[begin] && s[begin] == c)
			++begin;
		end = begin;
		while (s[end] && s[end] != c)
			++end;
		if (begin != end)
			strs[index++] = ft_substr(s, begin, end - begin);
		begin = end;
	}
	strs[index] = NULL;
	return (strs);
}
