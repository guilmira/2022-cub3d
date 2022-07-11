/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 06:04:39 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/11 06:43:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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

void cast_beam(mlx_image_t *image, t_vector vis, double position[], double low_bound[], double high_bound[], int aperture_units)
{
	int counter;
	t_vector beam;
	t_vector plane;
	t_vector  direction;
	t_vector  ray;


	counter = -1;
	plane.x = 0 - aperture_units / 2; 
	plane.y = 0;
	beam = sub_vec(vis, plane);
	direction = get_unit_vector(beam);
	while (++counter < aperture_units)
	{
		ray = cast_ray(direction, low_bound, high_bound);
		draw_vector(image, ray, position);
		
		plane.x = plane.x + counter; 
		beam = sub_vec(vis, plane);
		direction = get_unit_vector(beam);
	}
}