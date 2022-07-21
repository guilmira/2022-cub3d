/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:25:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 10:39:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : 60 frames per second function. */
void	put_frame(t_prog *game)
{
	/* --------------------------------------------------------------- */
	/* --------------------------------------------------------------- */
	if (!game->minimap_state)
	{
		wash_screen(game, game->image[1], game->w1, BLACK);
	}
	wash_screen(game, game->image[0], game->w1, BLACK);
	if (game->minimap_state)
	{
		wash_screen(game, game->image[1], game->w2, RED);
		wash_screen(game, game->image[1], game->w2, BLACK);
	}
	if (game->minimap_state)
		framework_2D(game);
	mlx_image_to_window(game->mlx,\
	game->image[1], game->w2.origin[0], game->w2.origin[1]);	
}
