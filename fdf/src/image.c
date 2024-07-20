/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:02 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 20:38:44 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	isometric_coordinates(t_fdf *fdf, int x, int y, int z)
{
	t_coord	coords;
	t_coord scale;

	if (fdf->dims.x != 0 || fdf->dims.y != 0)
	{
		scale.x = ((fdf->width - (2 * SCREEN_OFFSET_W)) / fdf->dims.x);
		scale.y = ((fdf->height - (2 * SCREEN_OFFSET_H)) / fdf->dims.y);
	}
	else
	{
		scale.x = 1;
		scale.y = 1;
	}

	// Multiplied by 10 so it doesn't collide that much
	// TO-DO: look for a proper formula to get the correct scale for any given map
	// TO-DO: normalize the map to get lower slopes (max - min height)
	coords.x = ((sqrt(3) / sqrt(6)) * (x - z)) * scale.x;
	coords.y = ((1 /sqrt(6)) * (x + 2 * y + z)) * scale.y;
	coords.x += SCREEN_OFFSET_W;
	coords.y += SCREEN_OFFSET_H;
	return (coords);
}



static void	create_lines(t_fdf *fdf, size_t i, size_t j)
{
	t_draw_point	pA;
	t_draw_point	pB;

	pA.coords = isometric_coordinates(fdf, j, i, fdf->map[i][j]);
	pA.z = fdf->map[i][j];
	if (j < fdf->matrix_width - 1)
	{
		pB.coords = isometric_coordinates(fdf, j + 1, i, fdf->map[i][j + 1]);
		pB.z = fdf->map[i][j + 1];
		ft_draw_line(fdf, &pA, &pB);
	}
	if (i < fdf->matrix_height - 1)
	{
		pB.coords = isometric_coordinates(fdf, j, i + 1, fdf->map[i + 1][j]);
		pB.z = fdf->map[i + 1][j];
		ft_draw_line(fdf, &pA, &pB);
	}
}

static t_coord	get_height(t_fdf *fdf)
{
	t_coord	height;
	size_t i;
	size_t j;

	height.x = fdf->map[0][0];
	height.y = fdf->map[0][0];
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
		{
			height.x = ft_min(height.x, fdf->map[i][j]);
			height.y = ft_max(height.y, fdf->map[i][j]);
			j++;
		}
		i++;
	}
	return (height);
}

static t_coord	isometric_dimensions(t_fdf *fdf)
{
	size_t			i;
	size_t			j;
	t_coord			max;
	t_coord			coords;

	fdf->min = isometric_coordinates(fdf, 0, 0, fdf->map[0][0]);
	max.x = fdf->min.x;
	max.y = fdf->min.y;
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
		{
			coords = isometric_coordinates(fdf, j, i, fdf->map[i][j]);
			fdf->min.x = ft_min((int) fdf->min.x, (int) coords.x);
			fdf->min.y = ft_min((int) fdf->min.y, (int) coords.y);
			max.x = ft_max((int) max.x, (int) coords.x);
			max.y = ft_max((int) max.y, (int) coords.y);
			j++;
		}
		i++;
	}
	return ((t_coord){ft_max(max.x - fdf->min.x, 1), ft_max(max.y - fdf->min.y, 1)});
}

void	ft_process_image(t_fdf *fdf)
{
	size_t			i;
	size_t			j;

	ft_draw_background(fdf, BACKGROUND_COLOR);
	fdf->dims = isometric_dimensions(fdf);
	fdf->z_coords = get_height(fdf);
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
			create_lines(fdf, i, j++);
		i++;
	}
}
