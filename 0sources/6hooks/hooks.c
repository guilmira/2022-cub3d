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

/** PURPOSE : manage keys. */
void	hk_keys(mlx_key_data_t key, void *game)
{
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(game);
}

/** PURPOSE : manage window closing or 
 * exiting with other widgets/tools. */
void	hk_close(void *game)
{
	clean_exit(game);
}

/** PURPOSE : Hook loop function. */
void next_frame(void *g)
{
	static int frame;
	t_prog *game;

	game = (t_prog *) g;
	
	frame++;
	//que haga barrido, asi veo el render
	wash_screen(game, game->image[1], game->w2, RED);
	wash_screen(game, game->image[1], game->w2, BLACK);
	framework_2D(game);
		game->pl.vis.x = frame * 0.01;
		game->pl.vis.y = 1;

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