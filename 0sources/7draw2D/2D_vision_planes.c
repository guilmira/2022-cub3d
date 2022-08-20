/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_vision_planes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:14:20 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 12:18:38 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


/** PURPOSE : Get plane vector, perpendicular to vision vector,
 * but is treated as only half of the plane. */
t_vector	get_plane_vector(t_vector vis, double plane_lenght)
{
	int			module;
	t_vector	perpendicular;
	t_vector	perpendicular_dir;

	module = plane_lenght;
	perpendicular = get_perpendicular(vis);
	perpendicular_dir = get_unit_vector(perpendicular);
	return (mul_vec(perpendicular_dir, module));
}

/** PURPOSE : Total horizontal plane lenght. 
 * 1. Get module of vision vector. 
 * 2. Pass it to radian. 
 * 3. tan(thetha) = opposite/ adyacent
 * 4. Therefore: result = adyacent * tan(thetha) */
static double	calculate_plane_lenght(double angle, t_vector vis)
{
	double	theta;
	double	vis_module;

	vis_module = get_module(vis);
	theta = degree_to_radian(angle / 2);
	return (vis_module * tan(theta));
}

double	plane_lenght_and_direction(t_beam *beam, int angle)
{
	double	plane_lenght;

	plane_lenght = calculate_plane_lenght(angle, beam->vis);
	beam->plane_left = get_plane_vector(beam->vis, plane_lenght);
	beam->plane_right = invert_sense_vector(beam->plane_left);
	return (plane_lenght);
}
