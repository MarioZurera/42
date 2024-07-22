/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:58:23 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/22 13:18:09 by mzurera-         ###   ########.fr       */
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
	uint32_t	factor;

	if (coords->x < 0 || (size_t) coords->x >= fdf->width
		|| coords->y < 0 || (size_t) coords->y >= fdf->height)
		return ;
	if (fdf->z_coords.y != fdf->z_coords.x)
		factor = (height - fdf->z_coords.x) / (fdf->z_coords.y - fdf->z_coords.x);
	else
		factor = 0;
	color = ft_color_gradient(LOW_COLOR, HIGH_COLOR, factor);
	/*mlx_put_pixel(fdf->image, coords->x - 3, coords->y, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y, color);
	mlx_put_pixel(fdf->image, coords->x, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x - 3, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y + 1, color);
	mlx_put_pixel(fdf->image, coords->x, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x - 3, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y - 1, color);
	mlx_put_pixel(fdf->image, coords->x, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x - 3, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y + 2, color);
	mlx_put_pixel(fdf->image, coords->x, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x - 3, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y - 2, color);
	mlx_put_pixel(fdf->image, coords->x, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x - 3, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y + 3, color);
	mlx_put_pixel(fdf->image, coords->x, coords->y - 3, color);
	mlx_put_pixel(fdf->image, coords->x - 3, coords->y - 3, color);
	mlx_put_pixel(fdf->image, coords->x - 2, coords->y - 3, color);
	mlx_put_pixel(fdf->image, coords->x - 1, coords->y - 3, color);
	mlx_put_pixel(fdf->image, coords->x + 1, coords->y - 3, color);
	mlx_put_pixel(fdf->image, coords->x + 2, coords->y - 3, color);
	mlx_put_pixel(fdf->image, coords->x + 3, coords->y - 3, color);*/
	mlx_put_pixel(fdf->image, coords->x, coords->y, color);
}

void	ft_draw_line(t_fdf *fdf, t_draw_point *pA, t_draw_point *pB)
{
	double	num_pixels;
	double	deltaX;
	double	deltaY;
	double	pixelX;
	double	pixelY;

	deltaX = pB->coords.x - pA->coords.x;
	deltaY = pB->coords.y - pA->coords.y;
	num_pixels = round(sqrt((deltaX * deltaX) + (deltaY * deltaY)));
	deltaX /= num_pixels;
	deltaY /= num_pixels;
	pixelX = pA->coords.x;
	pixelY = pA->coords.y;
	while (num_pixels-- > 0)
	{
		// mlx_put_pixel(fdf->image, pixelX *30, pixelY*30, 0xFFFFFF);
		ft_draw_point(fdf, &(t_coord){pixelX, pixelY}, pA->z);
		pixelX += deltaX;
		pixelY += deltaY;
	}
}

/*
static int get_pixel(double i, double a, double b)
{
	int x = (round(((i / NUMBER_GRADIENT) * (b - a)) + a));
	return (x);
}

void	ft_draw_line(t_fdf *fdf, t_draw_point *pA, t_draw_point *pB)
{
	size_t	i;
	t_coord point;
	int		height;

	i = 0;
	while (i <= NUMBER_GRADIENT)
	{
		point.x = get_pixel(i, pA->coords.x, pB->coords.x);
		point.y = get_pixel(i, pA->coords.y, pB->coords.y);
		height = get_pixel(i, pA->z, pB->z);
		ft_draw_point(fdf, &point, height);
		i++;
	}
}
*/
