/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dimensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:10:11 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 11:34:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : calculate unit of measure for each framework. */
static double	window_unit(double size, double divisor)
{
	return (size / divisor);
}

/** PURPOSE : copy struct. */
static t_dim	copy_dim_struct(t_dim window_src)
{
	t_dim	win_return;

	win_return.origin[0] = window_src.origin[0];
	win_return.origin[1] = window_src.origin[1];
	win_return.size[0] = window_src.size[0];
	win_return.size[1] = window_src.size[1];
	win_return.unit[0] = window_src.unit[0];
	win_return.unit[1] = window_src.unit[1];
	return (win_return);
}

void	get_minimap_simetric_size(t_prog *game)
{
	game->w2.size[0] = (game->w1.size[0] / MINIMAP_WINDOW_RATIO);
	game->w2.size[1] = (game->w1.size[1] / MINIMAP_WINDOW_RATIO);

	while ((int) game->w2.size[0] % game->map2D.width != 0)
		game->w2.size[0]++;
	while ((int) game->w2.size[1] % game->map2D.height != 0)
		game->w2.size[1]++;

	game->w2.origin[0] = game->w1.size[0] - game->w2.size[0];
	game->w2.origin[1] = game->w1.size[1] - game->w2.size[1];
}


/** PURPOSE : used to recalculate minimap dimensions.
 * EXPLANATION - limit and size are the same, but calculated int two ways. */
void	minimap_dimensions(t_prog *game)
{
	if (!game->minimap_state)
		return ;
	else if (game->minimap_state == 2)
	{
		get_minimap_simetric_size(game);
		if (game->w2.size[0] - game->w2.origin[0] > game->w1.size[0] \
		|| game->w2.size[1] - game->w2.origin[1] > game->w1.size[1])
			ft_shutdown("Error.\nMinimap to big\n", game);
		game->w2.unit[0] = window_unit(game->w2.size[0], game->map2D.width);
		game->w2.unit[1] = window_unit(game->w2.size[1], game->map2D.height);
	}
	else
		game->w2 = copy_dim_struct(game->w1);
}

/** PURPOSE : calculate main window and minimap dimensions. */
void	framework_dimensions(t_prog *game)
{
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
	update_pixel_per_block(game);
	game->map2D.pixel_per_b_screen[0] = game->w2.size[0] / VISUAL_BLOCKS_W;
	game->map2D.pixel_per_b_screen[1] = game->w2.size[1] / VISUAL_BLOCKS_H;
}
