/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:25:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/19 14:13:18 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Is there os is there not a minimap. */
int is_minimap(t_prog *game)
{
	if (!game->minimap_state)
		return (0);
	else if (game->minimap_state == 2 || game->minimap_state == 4)
		return (1);
	else
		return (0);
}

/** PURPOSE : Correct minimap status and reset screen. */
static void correct_minimap_value(t_prog *game)
{
	game->minimap_state++;
	if (game->minimap_state == 6)
		game->minimap_state = 0;
}

/** PURPOSE : Correct minimap status and reset screen. */
void update_player_location(t_prog *game)
{
	game->pl.position_coor[0] = (double) (game->pl.position[0]) * game->map2D.pixel_per_block[0] + (game->map2D.pixel_per_block[0] / 2);
	game->pl.position_coor[1] = (double) (game->pl.position[1]) * game->map2D.pixel_per_block[1] + (game->map2D.pixel_per_block[1] / 2);
}

/** PURPOSE : Executed when hitting tab. It executes twice */
void	hook_control_minimap(t_prog *game)
{
		correct_minimap_value(game);
		if (is_minimap(game))
		{
			game->pl.flag_movement = 1;
			minimap_dimensions(game);
			update_pixel_per_block(game);
			update_player_location(game);
		}
}


/** PURPOSE : 60 frames per second function. 
 * pl.flag_movement deactivates in order to prevent drawing if there isnt changes in the game
*/
void	put_frame2D(t_prog *game)
{
	/* --------------------------------------------------------------- */
	/* --------------------------------------------------------------- */
	if (game->minimap_state)
	{
		framework_2D(game);
	}
	

/* 	t_vector ray;
	int i; 
	i = -1;
	while (++i < 250)
	{
		ray = game->rc->rc_vector[i];
		draw_vector(ray, game->pl.position_coor, RED, game);
	} */
}

