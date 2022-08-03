/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/03 13:32:20 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Casting ray from a direction until it hits a boundry condition. */
t_vector	 cast_ray(t_vector direction, double position[], double low_boundry[], double high_boundry[], t_prog *game)
{
	int				counter;
	t_vector		ray;

	(void) game;
	counter = -1;
	ray = direction;
	(void) position;
	
	while (++counter <= game->w2.size[0])
	{
		/* if (collision_wall(ray, position, game))
			break; */
		if (collision_window(ray, low_boundry, high_boundry))
			break;
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