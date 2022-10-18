/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dinit_ray_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:14:55 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Check if at given coordinates, there is a wall. */
int	is_wall2d(int j, int i, t_prog *game)
{
	if (j < 0 || i < 0)
		return (1);
	if (i >= game->map2d.height || j >= game->map2d.width)
		return (1);
	if (game->map2d.layout[j][i])
		return (1);
	else
		return (0);
}

/** PURPOSE : Get distance at the beginnig of the coordinate. */
void	get_relative_distance(t_ray *ray, t_prog *game)
{
	ray->relative_distance[0] = 0;
	ray->relative_distance[1] = 0;
	ray->relative_distance[0] = ray->origin[0] - \
	(double) ray->pos[0] * game->map2d.pixel_per_block[0];
	ray->relative_distance[1] = ray->origin[1] - \
	(double) ray->pos[1] * game->map2d.pixel_per_block[1];
}

/** PURPOSE : fix net distance.
 * 1. There is a difference between what 2D block 
 * we are at, and the exact coor location.
 *	Factor corrects that offset. */
void	fix_net_distance(t_ray *ray, int case_factor, int block[])
{
	double	factor;

	if (case_factor == 1)
	{
		factor = (((double) ray->pos[0] + 1) * block[0] \
		- ray->origin[0]) / block[0];
		ray->net_distance[0] = (factor) * ray->delta[0];
	}
	else if (case_factor == 2)
	{
		factor = (ray->origin[0] - (double) ray->pos[0] * block[0]) / block[0];
		ray->net_distance[0] = (factor) * ray->delta[0];
	}
	else if (case_factor == 3)
	{
		factor = (((double) ray->pos[1] + 1) * block[1] \
		- ray->origin[1]) / block[1];
		ray->net_distance[1] = (factor) * ray->delta[1];
	}
	else if (case_factor == 4)
	{
		factor = (ray->origin[1] - (double) ray->pos[1] * block[1]) / block[1];
		ray->net_distance[1] = (factor) * ray->delta[1];
	}
}
