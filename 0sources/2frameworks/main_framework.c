/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_framework.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/13 16:58:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw 3D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Build cube. */
void	main_image_framework(t_prog *game)
{
	create_image(game, 0, game->w1.size);
	//cube3D(); TODO
	mlx_image_to_window(game->mlx, game->image[0], (int) game->w1.origin[0], (int) game->w1.origin[1]);
}


