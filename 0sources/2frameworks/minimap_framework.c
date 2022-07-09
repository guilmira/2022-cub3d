/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/09 16:37:37 by guilmira         ###   ########.fr       */
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
void	secd_image_framework(t_prog *game)
{
	mlx_image_t	*image;
	
	image = mlx_new_image(game->mlx,\
	(int) game->w2.size[0], (int) game->w2.size[1]);
	if (!image)
		ft_shutdown(EX3, game);
	game->image[1] = image; 
	/* --------------------------------------------------------------- */
	draw_grid(image, game, game->w2.size[0], game->w2.size[1]);
	coor_identifier(image, game, 4.2 * game->w2.unit[0], 1.2 * game->w2.unit[1], OY_MINIMAP, 0);
	draw_player_position(image, 4.2 * game->w2.unit[0], 1.2 * game->w2.unit[1], game); //TODO ejemplo, un 0,0 aqui provoca un seg fault
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	image, game->w2.origin[0], game->w2.origin[1]);
}