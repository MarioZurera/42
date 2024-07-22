/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:44:26 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/22 19:04:52 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	**ft_lst_to_array(t_list *list, t_fdf *fdf)
{
	t_list	*temp;
	size_t	i;
	int		**matrix;

	i = 0;
	fdf->matrix_height = ft_lstsize(list);
	matrix = malloc((fdf->matrix_height + 1) * sizeof(int *));
	while (i < fdf->matrix_height)
	{
		matrix[i] = (int *) list->content;
		temp = list;
		list = list->next;
		free(temp);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

static int	*matrix_line(const char *line, size_t len)
{
	int		*nums;
	char	**words;
	size_t	i;

	if (line == NULL)
		return (NULL);
	nums = ft_calloc(len + 1, sizeof(int));
	words = ft_split(line, ' ');
	i = 0;
	while (i < len && words[i] != NULL)
	{
		nums[i] = ft_atoi(words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (nums);
}

static size_t	count_words(const char *line)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		count++;
		while (line[i] && line[i] != ' ')
			i++;
		while (line[i] == ' ')
			i++;
	}
	return (count);
}

static int	**ft_init_map(const char *filename, t_fdf *fdf)
{
	int		fd;
	char	*line;
	t_list	*list;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error(FDF_INVALID_MAP, fdf, filename);
	line = get_next_line(fd);
	if (line == NULL)
		print_error(FDF_INVALID_MAP, fdf, filename);
	fdf->matrix_width = count_words(line);
	list = ft_lstnew(matrix_line(line, fdf->matrix_width));
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(&list, ft_lstnew(matrix_line(line, fdf->matrix_width)));
	}
	close(fd);
	return (ft_lst_to_array(list, fdf));
}

t_fdf	*ft_init_fdf(uint32_t width, uint32_t height,
		bool resize, const char *filename)
{
	t_fdf	*fdf;
	int		res;

	fdf = ft_calloc(1, sizeof(t_fdf));
	if (fdf == NULL)
		print_error(FDF_INIT_ERROR, fdf, NULL);
	fdf->width = width;
	fdf->height = height;
	fdf->map = ft_init_map(filename, fdf);
	fdf->mlx = mlx_init(width, height, WINDOW_TITLE, resize);
	if (fdf->mlx == NULL)
		print_error(FDF_INIT_ERROR, fdf, NULL);
	fdf->image = mlx_new_image(fdf->mlx, width, height);
	if (fdf->image == NULL)
		print_error(FDF_INIT_ERROR, fdf, NULL);
	res = mlx_image_to_window(fdf->mlx, fdf->image, 0, 0);
	if (res < 0)
		print_error(FDF_INIT_ERROR, fdf, NULL);
	fdf->scale = (t_coord){1, 1};
	return (fdf);
}
