/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/06 13:42:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define MARGIN 0.01  //probar con 0


/* Why isnt necessary the exact location. Vector can only stop at 
walls end, so it dosent matter where we are at exactly withing the block.
We work with a vector that would always start at the inferior leftmost corner. */
void init_fictional_distance(t_ray *ray, t_vector direction, t_prog *game)
{
	(void) direction;
	(void) game;

	ray->step[0] = 1;
	ray->step[1] = 1;

	if (ray->dir.x > 0)
	{
		ray->step_increase[0] = 1;
		ray->fictional_distance[0] = (1 * ray->delta[0]);
	}
	else
	{
		ray->step_increase[0] = -1;
		ray->fictional_distance[0] = (0 * ray->delta[0]);
	}
	if (ray->dir.y > 0)
	{
		ray->step_increase[1] = 1;
		ray->fictional_distance[1] = (1 * ray->delta[1]);
	}
	else
	{
		ray->step_increase[1] = -1;
		ray->fictional_distance[1] = (0 * ray->delta[1]);
	}

	if (!ray->dir.x)
		ray->fictional_distance[0] = game->map2D.width + 1;
	if (!ray->dir.y)
		ray->fictional_distance[1] = game->map2D.width + 1;


}

#define DELTA_LIMIT 0.01

void get_delta(t_ray *ray, t_vector dir, t_prog *game)
{
	(void) game;

	if (dir.x > DELTA_LIMIT )
		ray->delta[0] = fabs(1 / dir.x);
	if (dir.y > DELTA_LIMIT )
		ray->delta[1] = fabs(1 / dir.y);
}


void update_location_map2D(t_ray *ray, double position[], t_prog *game);



void init_ray(t_ray *ray, double origin[], t_vector dir, t_prog *game)
{
	ray->origin[0] = origin[0];
	ray->origin[1] = origin[1];
	ray->dir = dir;
	ray->resultant_vector.x = 0;
	ray->resultant_vector.y = 10;
	update_location_map2D(ray, origin, game); //log_coor_int(ray->position_2D);
	ray->delta[0] = 0;
	ray->delta[1] = 0;
	ray->face = 0;
	get_delta(ray, ray->dir, game);
	init_fictional_distance(ray, dir, game);

}




int is_wall2D(int j, int i, t_prog *game);
void get_resultant_vector(t_ray *ray, int array_pos, t_vector dir, t_prog *game);

//poner una cmrobacion de wall al principio
t_vector	 raycast(t_vector dir, double origin[], t_prog *game)
{
	//274 unidades en x  es el multiplicador.
	//154 unidades en y
	int counter;
	int coor_map2D[2];

	t_ray ray;

	init_ray(&ray, origin, dir, game);
	coor_map2D[0] = ray.position_2D[0];
	coor_map2D[1] = ray.position_2D[1];
	counter = -1;
	while (++counter <= game->map2D.width)
	{
		printf("pasada\n");
		log_coor(ray.fictional_distance);
		
		if (ray.fictional_distance[1] < ray.fictional_distance[0])
		{
			//ray.step[1]++;
			
				ray.step[1] += ray.step_increase[1];
		
			ray.fictional_distance[1] += ray.delta[1];
			coor_map2D[1] = ray.position_2D[1] + ray.step[1];
			ray.face = 2;
		}
		else
		{
			
				ray.step[0] += ray.step_increase[0];
			
			ray.fictional_distance[0] += ray.delta[0];
			coor_map2D[0] = ray.position_2D[0] + ray.step[0];
			ray.face = 1;
		}
		if (is_wall2D(coor_map2D[1], coor_map2D[0], game))
		{
			log_coor_int(coor_map2D);
			if (ray.face == 1)
				get_resultant_vector(&ray, 0, dir, game);
			if (ray.face == 2)
				get_resultant_vector(&ray, 1, dir, game);

			printf("pego %i\n", ray.face); //2 es vertical
			break;
		}
		
		
		
	}
	return (ray.resultant_vector);
}

int is_wall2D(int j, int i, t_prog *game)
{
	/* static int calcu;
	printf("caLc: %i\n", ++calcu); */
				

	/* if (j >  6)
		return (1); */ //RZON SEG FALT
	if (j < 0 || i < 0)
		return (1);
	if (game->map2D.layout[j][i])
		return (1);
	else
		return (0);
	
}


void get_resultant_vector(t_ray *ray, int array_pos, t_vector dir, t_prog *game)
{
	double mult;

	mult = ray->fictional_distance[array_pos] * game->map2D.pixel_per_block[array_pos];
	ray->resultant_vector = mul_vec(dir, mult);
}



/** PURPOSE : Get coordinates of array. */
void update_location_map2D(t_ray *ray, double position[], t_prog *game)
{
	ray->position_2D[0] = position[0] / game->map2D.pixel_per_block[0];
	ray->position_2D[1] = position[1] / game->map2D.pixel_per_block[1];
}