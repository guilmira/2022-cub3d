/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dcast_beam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 11:14:20 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_vector	 raycast(t_vector dir, double origin[], t_prog *game);

/** PURPOSE : Cast barrage of vector, starting outwards an going inwards. */
void raycast_barrage(t_beam *beam, int counter, t_vector plane, t_prog *game)
{
	t_vector	ray;
	t_vector	resultant;
	t_vector	direction;
	int			i;
	
	i = -1;
	//while (counter-- > 0)
	while (++i < counter)
	{
	/* ----------CALCULO----------------------------------------------------- */
		resultant = sum_vec(beam->vis, plane);
		direction = get_unit_vector(resultant);
		ray = raycast(direction, beam->position, game);
	/* ----------REPRESENTACION GRAFICA----------------------------------------------------- */
		if (i < game->rc->number_of_rays)
			game->rc->rc_vector[i] = ray;

		//draw_vector(ray, beam->position, RED, game);
	/* ----------CALCULO----------------------------------------------------- */
		resultant = sub_vec(beam->vis, plane);
		direction = get_unit_vector(resultant);
		ray = raycast(direction, beam->position, game);
	/* ----------REPRESENTACION GRAFICA----------------------------------------------------- */
		if (i < game->rc->number_of_rays)
			game->rc->rc_vector[counter + (counter - 1) - i] = ray;
		
		//draw_vector(ray, beam->position, RED, game);

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
	/* --------ACTUAL----------------------------------------------------- */
	raycast_barrage(beam, beam->number_of_rays, beam->plane_left, game);
	/* --------ACTUAL----------------------------------------------------- */

/* 	double time_spent = 0.0;	
	clock_t begin = clock(); */
/* 	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */
}