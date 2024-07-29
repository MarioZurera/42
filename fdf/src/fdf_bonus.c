/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:09:28 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/29 20:15:49 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	resize_hook(int32_t width, int32_t height, void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) data;
	fdf->width = width;
	fdf->height = height;
	mlx_resize_image(fdf->image, width, height);
	ft_process_image(fdf);
}

static void	key_hook(mlx_key_data_t keydata, void *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) data;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_X)
		fdf->rotation.x = (int)(fdf->rotation.x + 1) % 4;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_Y)
		fdf->rotation.y = (int)(fdf->rotation.y + 1) % 4;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_Z)
		fdf->rotation.z = (int)(fdf->rotation.z + 1) % 4;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_UP)
		fdf->movement.y--;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_DOWN)
		fdf->movement.y++;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_RIGHT)
		fdf->movement.x++;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_LEFT)
		fdf->movement.x--;
}

static void	hook(void *data)
{
	t_fdf	*fdf;
	double	delta_time;

	fdf = (t_fdf *) data;
	gettimeofday(&fdf->t2, NULL);
	delta_time = (fdf->t2.tv_sec - fdf->t1.tv_sec) * 1000;
	delta_time += (fdf->t2.tv_usec - fdf->t1.tv_usec) / 1000;
	if (delta_time > 50)
	{
		gettimeofday(&fdf->t1, NULL);
		ft_process_image(fdf);
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_name>\n", argv[0]);
		exit(1);
	}
	fdf = ft_init_fdf(SCREEN_WIDTH, SCREEN_HEIGHT, true, argv[1]);
	ft_process_image(fdf);
	gettimeofday(&fdf->t1, NULL);
	mlx_resize_hook(fdf->mlx, &resize_hook, fdf);
	mlx_key_hook(fdf->mlx, &key_hook, fdf);
	mlx_loop_hook(fdf->mlx, &hook, fdf);
	mlx_loop(fdf->mlx);
	free_fdf(&fdf);
	return (0);
}
