/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_ray_simplewall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:00:51 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/23 13:51:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define CONSTANT 800
#define MIN_DIST 1

/** PURPOSE : get height. */
static double get_height_constant(t_prog *game)
{
	double height;
	
	(void) game;
	height = CONSTANT;
	return (height);
}


/** PURPOSE : calculate wall height. */
double get_wall_size(double distance, t_prog *game)
{
	double	ret;
	//int		max_size;
	double	height;
	
	height = get_height_constant(game);
	//max_size = (game->w1.size[1] / 2) - SAFE_OFFSET;
	
	ret = height / distance;

		return (ret);
}


/** PURPOSE : draw a vertical symetric line starting in the 
 * middle of the screen. */
void centered_vertical(double x, int size, int colour, t_prog *game)
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