/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/04 14:20:06 by guilmira         ###   ########.fr       */
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
	 y = round(((stable + round(game->map2D.pixel_per_block/2))) / game->map2D.pixel_per_block);
	start = 0;
	finish = game->map2D.pixel_per_block;
	x = 0;
	while (x < game->map_x)
	{
		if (collision >= start && collision <= finish)
			break;
		x++;
		start = finish;
		finish += game->map2D.pixel_per_block;
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
	x = round((stable + round(game->map2D.pixel_per_block/2)) / game->map2D.pixel_per_block);
	start = 0;
	finish = game->map2D.pixel_per_block;
	y = 0;
	while (y < game->map_y)
	{
		if (collision >= start && collision <= finish)
			break;
		y++;
		start = finish;
		finish += game->map2D.pixel_per_block;
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
/*static int	collision_provisional(t_vector ray, t_prog *game)
{
	int coord[2];

	coord[0] = round(ray.x / game->map2D.pixel_per_block);
	coord[1] =  game->map_y - round(ray.y / game->map2D.pixel_per_block);
	if (game->map[coord[1]][coord[2]] == '1')
		return(1);
	return(0);
}*/


void update_grid(t_grid *grid, t_vector ray, double position[], t_prog *game);
t_grid calculate_grid_parameters(double position[], t_vector direction, t_prog *game);


/** PURPOSE : Casting ray from the coordinate position.
 * 1. The cast follows the direction given as an argument. 
 * 2. Stops when it hits boundry condition. */
t_vector	 cast_ray(t_vector direction, double position[], double low_boundry[], double high_boundry[], t_prog *game)
{
	int				counter;
	t_vector		ray;

	(void) game;
	counter = -1;
	ray = direction;
	(void) position;

	/* FED AS ARGUMENT */
	t_grid grid;
	grid = calculate_grid_parameters(position, direction, game);
	//printf("%i\n", game->map2D.pixel_per_block[1]); 154

	while (++counter <= game->w2.size[0])
	{
		/* if (collision_wall(ray, position, game))
			break; */
		if (collision_wall_trigonometric(ray, position, &grid, game))
			break;
		if (collision_window(ray, low_boundry, high_boundry))
			break;
		ray = mul_vec(direction, counter); //se podria multiplicar de mas en mas cantidades.
		update_grid(&grid, ray, position, game);
		
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
	/* ----------CALCULO----------------------------------------------------- */
		resultant_left = sum_vec(beam->vis, plane);
		direction = get_unit_vector(resultant_left);
		ray = cast_ray(direction, beam->position, beam->low_bound, beam->high_bound, game);
	/* ----------REPRESENTACION GRAFICA----------------------------------------------------- */
		draw_vector(ray, beam->position, RED, game);
	/* ----------CALCULO----------------------------------------------------- */
		resultant_right = sub_vec(beam->vis, plane);
		direction = get_unit_vector(resultant_right);
		ray = cast_ray(direction, beam->position, beam->low_bound, beam->high_bound, game);
	/* ----------REPRESENTACION GRAFICA----------------------------------------------------- */
		draw_vector(ray, beam->position, RED, game);
	/* --------RESTAR SEGMENTO Y REPETIR----------------------------------------------------- */
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
	draw_vector(beam->vis, beam->position, RED, game);
	
	/* clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */
}