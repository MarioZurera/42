/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:34:44 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/17 16:12:10 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error(unsigned int n_params, ...)
{
	va_list	args;
	char	*buffer;
	char	*temp;

	va_start(args, n_params);
	buffer = ft_strdup("");
	while (n_params--)
	{
		temp = buffer;
		buffer = ft_strjoin(buffer, va_arg(args, char *));
		free(temp);
	}
	ft_putstr_fd(buffer, STDERR_FILENO);
	free(buffer);
	va_end(args);
}
