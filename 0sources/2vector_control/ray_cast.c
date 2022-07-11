/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/11 12:59:04 by guilmira         ###   ########.fr       */
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
t_vector	cast_ray(t_vector direction, double low_boundry[], double high_boundry[])
{
	int				counter;
	t_vector		ray;

	counter = -1;
	ray = direction;
	while (++counter <= OX_WINDOW)
	{
		if (collision(ray, low_boundry, high_boundry))
			break;
		ray = mul_vec(direction, counter);
	}
	return (ray);
}



t_vector get_plane_vector(t_vector vis, double aperture_units)
{
	int			module;
	t_vector	perpendicular;
	t_vector	perpendicular_dir;

	module = (aperture_units / 2) * RAYCAST_OFFSET;
	perpendicular = get_perpendicular(vis);
	perpendicular_dir = get_unit_vector(perpendicular);
	return (mul_vec(perpendicular_dir, module));
}

/** PURPOSE : Casting beam of rays from origin. 
 * 1. Find out plane x vector. ( <---------------- ).
 * 2. Beam vector is the vision vector added to the plane.
 * 3. Get direction of beam vector. i.e: the unit vector of the beam.
 * 4. Cast ray to obstacle from unit vector of beam.
 * 5. Draw said vector.
 * 6. Rcalculate plane vector and start loop. */
void cast_beam(mlx_image_t *image, t_vector vis, t_beam *beam_dim, double aperture_units, t_prog *game)
{
	t_vector	beam;
	t_vector	plane;
	t_vector	direction;
	t_vector	ray;

	double time_spent = 0.0;	
	clock_t begin = clock();
	
	coor_identifier(image, game, 100, 300, OY_MINIMAP, 0);

	plane.x = vis.x - (aperture_units / 2) * RAYCAST_OFFSET; 
	plane.y = 0;
	//draw_vector(image, ray, beam_dim->position);
	plane = get_plane_vector(vis, aperture_units);
	log_vector(plane);
	aperture_units++;
	while (aperture_units-- > 0)
	{
		beam = sum_vec(vis, plane);
		direction = get_unit_vector(beam);
		ray = cast_ray(direction, beam_dim->low_bound, beam_dim->high_bound);
		draw_vector(image, ray, beam_dim->position);
		plane.x += RAYCAST_OFFSET;
	}

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent);
}