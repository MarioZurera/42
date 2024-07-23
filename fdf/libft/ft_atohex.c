/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:03:46 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/23 14:06:50 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atohex(char *s)
{
	if (s == NULL)
		return (0);
	if (s[0] == '0' && s[1] == 'x')
	{
		s += 2;
		return (ft_atoi_base(s, "0123456789abcdef"));
	}
	if (s[0] == '0' && s[1] == 'X')
	{
		s += 2;
		return (ft_atoi_base(s, "0123456789ABCDEF"));
	}
	return (ft_atoi_base(s, "0123456789ABCDEF"));
}