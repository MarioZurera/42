/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:39:22 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 15:15:13 by mzurera-         ###   ########.fr       */
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

uint32_t	ft_color_gradient(uint32_t hex1, uint32_t hex2, uint8_t factor)
{
	t_color	color1;
	t_color	color2;
	t_color	color;

	if (factor > 1)
		factor = 1;
	color1 = ft_hex_to_color(hex1);
	color2 = ft_hex_to_color(hex2);
	color.red = color1.red + ((color2.red - color1.red) * factor);
	color.green = color1.green + ((color2.green - color1.green) * factor);
	color.blue = color1.blue + ((color2.blue - color1.blue) * factor);
	color.alpha = color1.alpha + ((color2.alpha - color1.alpha) * factor);
	return (ft_color_to_hex(color));
}
