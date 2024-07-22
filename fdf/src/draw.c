/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:58:23 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/22 19:38:14 by mzurera-         ###   ########.fr       */
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

static void	ft_draw_point(t_fdf *fdf, t_coord *coords, int height)
{
	uint32_t	color;
	double		factor;

	if (coords->x < 0 || (size_t) coords->x >= fdf->width
		|| coords->y < 0 || (size_t) coords->y >= fdf->height)
		return ;
	if (fdf->z_coords.y != fdf->z_coords.x)
		factor = (height - fdf->z_coords.x) / (fdf->z_coords.y - fdf->z_coords.x);
	else
		factor = 0;
	color = ft_color_gradient(LOW_COLOR, HIGH_COLOR, factor);
	mlx_put_pixel(fdf->image, coords->x, coords->y, color);
}

void	ft_draw_line(t_fdf *fdf, t_draw_point *pA, t_draw_point *pB)
{
	double	num_pixels;
	double	deltaX;
	double	deltaY;
	double	deltaZ;

	deltaX = pB->coords.x - pA->coords.x;
	deltaY = pB->coords.y - pA->coords.y;
	deltaZ = pB->z - pA->z;
	num_pixels = round(sqrt((deltaX * deltaX) + (deltaY * deltaY)));
	deltaX /= num_pixels;
	deltaY /= num_pixels;
	deltaZ /= num_pixels;
	while (num_pixels-- > 0)
	{
		ft_draw_point(fdf, &pA->coords, pA->z);
		pA->coords.x += deltaX;
		pA->coords.y += deltaY;
		pA->z += deltaZ;
	}
}
