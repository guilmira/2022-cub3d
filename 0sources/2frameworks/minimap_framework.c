/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/07 14:24:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//mejorar abstraccion con (put_horizontal) y (put_vertical)

void put_horizontal(mlx_image_t *image, double coordinate_y, double limit_x, int colour)
{
	int i;
	int coor_y;

	i = -1;
	coor_y = (int) coor(coordinate_y, OY_MINIMAP);//it wont change on an horizontal
	printf("%f\n", coor(coordinate_y, OY_MINIMAP));
	printf("%i\n", coor_y);
	
	//mlx_put_pixel(image, 769, coor_y, colour);
	while (++i < limit_x)
	{
		//printf("%i\n", i); //768
		mlx_put_pixel(image, i, coor_y, colour);
		
	
	}
	printf("komo va\n");
}

void put_vertical(mlx_image_t *image, double coordinate_x, double limit_y, int colour)
{
	int j;
	j = -1;


	while (++j < limit_y)
	{
		mlx_put_pixel(image, coordinate_x, coor(j, OY_MINIMAP), colour);
	}
}

/** PURPOSE : Scale a 2D grid. */
void	draw_grid(mlx_image_t *image, t_prog *game, double size_x, double size_y)
{

	//offset for double
	printf("%f\n", game->w2.origin[0]);
	printf("%f\n", game->w2.size[0]);
	printf("%f\n", game->w2.limit[0]);
	printf("%f\n", game->w2.unit[0]);
	for (int nb = 0; nb < 10; nb++)
	{
			

		put_horizontal(image, ( nb * game->w2.unit[1]), size_x, GREEN);
		put_vertical(image, ( nb * game->w2.unit[0]), size_y, RED);
	}
	printf("PASSA\n");
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
	//draw_player_position(image, 2 * game->w2.unit[0], 2 * game->w2.unit[1], game);

	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	image, game->w2.origin[0], game->w2.origin[1]);
}