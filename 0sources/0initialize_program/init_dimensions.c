/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dimensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:10:11 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/05 10:20:55 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : calculate unit of measure for each framework. */
static double	window_unit(double size, double divisor)
{
	return ( size / divisor);
}

/** PURPOSE : copy struct. */
static t_dim copy_dim_struct(t_dim window_src)
{
	t_dim win_return;

	win_return.origin[0] = window_src.origin[0];
	win_return.origin[1] = window_src.origin[1];
	win_return.size[0] = window_src.size[0];
	win_return.size[1] = window_src.size[1];
	win_return.unit[0] = window_src.unit[0];
	win_return.unit[1] = window_src.unit[1];
	return (win_return);
}



/** PURPOSE : used to recalculate minimap dimensions.
 * EXPLANATION - limit and size are the same, but calculated int two ways. */
void	minimap_dimensions(t_prog *game)
{
	if (!game->minimap_state)
		return ;
	else if (game->minimap_state == 2)
	{
		game->w2.origin[0] = (double) game->w1.origin[0] + game->w1.unit[0] * OX_CORNER_WINDOW_DESPLACEMENT;
		game->w2.origin[1] = (double) game->w1.origin[1] + game->w1.unit[1] * OY_CORNER_WINDOW_DESPLACEMENT;
		game->w2.size[0] = (double) (game->w1.size[0] - OX_CORNER_WINDOW_FACTOR * game->w1.unit[0]) ;
		game->w2.size[1] = (double) (game->w1.size[1] - OY_CORNER_WINDOW_FACTOR * game->w1.unit[1]);
		if (game->w2.size[0] - game->w2.origin[0] > game->w1.size[0] \
		|| game->w2.size[1] - game->w2.origin[1] > game->w1.size[1])
			ft_shutdown("Error.\nMinimap to big\n", game);
		game->w2.unit[0] = window_unit(game->w2.size[0], game->map2D.width);
		game->w2.unit[1] = window_unit(game->w2.size[1], game->map2D.height);
	}
	else
		game->w2 = copy_dim_struct(game->w1);
}


#define SPACES_AT_BORDER 2

/** PURPOSE : calculate main window and minimap dimensions. */
void	framework_dimensions(t_prog *game)
{
	int help[2];

	game->map2D.width = game->map2D.map_x + SPACES_AT_BORDER;
	game->map2D.height = game->map2D.map_y + SPACES_AT_BORDER;
	/* --------------------------------------------------------------- */
	game->w1.origin[0] = 0;
	game->w1.origin[1] = 0;
	game->w1.size[0] = OX_WINDOW;
	game->w1.size[1] = OY_WINDOW;
	game->w1.unit[0] = window_unit(game->w1.size[0], game->map2D.width);
	game->w1.unit[1] = window_unit(game->w1.size[1], game->map2D.height);
	/* --------------------------------------------------------------- */
	minimap_dimensions(game);
	/* --------------------------------------------------------------- */

	/* --------------------------------------------------------------- */
	help[0] = (int)((game->w2.size[0]) / (game->map2D.width));
	help[1] = (int)((game->w2.size[1]) / (game->map2D.height));
	/* --------------------------------------------------------------- */

/* 	if (help[0] > help[1])
	{ */
		game->map2D.pixel_per_block[0] = help[0];
		game->map2D.pixel_per_block[1]  = help[1];
	//}
/* 	else
	{
		game->map2D.pixel_per_block[0] = help[0];
		game->map2D.pixel_per_block[1] = help[0];
	} */
}