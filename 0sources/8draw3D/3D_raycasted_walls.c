/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/22 17:09:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void centered_vertical(double x, int size, int colour, t_prog *game)
{
	int				i;
	int				y;
	int				counter;
	double start[D2];	

	i = -1;
	counter = (int) size;

	start[0] = x;
	start[1] = game->w1.size[1] / 2;
	if (counter <= 0)
		return ;
	while (++i < counter)
	{
		y = (int) coor(start[1] - i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], \
		(int) (start[0]), y, colour);

		y = (int) coor(start[1] + i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], \
		(int) (start[0]), y, colour);
	}
}
#define CONSTANT 5000

int get_wall_size(int distance, t_prog *game)
{
	(void) game;
	return (CONSTANT / distance);
}

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght deoending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int	i;
	i = -1;
	int screen_width;
	int wall_ox_unit;
	int pixel_ox_counter;
	int size;
	int pixel_ox;
	int shadowed;
	int colour_shadowed;
	int colour_normal;

	colour_normal = BLUE;
	colour_shadowed = trgb_translate(0, 0, 255, 120);

	shadowed = 0;
	pixel_ox_counter = -1;
	screen_width = game->w1.size[0];
	wall_ox_unit = screen_width / game->rc->number_of_rays;
	while (++i < game->rc->number_of_rays)
	{
		
		size = get_wall_size(game->rc->rc_distance[i], game);
		while (++pixel_ox_counter < wall_ox_unit)
		{
			if (game->rc->rc_wall_side[i] == 2)
				shadowed++;
			else
				shadowed = 0;
			pixel_ox = (wall_ox_unit * i) + pixel_ox_counter;
			if (shadowed)
				centered_vertical(pixel_ox, size, colour_normal, game);
			else
				centered_vertical(pixel_ox, size, colour_shadowed, game);

		}
		pixel_ox_counter = -1;

	}
}