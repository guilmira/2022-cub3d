/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:18:40 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/05 14:19:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : pointers at images to NULL */
static void init_image(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < TOTAL_IMAGES + 1)
		game->image[i] = NULL;
}

/** PURPOSE : calculate boundry condition for framework. */
static double	window_limit(double origin, double size)
{
	return (size + origin);
}

/** PURPOSE : calculate unit of meastur for each framework. */
static double	window_unit(double size, double divisor)
{
	return ( size / divisor);
}

/** PURPOSE : calculate main window and minimap dimensions. */
void	framework_dimensions(t_prog *game)
{
	game->w1.origin[0] = 0;
	game->w1.origin[1] = 0;
	game->w1.size[0] = OX_WINDOW;
	game->w1.size[1] = OY_WINDOW;
	//limit is the OVERALL LIMIT COORDINATE
	game->w1.limit[0] = window_limit(game->w1.origin[0], game->w1.size[0]);
	game->w1.limit[1] = window_limit(game->w1.origin[1], game->w1.size[1]);
	game->w1.unit[0] = window_unit(game->w1.size[0], OX_DIV);
	game->w1.unit[1] = window_unit(game->w1.size[1], OY_DIV);
	/* --------------------------------------------------------------- */
	game->w2.origin[0] = OX_MINIMAP_O;
	game->w2.origin[1] = OY_MINIMAP_O;
	game->w2.size[0] = OX_MINIMAP;
	game->w2.size[1] = OY_MINIMAP;
	game->w2.limit[0] = window_limit(game->w2.origin[0], game->w2.size[0]);
	game->w2.limit[1] = window_limit(game->w2.origin[1], game->w2.size[1]);
	if (game->w2.limit[0] > OX_WINDOW || game->w2.limit[1] > OY_WINDOW)
		ft_shutdown("Minimap to big\n", game);
	game->w2.unit[0] = window_unit(game->w2.size[0], OX_DIV);
	game->w2.unit[1] = window_unit(game->w2.size[1], OY_DIV);
	/* --------------------------------------------------------------- */
	game->w1.sec_limit[0] = game->w1.size[0] - game->w2.origin[0]; //only if (OX >= game->w2.origin[0])
	game->w1.sec_limit[1] = game->w1.size[1] - game->w2.origin[1]; //only if (OY >= game->w2.origin[1])
	game->w2.sec_limit[0] = 0;
	game->w2.sec_limit[1] = 0;
}

/** PURPOSE : init MLX and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). 
 * The library functions need it in order to work.
 * 2. Inits the rest of the variables within the struct. */
void	init_game(t_prog *game)
{
	game->mlx = mlx_init(OX_WINDOW, OY_WINDOW, TITLE_WINDOW, 1);
	if (!game->mlx)
		ft_shutdown("MLX could not be initialized\n", game);
	/* --------------------------------------------------------------- */
	//INIT all pointers to NULL, variables to zero.
	game->map = NULL;
	game->file = 0;
	/* --------------------------------------------------------------- */
	init_image(game);
	framework_dimensions(game);
}