/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 15:15:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Scale a 2D grid. */
void	draw_grid(t_prog *game, double size_x, double size_y)
{
	int nb;

	nb = -1;
	while (++nb < 11)
	{
		put_horizontal(( nb * game->w2.unit[1]), size_x, WHITE, game);
		(void ) size_x;
		put_vertical(( nb * game->w2.unit[0]), size_y, WHITE, game);
	}
	if (0)
		ft_shutdown(EX, game);
}

static void draw_map(t_prog *game)
{
	int i;
	int x;

	i = 1;
	while (i < game->map_y + 1)
	{
		x = -1;
		while (x <= game->map_x)
		{		
			if (game->map[i][x++] == '1')
				draw_centered_rectangle(x * game->w2.pixel_per_block[0], (game->map_y - i) * game->w2.pixel_per_block[1], game->w2.pixel_per_block[0], game->w2.pixel_per_block[1], game);
		}
		i++;
	}
}

/** PURPOSE : Draw 2D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Draw grid.
 * 3. Draw player position + its field of vision. */
void	framework_2D(t_prog *game)
{
	if (!game->minimap_state)
		return ;
	/* --------------------------------------------------------------- */

	/* --------------------------------------------------------------- */
	draw_grid(game, game->w2.size[0], game->w2.size[1]);
	draw_map(game);
	draw_player_position(game->image[MAP_2D], game->pl.position, game->pl.vis, game); //PACE ejemplo, un 0,0 aqui provoca un seg fault
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	game->image[MAP_2D], game->w2.origin[0], game->w2.origin[1]);
}
