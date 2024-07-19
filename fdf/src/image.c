/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:02 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/19 21:09:19 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	black_background(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			mlx_put_pixel(fdf->image, j, i, 0x000000FF);
			j++;
		}
		i++;
	}
}

static void	process_coordinate(t_coord *coords, int x, int y, int z)
{
	coords->x = round((sqrt(3) / sqrt(6)) * (x - z));
	coords->y = round((1 /sqrt(6)) * (x + 2 * y + z));
}

static t_coord	get_printed_dimensions(t_fdf *fdf)
{
	size_t			i;
	size_t			j;
	t_coord			min;
	t_coord			max;
	t_coord			coords;

	process_coordinate(&min, 0, 0, fdf->map[0][0]);
	max.x = min.x;
	max.y = min.y;
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
		{
			process_coordinate(&coords, j, i, fdf->map[i][j]);
			min.x = ft_min((int) min.x, (int) coords.x);
			min.y = ft_min((int) min.y, (int) coords.y);
			max.x = ft_max((int) max.x, (int) coords.x);
			max.y = ft_max((int) max.y, (int) coords.y);
			j++;
		}
		i++;
	}
	return ((t_coord){ft_max(max.x - min.x, 1), ft_max(max.y - min.y, 1)});
}

void	ft_process_image(t_fdf *fdf)
{
	size_t			i;
	size_t			j;
	t_coord	coords;
	t_coord	dimensions;

	black_background(fdf);
	dimensions = get_printed_dimensions(fdf);
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
		{
			process_coordinate(&coords, j, i, fdf->map[i][j]);
			coords.x *= ((fdf->width - (2 * SCREEN_OFFSET_W)) / dimensions.x);
			coords.y *= ((fdf->height - (2 * SCREEN_OFFSET_H)) / dimensions.y);
			coords.x += SCREEN_OFFSET_W;
			coords.y += SCREEN_OFFSET_H;
			mlx_put_pixel(fdf->image, coords.x, coords.y, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}
