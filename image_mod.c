/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:31:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/29 16:32:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : We pass the image as a poiinter to data.
 * Data has the location (first address in memory) of the space allocated for the image. 
 * This is data->addr. There, we calculate the offset, and write the colour in memory. This is, writing the pixel.
 * By calling this function several times, we are buiding in memory an image, that is only put to window afterwards. 
 * Result: is much faster than putting to window the pixels one by one. */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}