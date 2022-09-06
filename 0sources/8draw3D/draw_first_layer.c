/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:40:26 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/22 16:46:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Horizontal line in given coordinate. */
static void put_horizontal_line(double coordinate_y, double limit_x, int colour, t_prog *game)
{
	int i;
	int coor_y;
	mlx_image_t *image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w1.size[1]);
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}

/** PURPOSE : extend horizonal lines through the screen. */
static void draw_horizon(double origin[], int size, int colour, t_prog *game)
{
	int i;
	double coor_y;
	
	i = -1;
	while (++i < size)
	{
		coor_y = origin[1] + i;
		put_horizontal_line(coor_y, game->w1.size[0], colour, game);
	}
}

/** PURPOSE : floor layer + horizon sky. 
 * 1. game->w1.size[1] / 2 represents the middlepoint at OY. */
void	draw_first_layer(t_prog *game)
{
	int colour_floor;
	int colour_sky;
	double origin[D2];

	origin[0] = 0;
	origin[1] = 0;
	colour_floor = trgb_translate(120, 20, 20, 255);
	colour_sky = trgb_translate(0, 40, 40, 255);
	draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	origin[1] = game->w1.size[1] / 2;
	draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);
}