/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:40:05 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/19 15:01:14 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			i;
} t_fdf;


void hook(void *data)
{
	t_fdf *fdf;

	fdf = (t_fdf *) data;
	if (fdf->i >= 1000)
		fdf->i = 0;
	// mlx_put_pixel(fdf->image, fdf->i, fdf->i, 0x999999);
	fdf->i++;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE)) exit(0);
}

int		main(int argc, char **argv, char **envp)
{
	t_fdf		fdf;

	(void) argc;
	(void) argv;
	(void) envp;
	fdf.mlx = mlx_init(1000, 1000, "FdF", false);
	fdf.image = mlx_new_image(fdf.mlx, 1000, 1000);
	fdf.i = 0;
	mlx_image_to_window(fdf.mlx, fdf.image, 0, 0);
	for (int i = 0; i < 1000; i++)
		mlx_put_pixel(fdf.image, i, i, 0x00FF00FF);
	mlx_loop_hook(fdf.mlx, hook, &fdf);
	mlx_loop(fdf.mlx);
	mlx_terminate(fdf.mlx);
	return (0);
}
