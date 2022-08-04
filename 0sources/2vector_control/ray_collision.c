/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:30:25 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/04 13:28:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define PROVISIONAL_OFFSET 20

/** PURPOSE : Is coordinate on the overall screen a wall?. */
int is_wall(double coor[], t_prog *game)
{
	int j;
	int i;

	static int calcu;
	printf("caLc: %i\n", ++calcu);


	i = coor[0] / game->map2D.pixel_per_block[0];
	j = coor[1] / game->map2D.pixel_per_block[1];
	j = game->map2D.height - 1 - j;

	if (j < 0)
		j = 0;
	if (game->map2D.layout[j][i])
		return (1);
	else
		return (0);
	
}

/** PURPOSE : Ray vector actual coordinates in pixel map. */
void	ray_coordinates(t_vector ray, double position[], double coor[])
{
	coor[0] = ray.x + position[0];
	coor[1] = ray.y + position[1];
}

/** PURPOSE : Collision conditions. */
int	collision_wall(t_vector ray, double position[], t_prog *game)
{
	double coor[D2];

	ray_coordinates(ray, position, coor);
	if (is_wall(coor, game))
		return (1);
	else
		return (0);
}

/** PURPOSE : Collision condition for window. */
int	collision_window(t_vector ray, double low_boundry[], double high_boundry[])
{
	//vector rojo es el que se sale
	//PACE set boundries and safe offset correctly.
	if (ray.x <= low_boundry[0] || ray.x >= high_boundry[0])
		return (1);
	if (ray.y <= low_boundry[1] + PROVISIONAL_OFFSET || ray.y >= high_boundry[1] + PROVISIONAL_OFFSET )
		return (1);
	return (0);
}