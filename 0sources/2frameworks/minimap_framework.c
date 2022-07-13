/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/13 21:24:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Scale a 2D grid. */
void	draw_grid(mlx_image_t *image, t_prog *game, double size_x, double size_y)
{
	int nb;

	//coor_identifier(image, game, 1800, 20, game->w2.size[1], 0);
	nb = -1;
	while (++nb < 11)
	{
		put_horizontal(image, ( nb * game->w2.unit[1]), size_x, WHITE);
		put_vertical(image, ( nb * game->w2.unit[0]), size_y, WHITE);
	}
	if (0)
		ft_shutdown(EX, game);
}

/** PURPOSE : Draw 2D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Draw grid.
 * 3. Draw player position + its field of vision. */
void	framework_2D(t_prog *game)
{
	
	/* --------------------------------------------------------------- */

	/* --------------------------------------------------------------- */
	fill_player_pos(game, game->pl.position);
	draw_map(game, game->image[1]);
	draw_grid(game->image[1], game, game->w2.size[0], game->w2.size[1]);	
	draw_player_position(game->image[1], game->pl.position, game->pl.vis, game); //PACE ejemplo, un 0,0 aqui provoca un seg fault
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	game->image[1], game->w2.origin[0], game->w2.origin[1]);
}

void	draw_map(t_prog *game, mlx_image_t *image)