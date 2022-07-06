/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/06 17:45:32 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


//mejorar abstraccion con (put_horizontal) y (put_vertical)

/* void put_horizontal(mlx_image_t *image, int coordinate_y, int limit_x, int colour)
{
	int i;

	i = -1;
	while (++i < limit_x)
		mlx_put_pixel(image, i, coor(coordinate_y), colour);
} */

/** PURPOSE : Scale a 2D grid. */
void	draw_grid(mlx_image_t *image, t_prog *game, int size_x, int size_y)
{
	//put_horizontal(image, MAP_UNIT_Y + 11, 30, GREEN);

	for (int nb = 0; nb < 10; nb++)
	{
		for (int j = 0; j < size_y; j++)
			mlx_put_pixel(image, ( nb * (size_x / OX_DIV) ), j, BLACK);
		for (int i = 0; i < size_x; i++)
			mlx_put_pixel(image, i, ( nb * (size_y / OY_DIV) ), BLACK);
		
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
	
	//parser: minimap cant be bigger than window, has to be located inside, not cross borders.
	//(ox + size_x >= WINOW_LIMIT) -> shutdown
	//parser_minimap_dimensions(); TODO
	image = mlx_new_image(game->mlx,\
	game->minimap.size_x, game->minimap.size_y);
	if (!image)
		ft_shutdown(EX3, game);
	game->image[1] = image; 
	/* --------------------------------------------------------------- */
	draw_grid(image, game, game->minimap.size_x, game->minimap.size_y);
	draw_player_position(image, 2 * MAP_UNIT_X, 2 * MAP_UNIT_Y, game);
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	image, game->minimap.ox, game->minimap.oy);
}