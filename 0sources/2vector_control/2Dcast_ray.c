/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dcast_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/16 10:28:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int is_wall2D(int j, int i, t_prog *game)
{
/* 	static int calcu;
	printf("caLc: %i\n", ++calcu); */
				
	if (j < 0 || i < 0)
		return (1);
	if (game->map2D.layout[j][i])
		return (1);
	else
		return (0);
	
}

t_vector final_raycasted_vector(int blocks_advanced, double factor, t_ray *ray, t_prog *game)
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

	printf("VECTOR FINAL\n");
	printf("blocks %i\n", blocks_advanced);
	log_vector(ray->resultant_vector);
	

}

void raycast_collision_routine(t_ray *ray, t_vector dir, t_prog *game)
{
	int counter;

	counter = -1;
	while (++counter <= game->map2D.width + RAYCAST_LIMIT)
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
 * 1. Create ray structure with all the used parameters.
 * 2. Initialize said values.
 * 3. Usea DDA algorithm to move across the grid and find collision point. */
t_vector	 raycast(t_vector dir, double origin[], t_prog *game)
{
	t_ray ray;

	init_ray(&ray, origin, dir, game);
	raycast_collision_routine(&ray, dir, game);
	return (ray.resultant_vector);
}
