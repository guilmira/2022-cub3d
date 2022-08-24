/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:40:37 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 06:30:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Convert pointer of program and execute frames.
 * 60 FPS. */
void	next_frame(void *g)
{
	t_prog		*game;

	game = (t_prog *) g;
	if (game->pl.flag_movement)
	{
		reset_and_wash_frame(game);

		main_raycast_calculation(FOV_DEGREE, RAYCAST_OFFSET, game);
/* 		if (game->minimap_state != FULL_MINIMAP)
			put_frame3D(game); */
		if (game->minimap_state)
			put_frame2D(game);
		mlx_image_to_window(game->mlx, game->image[CUB_3D], \
		game->w1.origin[0], game->w1.origin[1]);
		game->pl.flag_movement = 0;
	}
}

/** PURPOSE : execute main routine of program.
 * mlx_loop and mlx_loop_hook will tried to be executed a total
 * of 60 times pers second. Therefore 60 fps. */
void	hooks_and_loops(t_prog *game)
{
	mlx_close_hook(game->mlx, &hk_close, (void *) game);
	mlx_key_hook(game->mlx, &hk_keys, game);
	mlx_loop_hook(game->mlx, &next_frame, game);
	mlx_loop(game->mlx);
}
