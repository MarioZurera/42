/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:58:23 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 15:58:53 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_background(t_fdf *fdf, uint32_t color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			mlx_put_pixel(fdf->image, j, i, color);
			j++;
		}
		i++;
	}
}

static void calculate_coords(t_fdf *fdf, t_coord *coords)
{
	int	h;

	h = 0;
	if (fdf->min.x < 0)
	{
		h = fdf->min.x;
		h *= -1;
		if (h < 0)
			return ;
		coords->x += h;
	}
	if (fdf->min.y < 0)
	{
		h = fdf->min.y;
		h *= -1;
		if (h < 0)
			return ;
		coords->y += h;
	}
	coords->x *= ((fdf->width - (2 * SCREEN_OFFSET_W)) / fdf->dims.x);
	coords->y *= ((fdf->height - (2 * SCREEN_OFFSET_H)) / fdf->dims.y);
	coords->x += SCREEN_OFFSET_W;
	coords->y += SCREEN_OFFSET_H;
}

void	ft_draw_point(t_fdf *fdf, t_coord *coords, int height)
{
	uint32_t	color;
	uint32_t	factor;

	if (coords->x < 0 && (size_t) coords->x >= fdf->width
		&& coords->y < 0 && (size_t) coords->y >= fdf->height)
		return ;
	calculate_coords(fdf, coords);
	if (fdf->z_coords.y != fdf->z_coords.x)
		factor = (height - fdf->z_coords.x) / (fdf->z_coords.y - fdf->z_coords.x);
	else
		factor = 1;
	color = ft_color_gradient(LOW_COLOR, HIGH_COLOR, factor);
	mlx_put_pixel(fdf->image, coords->x, coords->y, color);
}

void	ft_draw_line()
{
	
}
