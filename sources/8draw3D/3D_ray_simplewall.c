/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_ray_simplewall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:40:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/06 16:12:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : check if the wall hits on OX axis or OY axis.
 * 2 OX axis (vertical vector that hits on an horizontal)
 * 1 OXY axis (horizontal vector that hits on a vertical) */
static int	is_shadowed(int value)
{
	if (value == 2)
		return (1);
	else
		return (0);
}

/** PURPOSE : choose what shade to put on wall. 
 * 0 - normal
 * 1 - far
 * 2 - shadowed
 * 3 - far shadowed */
static int	choose_wall_shade(int wall_value, int size, t_prog *game)
{
	int	colour[4];

	colour[0] = YELLOW;
	colour[1] = rgb_t_translate(255, 180, 40, 255);
	colour[2] = get_rgb_shadowed(colour[0]);
	colour[3] = get_rgb_shadowed(colour[1]);
	if (is_shadowed(wall_value) && size < game->w1.size[1] / 15)
		return (colour[3]);
	else if (is_shadowed(wall_value))
		return (colour[2]);
	else if (size < game->w1.size[1] / 15)
		return (colour[1]);
	else
		return (colour[0]);
}

/** PURPOSE : draw a vertical symetric line starting in the 
 * middle of the screen. */
static void	centered_vertical(double x, int size, int colour, t_prog *game)
{
	int		i;
	int		y;
	int		counter;
	double	start[D2];	

	i = -1;
	counter = size;
	start[0] = x;
	start[1] = game->w1.size[1] / 2;
	if (counter <= 0)
		return ;
	while (++i < counter)
	{
		y = (int) coor(start[1] - i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], (int)(start[0]), y, colour);
		y = (int) coor(start[1] + i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], (int)(start[0]), y, colour);
	}
}

/** PURPOSE : draw a wall made of straight colored lines. */
void	draw_solid_wall(int ray_number, int wall_side, int size, t_prog *game)
{
	int	wall_colour;

	wall_colour = choose_wall_shade(wall_side, size, game);
	centered_vertical(ray_number, size, wall_colour, game);
}
