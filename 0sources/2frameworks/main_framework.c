/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_framework.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/07 14:13:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw 3D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Build cube. */
void	main_image_framework(t_prog *game)
{
	mlx_image_t	*image;

	image = mlx_new_image(game->mlx, (int) game->w1.size[0], (int) game->w1.size[1]);
	if (!image)
		ft_shutdown(EX3, game);
	game->image[0] = image; 
	//cube3D(); TODO
	//testing:
	mlx_image_to_window(game->mlx, image, (int) game->w1.origin[0], (int) game->w1.origin[1]);

}