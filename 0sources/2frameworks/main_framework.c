/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_framework.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 10:41:59 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw 3D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Build cube. */
void	main_image_framework(t_prog *game)
{
	//virtualize_3D();
	coor_identifier(game->image[0], game, 50, coor(50, game->w1.size[0]), game->w1.size[0]);
	mlx_image_to_window(game->mlx, game->image[0], (int) game->w1.origin[0], (int) game->w1.origin[1]);
}


