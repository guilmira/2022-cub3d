/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_framework.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/06 16:33:33 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw 3D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Build cube. */
void	main_image_framework(t_prog *game, int size_x, int size_y)
{
	mlx_image_t	*image;

	image = mlx_new_image(game->mlx, size_x, size_y);
	if (!image)
		ft_shutdown(EX3, game);
	game->image[0] = image; 
	//cube3D(); TODO
	//testing:
	mlx_put_pixel(image, 1, 1, trgb_translate(0, 0, 255, 255));
	mlx_image_to_window(game->mlx, image, 0, 0);
}