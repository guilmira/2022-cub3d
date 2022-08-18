/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:48:19 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/18 11:00:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Raise 3D images.
 * 1. Build image.
 * 2. Put to window. */
void	put_frame3D(t_prog *game)
{
	(void) game;
	//virtualize_3D(game);
	wash_screen(game, game->image[CUB_3D], game->w1, RED);
	wash_screen(game, game->image[CUB_3D], game->w1, BLACK);
	int i;
	i = -1;
	while (++i < 900)
		solid_pixel(game->image[CUB_3D], 900, 600 + i, GREEN);
	mlx_image_to_window(game->mlx, game->image[CUB_3D], (int) game->w1.origin[0], (int) game->w1.origin[1]);

}