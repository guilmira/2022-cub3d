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

/** PURPOSE : manage window closing or 
 * exiting with other widgets/tools. */
static void	hk_close(void *game)
{
	clean_exit(game);
}

/** PURPOSE : Clear framework and create a new image to write pixels into. 
 * Window_number is either 0 for the 3D or 1 for the 2D
*/
void	frame_reset(int window_number, t_prog *game)
{
	if (window_number == 0)
	{
		ft_mlx_delete_image_safe(0, game);
		create_image(game, 0, game->w1.size);
	}
	else if (window_number == 1)
	{
		ft_mlx_delete_image_safe(1, game);
		create_image(game, 1, game->w2.size);
	}
}

void insta_player_vision(t_prog *game);
void	speed_testing(int frame, t_prog *game)
{
	if (frame == 150)
		clean_exit(game);
	insta_player_vision(game);
	if (frame == 0)
	{
	game->pl.vis.x = 1;
	game->pl.vis.y = 1;

	}
}


/** PURPOSE : Convert pointer of program and execute 60 times each second the frame. */
void next_frame(void *g)
{
	t_prog		*game;
	static int	frame;

	game = (t_prog *) g;

	//speed_testing(frame, game);
	
	if (game->pl.flag_movement)
	{
		printf("												FRAME: 	 %i\n", frame);
		frame++;
	
		/* if (game->minimap_state != FULL_MINIMAP)
		{
			frame_reset(0, game);
			put_frame3D(game);
		} */

		if (game->minimap_state)
		{
			frame_reset(1, game);
			put_frame2D(game);
		}
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