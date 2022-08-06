/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:30:25 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/06 07:22:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define PROVISIONAL_OFFSET 20


int is_wall(double coor[], t_prog *game);
void	ray_coordinates(t_vector ray, double position[], double coor[]);


#define RANGE 1

int needs_collision_check(t_vector ray, t_grid *grid, t_prog *game)
{
	(void) game;
	if (ray.x >= grid->distance[0] - RANGE && ray.x <= grid->distance[0] + RANGE)
		return 1;
	else if (ray.y >= grid->distance[1] - RANGE && ray.y <= grid->distance[1] + RANGE)
		return 1;
	else
		return (0);

	/* if (ray.y == grid->distance_y)
		return 1; */
}

/** PURPOSE : Collision conditions. */
int	collision_wall_trigonometric(t_vector ray, double position[], t_grid *grid, t_prog *game)
{
	double coor[D2];

	if (needs_collision_check(ray, grid, game))
	{
		coor[0]++;
		coor[1]++;
		ray_coordinates(ray, position, coor);
		if (is_wall(coor, game))
			return (1);
	}
	return (0);
}





void calculate_partial(t_grid *grid, double position[], t_vector direction, t_prog *game)
{
	(void) direction;
	(void) position;

	grid->partial[0] = game->map2D.pixel_per_block[0] - (game->pl.position_coor[0] - game->pl.position[0] * game->map2D.pixel_per_block[0]);
	grid->partial[1] = game->map2D.pixel_per_block[1] - (game->pl.position_coor[1] - game->pl.position[1] * game->map2D.pixel_per_block[1]);
	/* Cuando esta en el medio
	grid->partial[0] = game->map2D.pixel_per_block[0] / 2;
	grid->partial[1] = game->map2D.pixel_per_block[1] / 2; */
}

void calculate_delta(t_grid *grid, double position[], t_vector direction, t_prog *game)
{
	(void) direction;
	(void) position;
	grid->delta[0] = game->map2D.pixel_per_block[0];
	grid->delta[1] = game->map2D.pixel_per_block[1];

	
}

void update_distance(t_grid *grid, int array_pos)
{
	int factor;

	factor = grid->blocks[array_pos];
	grid->distance[array_pos] = (factor *  grid->delta[array_pos]) + grid->partial[array_pos];
}

t_grid calculate_grid_parameters(double position[], t_vector direction, t_prog *game)
{
	t_grid grid;

	grid.blocks[0] = 0;
	grid.blocks[1] = 0;
	calculate_partial(&grid, position, direction, game);
	calculate_delta(&grid, position, direction, game);
	update_distance(&grid, 0);
	update_distance(&grid, 1);
	return (grid);
}

/** PURPOSE : Casting ray from the coordinate position.
 * 1. The cast follows the direction given as an argument. 
 * 2. Stops when it hits boundry condition. */
void update_grid(t_grid *grid, t_vector ray, double position[], t_prog *game)
{
	(void) game;
	(void) position;
	if (ray.x >= grid->distance[0])
	{
		grid->blocks[0]++;
		update_distance(grid, 0);
	}
	if (ray.y >= grid->distance[1])
	{
		grid->blocks[1]++;
		update_distance(grid, 1);
	}
}