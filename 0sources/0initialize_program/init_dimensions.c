/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dimensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:10:11 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 11:46:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : calculate boundry condition for framework. */
static double	window_limit(double origin, double total_size)
{
	return (total_size - origin);
}

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
	win_return.limit[0] = window_src.limit[0];
	win_return.limit[1] = window_src.limit[1];
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
		game->w2.limit[0] = window_limit(game->w2.origin[0], game->w1.size[0]); //has to be window 1
		game->w2.limit[1] = window_limit(game->w2.origin[1], game->w1.size[1]);
		if (game->w2.limit[0] > OX_WINDOW || game->w2.limit[1] > OY_WINDOW)
			ft_shutdown("Error.\nMinimap to big\n", game);
		game->w2.unit[0] = window_unit(game->w2.size[0], OX_DIV);
		game->w2.unit[1] = window_unit(game->w2.size[1], OY_DIV);
	}
	else
		game->w2 = copy_dim_struct(game->w1);
}

/** PURPOSE : calculate main window and minimap dimensions. */
void	framework_dimensions(t_prog *game)
{
	game->w1.origin[0] = 0;
	game->w1.origin[1] = 0;
	game->w1.size[0] = OX_WINDOW;
	game->w1.size[1] = OY_WINDOW;
	//limit is the OVERALL LIMIT COORDINATE
	game->w1.limit[0] = OX_WINDOW;
	game->w1.limit[1] = OY_WINDOW;
	game->w1.unit[0] = window_unit(game->w1.size[0], OX_DIV);
	game->w1.unit[1] = window_unit(game->w1.size[1], OY_DIV);
	/* --------------------------------------------------------------- */
	minimap_dimensions(game);
	/* --------------------------------------------------------------- */

	/* --------------------------------------------------------------- */
	game->w2.pixel_per_block[0] = (double)((game->w2.size[0]) / (game->map_x + 2));
	game->w2.pixel_per_block[1] = (double)((game->w2.size[1]) / (game->map_y + 2));
	game->w1.pixel_per_block[0] = (double)((game->w1.size[0]) / (game->map_x + 2));
	game->w1.pixel_per_block[1] = (double)((game->w1.size[1]) / (game->map_y + 2));

}