/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:32:39 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/19 21:12:59 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/colors.h"
# include "../libft/libft.h"
# include <MLX42/MLX42.h>
# include <math.h>

/* To-Check libs */
# include <stdlib.h>
# include <fcntl.h>

/* CONSTANTS */
# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 1000
# define SCREEN_OFFSET_H 125
# define SCREEN_OFFSET_W 125


typedef enum e_error
{
	FDF_INIT_ERROR = 1,
	FDF_INVALID_MAP = 2
}	t_error;

typedef struct s_coord
{
	uint32_t	x;
	uint32_t	y;
}	t_coord;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				**map;
	size_t	width;
	size_t	height;
	size_t	matrix_width;
	size_t	matrix_height;
}	t_fdf;

/**
 * @brief Initialize the fdf structure
 * @param width The width of the window
 * @param height The height of the window
 * @param resize If the window can be resized
 * @param filename The name of the map file
 * @return The fdf structure
 * @note The fdf structure should be freed with free_fdf
*/
t_fdf	*ft_init_fdf(uint32_t width, uint32_t height,
			bool resize, const char *filename);

/**
 * @brief Free the fdf structure and all its internal elements
 * @param ptr_fdf The pointer to the fdf structure
*/
void	free_fdf(t_fdf **ptr_fdf);

/**
 * @brief Print the fdf map on the screen
 * @param fdf The fdf structure
*/
void	ft_process_image(t_fdf *fdf);

/**
 * @brief Print an error message, free the fdf structure and exit the program
 * @param code The error code
 * @param fdf The fdf structure
*/
void	print_error(t_error code, t_fdf *fdf, const char *msg);

int		main(int argc, char **argv);

#endif /* FDF_H */
