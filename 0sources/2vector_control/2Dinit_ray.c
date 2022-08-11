/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dinit_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:14:55 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/11 11:22:49 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//#define DELTA_LIMIT 0.01


/** PURPOSE : Get the distance of OX between 2 vertical lines that represent a wall.
 * Or the equivalent of OY. */
static void get_delta(t_ray *ray, t_vector dir)
{
	/* if (fabs(dir.x) > DELTA_LIMIT ) */
		ray->delta[0] = fabs(1 / dir.x);
/* 	if (fabs(dir.y) > DELTA_LIMIT ) */
		ray->delta[1] = fabs(1 / dir.y);
}

/** PURPOSE : Init distance of delta x or delta y at first block.
 * 1. There is a difference between what 2D block we are at, and the exact coor location.
 *	Factor_at_origin corrects that offset. */
static void init_net_distance(t_ray *ray, t_vector direction, t_prog *game)
{
	double origin_coordinates[2]; 
	double factor_at_origin;

	origin_coordinates[0] = ray->origin[0];
	origin_coordinates[1] = ray->origin[1];
	ray->step[0] = ray->position_2D[0];
	ray->step[1] = ray->position_2D[1];
	if (direction.x >= 0)
	{
		ray->step_increase[0] = 1;
		factor_at_origin = (double) ray->position_2D[0] * game->map2D.pixel_per_block[0] - ray->origin[0];
		ray->fictional_distance[0] = (factor_at_origin + 1) * ray->delta[0];
	}
	else
	{
		ray->step_increase[0] = -1;
		factor_at_origin = ray->origin[0] - (double) ray->position_2D[0] * game->map2D.pixel_per_block[0];
		ray->fictional_distance[0] = (factor_at_origin) * ray->delta[0];
	}
	if (direction.y >= 0)
	{
		ray->step_increase[1] = 1;
		factor_at_origin = (double) ray->position_2D[1] * game->map2D.pixel_per_block[0] - ray->origin[1];
		ray->fictional_distance[1] = (factor_at_origin + 1) * ray->delta[1];
	}
	else
	{
		ray->step_increase[1] = -1;
		factor_at_origin = ray->origin[1] - (double) ray->position_2D[1] * game->map2D.pixel_per_block[0];
		ray->fictional_distance[1] = (factor_at_origin) * ray->delta[1];
	}
/* printf("%f\n", factor_at_origin);
	printf("HERE \n");
	if (fabs(direction.x) < PROV)
		ray->fictional_distance[0] = game->map2D.width + 1;
	if (fabs(direction.y) < PROV)
		ray->fictional_distance[1] = game->map2D.width + 1; */

}

/** PURPOSE : Get coordinates of array. */
static void update_location_map2D(t_ray *ray, double position[], int pixel_per_block[])
{
	ray->position_2D[0] = position[0] / pixel_per_block[0];
	ray->position_2D[1] = position[1] / pixel_per_block[1];
}

/** PURPOSE : Init values
 * 1. Delta is the distance of OX between 2 vertical lines that represent a wall. */
void init_ray(t_ray *ray, double origin[], t_vector dir, t_prog *game)
{
	ray->origin[0] = origin[0];
	ray->origin[1] = origin[1];
	ray->dir = dir;
	ray->resultant_vector.x = 0;
	ray->resultant_vector.y = 0;
	/* ----------------------------------------- */
	update_location_map2D(ray, origin, game->map2D.pixel_per_block); 
	ray->delta[0] = 0;
	ray->delta[1] = 0;
	ray->face = 0;
	get_delta(ray, ray->dir);
	init_net_distance(ray, ray->dir, game);
}