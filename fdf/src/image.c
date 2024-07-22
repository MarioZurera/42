/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:02 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/22 13:26:54 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	isometric_coordinates(t_fdf *fdf, int x, int y, int z)
{
	t_coord	coords;

	// printf("fdf->scale.x: %f\n", fdf->scale.x);
	// printf("fdf->scale.y: %f\n", fdf->scale.y);
	// Multiplied by 10 so it doesn't collide that much
	// TO-DO: look for a proper formula to get the correct scale for any given map
	// TO-DO: normalize the map to get lower slopes (max - min height)
	coords.x = ((sqrt(3) / sqrt(6)) * (x - z)) * fdf->scale.x;
	coords.y = ((1 /sqrt(6)) * (x + 2 * y + z)) * fdf->scale.y;
	// coords.x += SCREEN_OFFSET_W;
	// coords.y += SCREEN_OFFSET_H;
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

static t_coord	get_isometric_scale(t_fdf *fdf)
{
	int				i;
	int				j;
	t_coord			max;
	t_coord			coords;

	fdf->min = isometric_coordinates(fdf, 0, 0, fdf->map[0][0]);
	max.x = fdf->min.x;
	max.y = fdf->min.y;
	i = -1;
	while ((size_t)(++i) < fdf->matrix_height)
	{
		j = -1;
		while ((size_t)(++j) < fdf->matrix_width)
		{
			coords = isometric_coordinates(fdf, j, i, fdf->map[i][j]);
			fdf->min.x = ft_min((int) fdf->min.x, (int) coords.x);
			fdf->min.y = ft_min((int) fdf->min.y, (int) coords.y);
			max.x = ft_max((int) max.x, (int) coords.x);
			max.y = ft_max((int) max.y, (int) coords.y);
		}
	}
	printf("fdf->scale: %f, %f\n", fdf->scale.x, fdf->scale.y);
	printf("fdf->max.x: %f\n", max.x);
	printf("fdf->max.y: %f\n", max.y);
	coords.x = (fdf->width - SCREEN_OFFSET_W) / max.x;
	coords.y = (fdf->height - SCREEN_OFFSET_H) / max.y;
	printf("fdf->width: %f\n", coords.x);
	printf("fdf->height: %f\n", coords.y);
	return (coords);
}

void	ft_process_image(t_fdf *fdf)
{
	size_t			i;
	size_t			j;

	ft_draw_background(fdf, BACKGROUND_COLOR);
	fdf->scale = get_isometric_scale(fdf);
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
