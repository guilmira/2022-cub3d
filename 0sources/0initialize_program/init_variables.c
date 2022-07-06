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

/** PURPOSE : two variables: the origin at window and its size. */
static void init_minimap_dimensions(t_prog *game)
{
	game->minimap.ox = MAP_OX;
	game->minimap.oy = MAP_OY;
	game->minimap.size_x = MAP_SIZE_X;
	game->minimap.size_y = MAP_SIZE_Y;
}

/** PURPOSE : pointers at images to NULL */
static void init_image(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < TOTAL_IMAGES + 1)
		game->image[i] = NULL;
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
	init_minimap_dimensions(game);
}