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
static void	init_image(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < TOTAL_IMAGES + 1)
		game->image[i] = NULL;
}

static void parser_defines(t_prog *game)
{
	if (OY_WINDOW < 800)
		ft_shutdown(EX0, game);
	if (OX_WINDOW > OY_WINDOW)
		ft_shutdown(EX0, game);
	if (OX_WINDOW != OY_WINDOW)
		ft_shutdown(EX0, game);
	
}


/** PURPOSE : init MLX and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). 
 * The library functions need it in order to work.
 * 2. Inits the rest of the variables within the struct. */
void	init_game(t_prog *game)
{
	int32_t ox_size;
	int32_t oy_size;

	game->mlx = NULL;
	ox_size = OX_WINDOW;
	oy_size = OY_WINDOW;
	parser_defines(game);
	game->mlx = mlx_init(ox_size, oy_size, TITLE_WINDOW, 1);
	if (!game->mlx)
		ft_shutdown("Error.\nMLX could not be initialized\n", game);
	/* --------------------------------------------------------------- */
	game->map2D.map = NULL;
	game->file = 0;
	game->minimap_state = MINIMAP_INTIAL_STATE;
	/* --------------------------------------------------------------- */
	init_image(game);
	game->pl.flag_movement = 1;
	game->pl.flag_trance = 0;
	game->map2D.layout = NULL;
}
