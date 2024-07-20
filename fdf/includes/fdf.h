/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:32:39 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 15:54:10 by mzurera-         ###   ########.fr       */
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

/* COLORS */
# define HIGH_COLOR 0xFF0000FF
# define LOW_COLOR 0xFFFFFFFF
# define BACKGROUND_COLOR 0x000000FF

typedef enum e_error
{
	FDF_INIT_ERROR = 1,
	FDF_INVALID_MAP = 2
}	t_error;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_draw_point
{
	t_coord	coords;
	int		z;
}	t_draw_point;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	int				**map;
	size_t	width;
	size_t	height;
	size_t	matrix_width;
	size_t	matrix_height;
	t_coord dims;
	t_coord	z_coords;
	t_coord min;
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
 * @brief Get the color gradient with the specified factor
 * @param hex1 The low color
 * @param hex2 The high color
 * @param factor The factor to calculate the gradient, a number between 0 and 1
 * @return The color between hex1 and hex2 by a factor percentage
*/
uint32_t	ft_color_gradient(uint32_t hex1, uint32_t hex2, uint8_t factor);

/**
 * @brief Draw the screen background with the specified color
 * @param fdf The fdf structure
 * @param color The color to draw the background
 * @note The color should be in the format 0xRRGGBBAA
*/
void	ft_draw_background(t_fdf *fdf, uint32_t color);

/**
 * @brief Draw a point on the screen
 * @param fdf The fdf structure
 * @param coords The coordinates of the point in 2D representation
 * @param height The height of the point for the color gradient
*/
void	ft_draw_point(t_fdf *fdf, t_coord *coords, int height);

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
