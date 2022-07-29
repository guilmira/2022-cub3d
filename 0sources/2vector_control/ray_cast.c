/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/22 17:30:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Collision conditions. */

/*double	calculate_col(t_vector direction, t_prog *game, double stable, int flag)
{
	if (flag == 'x')
	{
		if (direction.x == 0)
			return (0);
		return (round((direction.y/direction.x) * (stable - game->pl.position[1]) + game->pl.position[0]));
	}
	else if (flag == 'y')
	{
		if (direction.y == 0)
			return (0);
		return (round((direction.x/direction.y) * (stable - game->pl.position[0]) + game->pl.position[1]));
	}
	return (0);
}

double	get_colision_x(t_vector direction, t_prog *game, double stable)
{
	double  collision;
	int		y;
	int		x;
	double	start;
	double	finish;

	printf("dir:%f y %f ; game: %f, %f ; stable %f\n", direction.x, direction.y, game->pl.position[0], game->pl.position[1], stable);
	collision = calculate_col(direction, game, stable, 'x');
	if (collision == 0)
		return (-1);
	 y = round(((stable + round(game->w2.pixel_per_block[1]/2))) / game->w2.pixel_per_block[1]);
	start = 0;
	finish = game->w2.pixel_per_block[0];
	x = 0;
	while (x < game->map_x)
	{
		if (collision >= start && collision <= finish)
			break;
		x++;
		start = finish;
		finish += game->w2.pixel_per_block[0];
	}
	if (game->map[y][x] == '1')
		return(collision);
	return (0);
}

double	get_colision_y(t_vector direction, t_prog *game, double stable)
{
	double  collision;
	int		y;
	int		x;
	double	start;
	double	finish;

	collision = calculate_col(direction, game, stable, 'y');
	if (collision == 0)
		return (-1);
	x = round((stable + round(game->w2.pixel_per_block[0]/2)) / game->w2.pixel_per_block[0]);
	start = 0;
	finish = game->w2.pixel_per_block[1];
	y = 0;
	while (y < game->map_y)
	{
		if (collision >= start && collision <= finish)
			break;
		y++;
		start = finish;
		finish += game->w2.pixel_per_block[1];
	}
	y = game->map_y - y;
	if (game->map[y][x] == '1')
		return(collision);
	return (0);
}

int	check_length(double x[], double y[], t_prog *game)
{	
	double len_x;
	double len_y;

	len_x = sqrt(pow((x[0] - game->pl.position[0]), 2) +  pow((x[1] - game->pl.position[1]), 2));
	len_y = sqrt(pow((y[0] - game->pl.position[0]), 2) +  pow((y[1] - game->pl.position[1]), 2));
	if (len_x < len_y)
		return('x');
	else
		return('y');
}*/
/*
static int	collision(t_vector ray, t_prog *game)
{
	int coord[2];

	coord[0] = round(ray.x / game->w2.pixel_per_block[0]);
	coord[1] =  game->map_y - round(ray.y / game->w2.pixel_per_block[0]);
	if (game->map[coord[1]][coord[2]] == '1')
		return(1);
	return(0);
}
*/
/** PURPOSE : Casting ray from a direction until it hits a boundry condition. */
t_vector	 cast_ray(t_vector direction, t_prog *game)
{
	int				counter;
	t_vector		ray;

	(void) game;
	counter = -1;
	ray = direction;
	while (++counter <= game->w2.size[0])
	{
		/*if (collision(ray, game))
			break; //PACE aqui puede petar si no encuenta break point de colision*/
		ray = mul_vec(direction, counter);
	}
	return (ray);
}

/** PURPOSE : Cast barrage of vector, starting outwards an going inwards. */
void cast_barrage(t_beam *beam, int counter, t_vector plane, t_prog *game)
{
	t_vector ray;
	t_vector resultant_left;
	t_vector resultant_right;
	t_vector direction;

	while (counter-- > 0)
	{
		resultant_left = sum_vec(beam->vis, plane);
		resultant_right = sub_vec(beam->vis, plane);
		direction = get_unit_vector(resultant_left);
		ray = cast_ray(direction, game);
		draw_vector(ray, beam->position, BLUE, game);
		direction = get_unit_vector(resultant_right);
		ray = cast_ray(direction, game);
		draw_vector(ray, beam->position, BLUE, game);
		plane = sub_vec(plane, beam->plane_segment);
	}
}


/** PURPOSE : Casting beam of rays from origin. 
 * 1. Beam vector is the vision vector added to the plane.
 * 2. Get direction of beam vector. i.e: the unit vector of the beam.
 * 3. Cast ray to obstacle from unit vector of beam.
 * 4. Draw said vector.
 * 5. Recalculate plane vector and start loop. */
void cast_beam(t_beam *beam, t_prog *game)
{
	
	/* double time_spent = 0.0;	
	clock_t begin = clock(); */

	cast_barrage(beam, beam->aperture_units, beam->plane_left, game);
	

	draw_vector(beam->vis,\
	beam->position, RED, game);
	
	/* clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */
}