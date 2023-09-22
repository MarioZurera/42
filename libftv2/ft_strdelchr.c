/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:20:56 by mzurera-          #+#    #+#             */
/*   Updated: 2023/09/22 18:20:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelchr(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
