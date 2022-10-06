/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/06 16:11:54 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : get height. */
static double	get_height_constant(t_prog *game)
{
	double	height;

	(void) game;
	height = CONSTANT_HEIGHT_WALL;
	return (height);
}

/** PURPOSE : calculate wall height. */
static double	get_wall_size(double distance, t_prog *game)
{
	double	ret;
	double	height;

	height = get_height_constant(game);
	ret = height / distance;
	return (ret);
}

/** PURPOSE : draw a vertical line of calculated size. 
 * Add function 
 * draw_solid_wall(ray_number, wall_side, size, game)
 * in order to represent a simple cube representation. */
static inline void	draw_wall_vertical_unit(int ray_number, t_prog *game)
{
	int		size;
	int		wall_side;
	double	distance;

	wall_side = game->rc->rc_wall_side[ray_number];
	distance = game->rc->rc_distance[ray_number];
	size = get_wall_size(distance, game);
	draw_textured_wall(wall_side, ray_number, size * 2, game);
}

/** PURPOSE : wa66lls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_three_dimension_walls(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < game->rc->number_of_rays)
		draw_wall_vertical_unit(i, game);
}
