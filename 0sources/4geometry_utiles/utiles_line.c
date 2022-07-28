/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:28:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/28 15:42:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Put line horizontal from given beginning to end.
 * ONLY HORIZONTAL LINE AND ONLY FOR MINIMAP.
 */
void put_lineH(double start[], double end[], int colour, t_prog *game)
{
	int x;
	int y;
	mlx_image_t *image;
	image = game->image[MAP_2D];
	int counter;
	int i;

	i = -1;

	counter = (int) end[0] - (int) start[0];
	if (counter <= 0)
		return ;

	while (++i < counter)
	{
		x = (int) (start[0] + i);
		y = (int) coor(start[1], game->w2.size[1]);
		solid_pixel(image, x, y, colour);
	}
}

/** PURPOSE : Translate coordinate from argument map to screen.
 * This is from a 4x4	1111
 * 					 	1001
 * 						1001
 * 						1111
 * to an 1080 x 1900 (or whatever was set) on the screen. */ 
void translate_to_screen(double position_map[], double position_screen[], int pixel_per_block[], t_prog *game)
{
	(void) game;
	position_screen[0] = position_map[0] * (double) pixel_per_block[0];
	position_screen[1] = position_map[1] * (double) pixel_per_block[1];
}