/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 12:34:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* The whole idea is to pass Cartesian coordinates.
Forget all about the shifting. 
The geom_functions themselves will take care of the conversion. */

/* NOTATION: 
	coor_x, coor_y :	abstraction coordinates. Have not been shifted.
	have DOUBLE type.
	x, y:				actual coordinates. already shifted. Used for solid_pixel.
	they have the type INT.
 */

/** PURPOSE : Put pixel to image in a secure way.
 * It need to recieve the y coordinate already SHIFTED!. */
void solid_pixel(mlx_image_t *image, int coor_x, int coor_y, uint32_t colour)
{
	uint32_t x;
	uint32_t y;

	mlx_put_pixel(image, 50, 50, BLACK);

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
void put_horizontal(double coordinate_y, double limit_x, int colour, t_prog *game)
{
	int i;
	int coor_y;
	mlx_image_t *image;

	image = game->image[MAP_2D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w2.size[1]); //!!!ojo que aqui podria ser x
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}

/** PURPOSE : Vertical line in given coordinate. */
void put_vertical(double coordinate_x, double limit_y, int colour, t_prog *game)
{
	int j;
	int coor_y;
	mlx_image_t *image;

	image = game->image[MAP_2D];
	if (coordinate_x == image->width)
		coordinate_x -= (SAFE_OFFSET);
	j = -1;
	while (++j < limit_y)
	{
		coor_y = (int) coor(j, game->w2.size[1]);
		solid_pixel(image, (int) coordinate_x, coor_y, colour);
	}
}

/** PURPOSE : Base times height.
 * 1. Requires dimensions and position of origin. */
void draw_centered_rectangle(double o_x, double o_y, int base, int height, t_prog *game)
{
	int i;
	int j;
	int x;
	int y;
	mlx_image_t *image;

	image = game->image[MAP_2D];
	if (o_x < 0 || o_y < 0)
		return ;
	i = -1;
	j = -1;
	o_y = o_y - height / 2;
	o_x = o_x - base / 2;

	while (++j < height)
	{
		while (++i < base)
		{
			x = (int) (o_x + i);
			y = (int) coor(o_y + j, game->w2.size[1]);
			solid_pixel(image, x, y, RED);
		}
		i = -1;
	}
}

int check_radio(double coord[], double radio);

void draw_2d_player(mlx_image_t *image, double pos[], double radio, int colour, t_prog *game)
{
	double i[2];

	i[0] = -1 - radio;
	while (++i[0] < (radio * 2))
	{
		i[1] = -1 - radio;
		while (++i[1] < (radio * 2))
			if(check_radio(i, radio))
				solid_pixel(image, i[0] + pos[0], coor(i[1] + pos[1], game->w2.size[1]), colour);
	}
}

int check_radio(double coord[], double radio)
{
	if(pow((coord[0]) , 2) + pow((coord[1]), 2) <= pow(radio, 2))
		return (1);
	return (0);
}

