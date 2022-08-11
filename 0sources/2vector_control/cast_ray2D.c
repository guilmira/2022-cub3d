/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/11 10:46:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define MARGIN 0.01  //probar con 0

#define PROV 0.01

/* Why isnt necessary the exact location. Vector can only stop at 
walls end, so it dosent matter where we are at exactly withing the block.
We work with a vector that would always start at the inferior leftmost corner. */

/** PURPOSE : Init distance of delta x or delta y at first block
 * 1. Factor at origin corrects int  */
void init_fictional_distance(t_ray *ray, t_vector direction, t_prog *game)
{
	(void) game;
	double origin_coordinates[2]; 
	double factor_at_origin;

	origin_coordinates[0] = ray->origin[0];
	
	origin_coordinates[1] = ray->origin[1];
	ray->step[0] = ray->position_2D[0]; //equivalent to a standar 0, 0
	ray->step[1] = ray->position_2D[1];
	log_coor_int(ray->position_2D);


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
printf("%f\n", factor_at_origin);
	printf("HERE \n");
	if (fabs(direction.x) < PROV)
		ray->fictional_distance[0] = game->map2D.width + 1;
	if (fabs(direction.y) < PROV)
		ray->fictional_distance[1] = game->map2D.width + 1;

}






void update_location_map2D(t_ray *ray, double position[], t_prog *game);


void get_delta(t_ray *ray, t_vector dir, t_prog *game);

void init_ray(t_ray *ray, double origin[], t_vector dir, t_prog *game)
{
	ray->origin[0] = origin[0];
	ray->origin[1] = origin[1];
	ray->dir = dir;
	ray->resultant_vector.x = 0;
	ray->resultant_vector.y = 10;

	//cuando cambies la posicion del player, observa esto
	update_location_map2D(ray, origin, game); //log_coor_int(ray->position_2D);
	ray->delta[0] = 0;
	ray->delta[1] = 0;
	ray->face = 0;
	get_delta(ray, ray->dir, game);
	init_fictional_distance(ray, ray->dir, game);

}

int is_wall2D(int j, int i, t_prog *game);
void get_resultant_vector(t_ray *ray, int array_pos, t_vector dir, t_prog *game);


void get_resultant_vector(t_ray *ray, int array_pos, t_vector dir, t_prog *game)
{
	double		factor;
	t_vector	vector;
	int			blocks_advanced;
	
	printf("steps neto : %i\n", ray->step[array_pos]);

	vector.x = 0;
	vector.y = 0;

	
	blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos];
	if (ray->dir.y < 0 && array_pos == 1)
		blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos] + 1;
	if (ray->dir.x < 0 && array_pos == 0)
		blocks_advanced = ray->step[array_pos] - ray->position_2D[array_pos] + 1;
	printf("BLoques avanzados : %i\n", blocks_advanced);


	if (!dir.x)
		vector.y = blocks_advanced * game->map2D.pixel_per_block[array_pos];
	if (!dir.y)
		vector.x = blocks_advanced * game->map2D.pixel_per_block[array_pos];
	if (!dir.x || !dir.y)
	{
		ray->resultant_vector= vector;
		return ;
	}	
	factor = dir.y / dir.x;
	if (ray->face == 2)
	{
		vector.y = blocks_advanced * game->map2D.pixel_per_block[array_pos];
		vector.x = vector.y / factor;
	}
	if (ray->face == 1)
	{
		vector.x = blocks_advanced * game->map2D.pixel_per_block[array_pos];
		vector.y = vector.x * factor;
	}
	ray->resultant_vector= vector;
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
			printf("AQUI %i\n", ray->step[1]);
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
			printf("distancia resultante\n");
			log_coor(ray->fictional_distance);
			printf("pegue resultante\n");
			log_coor_int(ray->step);
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


//poner una cmrobacion de wall al principio
t_vector	 raycast(t_vector dir, double origin[], t_prog *game)
{
	t_ray ray;

	init_ray(&ray, origin, dir, game);
	raycast_collision_routine(&ray, dir, game);

	return (ray.resultant_vector);
}

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

/** PURPOSE : Get coordinates of array. */
void update_location_map2D(t_ray *ray, double position[], t_prog *game)
{
	ray->position_2D[0] = position[0] / game->map2D.pixel_per_block[0];
	ray->position_2D[1] = position[1] / game->map2D.pixel_per_block[1];
}



#define DELTA_LIMIT 0.01
void get_delta(t_ray *ray, t_vector dir, t_prog *game)
{
	(void) game;

	if (fabs(dir.x) > DELTA_LIMIT )
		ray->delta[0] = fabs(1 / dir.x);
	if (fabs(dir.y) > DELTA_LIMIT )
		ray->delta[1] = fabs(1 / dir.y);

/* 	double m;
	double factor;

	factor = game->w2.size[0] / game->w2.size[1];

	m = dir.y / dir.x;

	double root[2];

	root[0] = pow(factor, 2) + pow(m, 2);
	root[1] = 1 + pow((1 / m), 2);

	if (dir.x > DELTA_LIMIT )
		ray->delta[0] = sqrt(root[0]);
	if (dir.y > DELTA_LIMIT )
		ray->delta[1] = sqrt(root[1]); */



	double y = ray->delta[1] * game->map2D.pixel_per_block[1];
	double x = ray->delta[0] * game->map2D.pixel_per_block[0];
	double start[2];
	double start1[2];

	start[0] = 2 * game->w2.unit[0] - 1;
	start[1] = 4 * game->w2.unit[1] - 1;
	start1[0] = 2 * game->w2.unit[0];
	start1[1] = 2 * game->w2.unit[1];

	double end[2];
	end[0] = start[0] + x;
	end[1] = start[1];
	put_lineV(start, y, RED, game);
	put_lineH(start1, end, RED, game);

}