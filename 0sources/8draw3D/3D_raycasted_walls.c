/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/05 16:26:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : draw a vertical symetric line starting in the 
 * middle of the screen. */
static void centered_vertical(double x, int size, int colour, t_prog *game)
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
		solid_pixel(game->image[CUB_3D], (int) (start[0]), y, colour);
		y = (int) coor(start[1] + i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], (int) (start[0]), y, colour);
	}
}

#define CONSTANT 2000
#define MIN_DIST 1

static double get_height_constant(t_prog *game)
{
	double height;
	
	(void) game;
	height = CONSTANT;
	return (height);
}


/** PURPOSE : calculate wall height. */
static double get_wall_size(double distance, t_prog *game)
{
	double	ret;
	int		max_size;
	double	height;

	height = get_height_constant(game);
	max_size = (game->w1.size[1] / 4) - SAFE_OFFSET;
	if (distance < MIN_DIST)
		return (max_size);
	ret = height / distance;
	//printf("dist: %d\n", distance);
	ret = (int) ret;
	if (ret > max_size)
		return (max_size);
	else
		return (ret);
}

/** PURPOSE : draw a vertical line of calculated size. */
static void draw_wall_vertical_unit(int i, int wall_side, double distance, t_prog *game)
{
	int	size;
	int	pixel_ox;
	int	wall_colour;

	pixel_ox = i;
	size = get_wall_size(distance, game);
	wall_colour = choose_wall_shade(wall_side, size, game);
	centered_vertical(pixel_ox, size, wall_colour, game);
}

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < game->rc->number_of_rays)
	{
		draw_wall_vertical_unit(i, game->rc->rc_wall_side[i],\
		game->rc->rc_distance[i], game);
	}
}