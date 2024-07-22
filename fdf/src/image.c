/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:02 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/22 18:59:39 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static t_coord	get_min_coords(t_fdf *fdf)
{
	int				i;
	int				j;
	t_coord			min;
	t_coord			coords;

	min = isometric_non_scaled(fdf, 0, 0, fdf->map[0][0]);
	i = -1;
	while ((size_t)(++i) < fdf->matrix_height)
	{
		j = -1;
		while ((size_t)(++j) < fdf->matrix_width)
		{
			coords = isometric_non_scaled(fdf, j, i, fdf->map[i][j]);
			min.x = ft_mind(min.x, coords.x);
			min.y = ft_mind(min.y, coords.y);
		}
	}
	return (min);

}

static t_coord	get_isometric_scale(t_fdf *fdf)
{
	int				i;
	int				j;
	t_coord			max;
	t_coord			coords;

	max = isometric_non_scaled(fdf, 0, 0, fdf->map[0][0]);;
	i = -1;
	while ((size_t)(++i) < fdf->matrix_height)
	{
		j = -1;
		while ((size_t)(++j) < fdf->matrix_width)
		{
			coords = isometric_non_scaled(fdf, j, i, fdf->map[i][j]);
			max.x = ft_maxd(max.x, coords.x);
			max.y = ft_maxd(max.y, coords.y);
		}
	}
	/*
		(iso + OFF) * X = fdf->width - OFF
	*/
	coords.x = (fdf->width - (2 * SCREEN_OFFSET_W)) / max.x;
	coords.y = (fdf->height - (2 * SCREEN_OFFSET_H)) / max.y;
	printf("max.x: %f, max.y: %f\n", max.x, max.y);
	printf("coords.x: %f, coords.y: %f\n", coords.x, coords.y);
	return (coords);
	// return ((t_coord){ft_mind(coords.x, coords.y), ft_mind(coords.x, coords.y)});
}

void	ft_process_image(t_fdf *fdf)
{
	size_t			i;
	size_t			j;

	ft_draw_background(fdf, BACKGROUND_COLOR);
	fdf->z_coords = get_height(fdf);
	fdf->min = get_min_coords(fdf);
	fdf->scale = get_isometric_scale(fdf);
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
			create_lines(fdf, i, j++);
		i++;
	}
}
