/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:19:02 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 15:54:32 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	isometric_coordinates(int x, int y, int z)
{
	t_coord	coords;

	z *= -1;
	coords.x = round((sqrt(3) / sqrt(6)) * (x - z));
	coords.y = round((1 /sqrt(6)) * (x + 2 * y + z));
	return (coords);
}



/*static void	create_connections(t_fdf *fdf, size_t i, size_t j)
{
	t_draw_point	p[2];

	p[0].coords = isometric_coordinates(j, i, fdf->map[i][j]);
	p[0].z = fdf->map[i][j];
	if (j < fdf->matrix_width - 1)
	{
		p[1].coords = isometric_coordinates(j + 1, i, fdf->map[i][j + 1]);
		p[1].z = fdf->map[i][j + 1];
		ft_draw_line(fdf, p);
	}
	if (i < fdf->matrix_height - 1)
	{
		p[1].coords = isometric_coordinates(j, i + 1, fdf->map[i + 1][j]);
		p[1].z = fdf->map[i + 1][j];
		ft_draw_line(fdf, p);
	}
}*/

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

	fdf->min = isometric_coordinates(0, 0, fdf->map[0][0]);
	max.x = fdf->min.x;
	max.y = fdf->min.y;
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
		{
			coords = isometric_coordinates(j, i, fdf->map[i][j]);
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
	t_coord	coords;

	ft_draw_background(fdf, BACKGROUND_COLOR);
	fdf->dims = isometric_dimensions(fdf);
	fdf->z_coords = get_height(fdf);
	ft_printf("height: %d, %d\n", fdf->z_coords.x, fdf->z_coords.y);
	i = 0;
	while (i < fdf->matrix_height)
	{
		j = 0;
		while (j < fdf->matrix_width)
		{
			// create_connections(fdf, i, j);
			coords = isometric_coordinates(j, i, fdf->map[i][j]);
			ft_draw_point(fdf, &coords, fdf->map[i][j]);
			j++;
		}
		i++;
	}
}
