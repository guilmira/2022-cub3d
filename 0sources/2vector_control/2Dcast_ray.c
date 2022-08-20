/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dcast_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 12:51:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Check if at given coordinates, there is a wall. */
static int is_wall2D(int j, int i, t_prog *game)
{
	if (j < 0 || i < 0)
		return (1);
	if (game->map2D.layout[j][i])
		return (1);
	else
		return (0);
}

/** PURPOSE : Get the final coordinates of the vecctor that has collided. */
static t_vector final_raycasted_vector(int blocks_advanced, double factor, t_ray *ray, t_prog *game)
{
	t_vector vector;

	if (ray->face == 2)
	{
		vector.y = blocks_advanced * game->map2D.pixel_per_block[1] - ray->relative_distance[1];
		vector.x = vector.y / factor;
	}
	if (ray->face == 1)
	{
		vector.x = blocks_advanced * game->map2D.pixel_per_block[0] - ray->relative_distance[0];
		vector.y = vector.x * factor;
	}
	return (vector);
}

/** PURPOSE : Get vector that goes until that collision point that is found. */
static void get_resultant_vector(t_ray *ray, int array_pos, t_vector dir, t_prog *game)
{
	double		factor;
	t_vector	vector;
	int			blocks_advanced;
	
	vector.x = 0;
	vector.y = 0;
	/* --------------- */
	blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos];
	if (ray->dir.y < 0 && array_pos == 1)
		blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos] + 1;
	if (ray->dir.x < 0 && array_pos == 0)
		blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos] + 1;
	/* --------------- */
	if (!dir.x)
		vector.y = blocks_advanced * game->map2D.pixel_per_block[array_pos];
	if (!dir.y)
		vector.x = blocks_advanced * game->map2D.pixel_per_block[array_pos];
	ray->resultant_vector = vector;
	if (!dir.x || !dir.y)
		return ;
	factor = dir.y / dir.x;
	ray->resultant_vector = final_raycasted_vector\
	(blocks_advanced, factor, ray, game);
}

/** PURPOSE : Here is how the algorithm works: 
 * 1. t_ray = structure with all the parameters initialized.
 * 2. Loop for an ammmount of times at least as big as the bigger distance OX or OY.
 * 3. Compare the net_distance. If OY grid distance is closer to the origin point 
 * than the distance of OX, thats the one that we ll be looking at for a collision.
 * 4. Increase step (or grid block) in said direcction.
 * 5. Check if indeed there is a collision (a wall) at that location. If not, loop. */
static void raycast_collision_algorithm(t_ray *ray, t_vector dir, t_prog *game)
{
	int counter;

	counter = -1;
	while (++counter <= game->map2D.width + game->map2D.height)
	{

		/* if (!counter)
			printf("EMPIEZA------------------------------------------------------------------\n");
		printf("%f frente a %f\n", ray->net_distance[0], ray->net_distance[1]); */
		if (ray->net_distance[1] < ray->net_distance[0])
		{
			//printf("me fijo en OY\n");
			ray->step[1] += ray->step_increase[1];
			ray->net_distance[1] += ray->delta[1];
			ray->face = 2;
		}
		else
		{
			//printf("me fijo en OX\n");
			ray->step[0] += ray->step_increase[0];
			ray->net_distance[0] += ray->delta[0];
			ray->face = 1;
		}
		if (is_wall2D(ray->step[1], ray->step[0], game))
		{
			if (ray->face == 1)
				get_resultant_vector(ray, 0, dir, game);
			if (ray->face == 2)
				get_resultant_vector(ray, 1, dir, game);
			//printf("pego coordenaadas (%i ,%i )en cara%i\n", ray->step[0], ray->step[1], ray->face); //2 es vertical
			break ;
		}	
	}
}

/** PURPOSE : Cast a ray from location to wall, following the direction vector.
 * Direction, position, and walls + DDA algorightm = collision point. */
t_vector	 raycast(t_vector dir, double origin[], t_prog *game)
{
	t_ray ray;

	init_ray(&ray, origin, dir, game);
	raycast_collision_algorithm(&ray, dir, game);
	return (ray.resultant_vector);
}
