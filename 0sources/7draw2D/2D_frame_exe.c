/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:25:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 10:59:58 by guilmira         ###   ########.fr       */
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
void correct_minimap_value(t_prog *game)
{
	game->minimap_state++;
	if (game->minimap_state == 6)
	{
		wash_screen(game, game->image[1], game->w1, BLACK);
		game->minimap_state = 0;
	}
	
	
}
/** PURPOSE : Executed when hitting tab. It executes twice */
void	hook_control_minimap(t_prog *game)
{
		correct_minimap_value(game);
		if (is_minimap(game))
		{
			minimap_dimensions(game);
			if (game->minimap_state)
				create_image(game, 1, game->w2.size);
		}
}


/** PURPOSE : 60 frames per second function. */
void	put_frame(t_prog *game)
{
	/* --------------------------------------------------------------- */
	/* --------------------------------------------------------------- */
	/* if (!game->minimap_state)
	{
		wash_screen(game, game->image[1], game->w1, BLACK);
	}
	wash_screen(game, game->image[0], game->w1, BLACK); */

	if (game->minimap_state)
	{
		wash_screen(game, game->image[1], game->w2, RED);
		wash_screen(game, game->image[1], game->w2, BLACK);
		framework_2D(game);
	}
	mlx_image_to_window(game->mlx,\
	game->image[1], game->w2.origin[0], game->w2.origin[1]);	
}
