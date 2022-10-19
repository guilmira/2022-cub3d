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
static inline void	init_image(t_prog *game)
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
	int32_t	ox_size;
	int32_t	oy_size;

	game->mlx = NULL;
	ox_size = OX_WINDOW;
	oy_size = OY_WINDOW;
	game->mlx = mlx_init(ox_size, oy_size, TITLE_WINDOW, 1);
	if (!game->mlx)
		ft_shutdown("Error.\nMLX could not be initialized\n", game);
	game->map2d.map = NULL;
	game->file = 0;
	game->minimap_state = MINIMAP_INTIAL_STATE;
	if (game->minimap_state != 0 && game->minimap_state != 4 \
	&& game->minimap_state != 2)
		ft_shutdown("Valid Minimap values: 0, 2 or 4\n", game);
	init_image(game);
	game->pl.flag_movement = 0;
	game->pl.flag_trance = 0;
	game->pl.fov = 0;
	game->pl.speed = 0.02;
	game->map2d.layout = NULL;
	game->entity = NULL;
	game->flag_engine_report = GRAPHIC_ENGINE_REPORT;
}
