/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:39:22 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 16:50:29 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_color
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	uint8_t	alpha;
}	t_color;

static t_color	ft_hex_to_color(uint32_t hex)
{
	t_color	color;

	color.red = (uint8_t)(hex >> 24);
	color.green = (uint8_t)(hex >> 16);
	color.blue = (uint8_t)(hex >> 8);
	color.alpha = (uint8_t)(hex & 0xFF);
	return (color);
}

static uint32_t	ft_color_to_hex(t_color color)
{
	uint32_t	hex;

	hex = 0;
	hex |= color.red << 24;
	hex |= color.green << 16;
	hex |= color.blue << 8;
	hex |= color.alpha;
	return (hex);
}

uint32_t	ft_color_gradient(uint32_t hex1, uint32_t hex2, uint32_t factor)
{
	t_color	color;
	t_color	color2;

	if (factor > NUMBER_GRADIENT)
		factor = NUMBER_GRADIENT;
	color = ft_hex_to_color(hex1);
	color2 = ft_hex_to_color(hex2);
	color.red += ((color2.red - color.red) * factor / NUMBER_GRADIENT);
	color.green += ((color2.green - color.green) * factor / NUMBER_GRADIENT);
	color.blue += ((color2.blue - color.blue) * factor / NUMBER_GRADIENT);
	color.alpha += ((color2.alpha - color.alpha) * factor / NUMBER_GRADIENT);
	return (ft_color_to_hex(color));
}
