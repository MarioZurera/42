/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzurera- <mzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 17:46:31 by mzurera-          #+#    #+#             */
/*   Updated: 2024/07/20 17:48:24 by mzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_coord	isometric_coordinates(int x, int y, int z)
{
	t_coord	coords;

	// Multiplied by 10 so it doesn't collide that much
	// TO-DO: look for a proper formula to get the "10" for any given map
	// TO-DO: normalize the map to get lower slopes (max - min height)
	coords.x = round((sqrt(3) / sqrt(6)) * (x - z) * 10);
	coords.y = round((1 /sqrt(6)) * (x + 2 * y + z) * 10);
	return (coords);
}

t_coord	isometric_coordinates(t_fdf fdf, int x, int y, int z)
{
	t_coord	coords;

	// Multiplied by 10 so it doesn't collide that much
	// TO-DO: look for a proper formula to get the "10" for any given map
	// TO-DO: normalize the map to get lower slopes (max - min height)
	coords.x = round((sqrt(3) / sqrt(6)) * (x - z) * (fdf->width - (2 * SCREEN_OFFSET_W))<;
	coords.y = round((1 /sqrt(6)) * (x + 2 * y + z) * 10);
	return (coords);
}*/