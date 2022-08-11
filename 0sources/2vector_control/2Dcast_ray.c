/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dcast_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/11 11:37:27 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//#define PROV 0.01

void update_location_map2D(t_ray *ray, double position[], t_prog *game);

int is_wall2D(int j, int i, t_prog *game)
{
	/* static int calcu;
	printf("caLc: %i\n", ++calcu); */
				
	if (j < 0 || i < 0)
		return (1);
	if (game->map2D.layout[j][i])
		return (1);
	else
		return (0);
	
}


t_vector final_raycasted_vector(int blocks_advanced, double factor, int face, t_prog *game)
{
	t_vector vector;

	if (face == 2)
	{
		vector.y = blocks_advanced * game->map2D.pixel_per_block[1];
		vector.x = vector.y / factor;
	}
	if (face == 1)
	{
		vector.x = blocks_advanced * game->map2D.pixel_per_block[0];
		vector.y = vector.x * factor;
	}
	return (vector);
}


static void get_resultant_vector(t_ray *ray, int array_pos, t_vector dir, t_prog *game)
{
	double		factor;
	t_vector	vector;
	int			blocks_advanced;
	
	printf("steps neto : %i\n", ray->step[array_pos]);

	vector.x = 0;
	vector.y = 0;
	/* --------------- */
	blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos];
	if (ray->dir.y < 0 && array_pos == 1)
		blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos] + 1;
	if (ray->dir.x < 0 && array_pos == 0)
		blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos] + 1;
	/* --------------- */
	printf("AQUUIIII %i\n", blocks_advanced);
	if (!dir.x)
		vector.y = blocks_advanced * game->map2D.pixel_per_block[array_pos];
	if (!dir.y)
		vector.x = blocks_advanced * game->map2D.pixel_per_block[array_pos];
	ray->resultant_vector = vector;
	if (!dir.x || !dir.y)
		return ;
	factor = dir.y / dir.x;
	ray->resultant_vector = final_raycasted_vector\
	(blocks_advanced, factor, ray->face, game);

}

#define PROVI 300

void raycast_collision_routine(t_ray *ray, t_vector dir, t_prog *game)
{
	int counter;

	counter = -1;
	while (++counter <= PROVI)
	{

		if (!counter)
			printf("EMPIEZA------------------------------------------------------------------\n");
		if (ray->fictional_distance[1] < ray->fictional_distance[0])
		{
			printf("me fijo en OY\n");
			ray->step[1] += ray->step_increase[1];
			ray->fictional_distance[1] += ray->delta[1];
			ray->face = 2;
		}
		else
		{
			printf("me fijo en OX\n");
			ray->step[0] += ray->step_increase[0];
			ray->fictional_distance[0] += ray->delta[0];
			ray->face = 1;
		}
		if (is_wall2D(ray->step[1], ray->step[0], game))
		{
			if (ray->face == 1)
				get_resultant_vector(ray, 0, dir, game);
			if (ray->face == 2)
				get_resultant_vector(ray, 1, dir, game);
			printf("pego coordenaadas (%i ,%i )en cara%i\n", ray->step[0], ray->step[1], ray->face); //2 es vertical
			break ;
		}
		printf("-----------------------\n");
		log_coor(ray->fictional_distance);
		printf("-----------------------\n");
		
	}

}

void init_ray(t_ray *ray, double origin[], t_vector dir, t_prog *game);

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
