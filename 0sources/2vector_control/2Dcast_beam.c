/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2Dcast_beam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/11 12:26:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_vector	 raycast(t_vector dir, double origin[], t_prog *game);

/** PURPOSE : Cast barrage of vector, starting outwards an going inwards. */
static void raycast_barrage(t_beam *beam, int counter, t_vector plane, t_prog *game)
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
		ray = raycast(direction, beam->position, game);
	/* ----------REPRESENTACION GRAFICA----------------------------------------------------- */
		draw_vector(ray, beam->position, RED, game);
	/* ----------CALCULO----------------------------------------------------- */
		resultant_right = sub_vec(beam->vis, plane);
		direction = get_unit_vector(resultant_right);
		ray = raycast(direction, beam->position, game);
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
	
/* 	double time_spent = 0.0;	
	clock_t begin = clock(); */


	//PARA BORRAR LLEGADO EL MOMENTO
	//cast_barrage(beam, beam->aperture_units, beam->plane_left, game);

	/* --------ACTUAL----------------------------------------------------- */
	raycast_barrage(beam, beam->aperture_units, beam->plane_left, game);
	draw_vector(beam->vis, beam->position, RED, game);
	/* --------ACTUAL----------------------------------------------------- */
	

/* 	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */
}