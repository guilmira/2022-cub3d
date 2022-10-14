/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_ray_texture_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:46:10 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : get direction that the wall is facing. 
 * (ray hits on opposite side).
 * To be clear , it goes clockwise. 1 ray hits nort, 
 * 2 ray hits east, and so on.
 * 1 - north
 * 2 - east
 * 3 - south
 * 4 - west */
int	get_wall_orientation(int wall_side, t_vector direction)
{
	if (wall_side == 2)
	{
		if (direction.y > 0)
			return (1);
		else
			return (3);
	}
	else
	{
		if (direction.x > 0)
			return (2);
		else
			return (4);
	}
}

/** PURPOSE : get texture to represent depending on wall orientation. */
mlx_texture_t	*get_oriented_texture(int wall_side, \
t_vector direction, t_prog *game)
{
	int		wall_orientation;

	wall_orientation = get_wall_orientation(wall_side, direction);
	if (wall_orientation == 1)
		return (game->t_north);
	if (wall_orientation == 2)
		return (game->t_east);
	if (wall_orientation == 3)
		return (game->t_south);
	if (wall_orientation == 4)
		return (game->t_west);
	return (game->t_north);
}
