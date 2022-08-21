/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dcast_beam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/21 21:19:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : BARRAGE ALGORITHM.
 * * 1. Counter is the number of rays. Loop will be execcuted one time for each ray.
 * 2. Resultant vector is obtained by adding vision vector and plane vector.
 * 3. Unitary vector (direction) is calculated.
 * 4. Apply raycast collision algorithm to step 3 vector.
 * 5. The mirror vector (left side) is calulated the same way (but substracting). */
void	raycast_barrage(t_beam *beam, int counter, t_vector plane, t_prog *game)
{
	t_vector	ray;
	t_vector	resultant;
	t_vector	direction;
	int			i;
	int face;

	ray.x = 0;
	ray.y = 0;

	i = -1;
	while (++i < counter)
	{
		resultant = sum_vec(beam->vis, plane);
		direction = get_unit_vector(resultant);
		ray = raycast(&face, direction, beam->position, game);
		if (i < game->rc->number_of_rays)
		{
			game->rc->rc_vector[i] = ray;
			game->rc->rc_distance[i] = get_module(ray);
			game->rc->rc_wall_side[i] = face;
		}
	/* --------RESTAR SEGMENTO Y REPETIR----------------------------------------------------- */
		resultant = sub_vec(beam->vis, plane);
		direction = get_unit_vector(resultant);
		ray = raycast(&face, direction, beam->position, game);
		if (i < game->rc->number_of_rays)
		{
			game->rc->rc_vector[counter + (counter - 1) - i] = ray;
			game->rc->rc_distance[counter + (counter - 1) - i] = get_module(ray);
			game->rc->rc_wall_side[counter + (counter - 1) - i] = face;
		}
		plane = sub_vec(plane, beam->plane_segment);
	}
}

/** PURPOSE : Casting beam of rays from origin. 
 The barrage its what we call the rapid succesion of vectors calculated from 
 left to right and that they generate the beam. */
void	cast_beam(t_beam *beam, t_prog *game)
{
	raycast_barrage(beam, beam->number_of_rays, beam->plane_left, game);
}

/* 	double time_spent = 0.0;	
	clock_t begin = clock(); */
	/* 	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */