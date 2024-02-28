/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deep_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:19:56 by mzurera-          #+#    #+#             */
/*   Updated: 2023/11/27 19:19:57 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deep_free(void **ptr, unsigned int depth)
{
	int		i;
	void	**mem;

	i = 0;
	mem = *ptr;
	if (mem == NULL)
		depth = 0;
	while (depth > 1 && mem[i] != NULL)
	{
		if (depth > 2)
			ft_deep_free((void **) mem[i], depth - 1);
		free(mem[i]);
		i++;
	}
	if (depth > 0)
		free(mem);
	*ptr = NULL;
}
