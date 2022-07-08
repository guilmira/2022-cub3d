/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/08 15:50:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//mejorar abstraccion con (put_horizontal) y (put_vertical)

/** PURPOSE : Put pixel to image in a secure way.
 * It need to recieve the y coordinate already SHIFTED!. */
void solid_pixel(mlx_image_t *image, int coor_x, int coor_y, uint32_t colour)
{
	uint32_t x;
	uint32_t y;

	if (coor_x < 0 || coor_y < 0 || colour < 0) //tambien se puede añadir si es =
	{
		printf("Pixel (%i, %i) not rendered\n", coor_x, coor_y);
		return ;
	}
	x = (uint32_t) coor_x;
	y = (uint32_t) coor_y;
	if (x >= image->width || y >= image->height)
	{
		printf("Pixel (%i, %i) could not be rendered\n", coor_x, coor_y);
		return ;
	}
	mlx_put_pixel(image, x, y, colour);
}

/** PURPOSE : Horizontal line in given coordinate. */
void put_horizontal(mlx_image_t *image, double coordinate_y, double limit_x, int colour)
{
	int i;
	int coor_y;

	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, (double) OY_MINIMAP);
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}

/** PURPOSE : Vertical line in given coordinate. */
void put_vertical(mlx_image_t *image, double coordinate_x, double limit_y, int colour)
{
	int j;
	int coor_y;
	
	j = -1;
	while (++j < limit_y)
	{
		coor_y = (int) coor(j, (double) OY_MINIMAP);
		solid_pixel(image, (int) coordinate_x, coor_y, colour);
	}
}

/** PURPOSE : Scale a 2D grid. */
void	draw_grid(mlx_image_t *image, t_prog *game, double size_x, double size_y)
{
	int nb;

	nb = -1;
	while (++nb < 10)
	{
		put_horizontal(image, ( nb * game->w2.unit[1]), size_x, GREEN);
		put_vertical(image, ( nb * game->w2.unit[0]), size_y, RED);
	}
	printf("%f\n", game->w2.unit[1]);
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
	draw_player_position(image, 1 * game->w2.unit[0], 1 * game->w2.unit[1], game); //TODO ejemplo, un 0,0 aqui provoca un seg fault
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	image, game->w2.origin[0], game->w2.origin[1]);
}