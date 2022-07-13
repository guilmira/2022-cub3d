/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/12 16:05:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Collision conditions. */
static int	collision(t_vector ray, double low_boundry[], double high_boundry[])
{
	if (ray.x <= low_boundry[0] || ray.x >= high_boundry[0] )
		return (1);
	if (ray.y <= low_boundry[1]  || ray.y >= high_boundry[1] )
		return (1);
	return (0);
}

/** PURPOSE : Casting ray from a direction until it hits a boundry condition. */
t_vector	 cast_ray(t_vector direction, double low_boundry[], double high_boundry[])
{
	int				counter;
	t_vector		ray;

	counter = -1;
	ray = direction;
	while (++counter <= OX_WINDOW)
	{
		if (collision(ray, low_boundry, high_boundry))
			break; //PACE aqui puede petar si no encuenta break point de colision
		ray = mul_vec(direction, counter);
	}
	return (ray);
}

/** PURPOSE : Cast barrage of vector, starting outwards an going inwards. */
void cast_barrage(mlx_image_t *image, t_beam *beam, int counter, t_vector plane)
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
		ray = cast_ray(direction, beam->low_bound, beam->high_bound);
		draw_vector(image, ray, beam->position, BLUE);
		direction = get_unit_vector(resultant_right);
		ray = cast_ray(direction, beam->low_bound, beam->high_bound);
		draw_vector(image, ray, beam->position, BLUE);
		plane = sub_vec(plane, beam->plane_segment);
	}
}


/** PURPOSE : Casting beam of rays from origin. 
 * 1. Beam vector is the vision vector added to the plane.
 * 2. Get direction of beam vector. i.e: the unit vector of the beam.
 * 3. Cast ray to obstacle from unit vector of beam.
 * 4. Draw said vector.
 * 5. Recalculate plane vector and start loop. */
void cast_beam(mlx_image_t *image, t_beam *beam)
{
	
	double time_spent = 0.0;	
	clock_t begin = clock();

	cast_barrage(image, beam, beam->aperture_units, beam->plane_left);
	draw_vector(image, cast_ray(beam->vis_dir, beam->low_bound, beam->high_bound),\
	beam->position, RED);
	
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent);
}