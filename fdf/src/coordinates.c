/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:46:31 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/23 13:01:21 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void rotate(int *x, int *y, double angle)
{
	int old_X;

	old_X = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_X * sin(angle) + *y * cos(angle);
}

t_coord	isometric_non_scaled(t_fdf *fdf, int x, int y, int z)
{
	t_coord	coords;

	rotate(&y, &z, M_PI / 2);
	// y /= (fdf->z_coords.y - fdf->z_coords.x);
	coords.x = ((sqrt(3) / sqrt(6)) * (x - z));
	coords.y = ((1 /sqrt(6)) * (x + 2 * y + z));
	coords.x -= fdf->min.x;
	coords.y -= fdf->min.y;
	return (coords);
}

t_coord	isometric_coordinates(t_fdf *fdf, int x, int y, int z)
{
	t_coord	coords;

	rotate(&y, &z, M_PI / 2);
	// y /= (fdf->z_coords.y - fdf->z_coords.x);
	if (fdf->scale.x == 0 || fdf->scale.y == 0)
		fdf->scale = (t_coord){1, 1};
	coords.x = ((sqrt(3) / sqrt(6)) * (x - z));
	coords.y = ((1 /sqrt(6)) * (x + 2 * y + z));
	coords.x -= fdf->min.x;
	coords.y -= fdf->min.y;
	coords.x *= fdf->scale.x;
	coords.y *= fdf->scale.y;
	coords.x += SCREEN_OFFSET_W;
	coords.y += SCREEN_OFFSET_H;
	coords.x = round(coords.x);
	coords.y = round(coords.y);
	if (coords.x < 0 || coords.y < 0 || coords.x > SCREEN_WIDTH - SCREEN_OFFSET_W || coords.y > SCREEN_HEIGHT - SCREEN_OFFSET_H)
		printf("x: %f, y: %f\n", coords.x, coords.y);
	return (coords);
}
