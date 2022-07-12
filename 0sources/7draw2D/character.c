/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/12 16:07:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Total horizontal plane lenght. 
 * 1. Get module of vision vector. 
 * 2. Pass it to radian. 
 * 3. tan(thetha) = opposite/ adyacent
 * 4. Therefore: result = adyacent * tan(thetha) */ 
static double calculate_plane_lenght(double angle, t_vector vis)
{
	double theta;
	double vis_module;

	vis_module = get_module(vis);
	theta = degree_to_radian(angle / 2);
	return (vis_module * tan(theta));
}

/** PURPOSE : Calculate, given a plane lenght, how many pixels
 * are gonna divide given plane.
 * 
 * --- ^ --- ^ --- ^ ---      
 *     |     |     |
 *     |     |     | 
 *     |     |     |
 * aperture units = 3 */
static double calculate_aperture_units(double plane_lenght, double ray_offset)
{
	double		aperture_units;
	aperture_units = (double) (plane_lenght / ray_offset);
	return (aperture_units);
}

/** PURPOSE : Get plane vector, perpendicular to vision vector,
 * but is treated as only half of the plane. */
t_vector get_plane_vector(t_vector vis, double plane_lenght)
{
	int			module;
	t_vector	perpendicular;
	t_vector	perpendicular_dir;

	module = plane_lenght;
	perpendicular = get_perpendicular(vis);
	perpendicular_dir = get_unit_vector(perpendicular);
	return (mul_vec(perpendicular_dir, module));
}

/** PURPOSE : Calculate segment base on division. */
static t_vector calculate_plane_segment(t_vector plane_left, int aperture_units)
{
	t_vector segment;

	segment.x = plane_left.x / aperture_units;
	segment.y = plane_left.y / aperture_units;
	return (segment);
}

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. 
 * 3. Find out plane x vector. ( <---------------- ).*/
static void draw_vision(mlx_image_t *image, double position[], t_vector dir, int angle)
{
	t_beam		beam;
	double		plane_lenght;

	init_beam(&beam, position, dir);
	//ESTE PRIMER RAYO EN REALIDAD HAY QUE TIRARLO A LOS LIMITES DE LA VENTANA
	beam.vis = cast_ray(beam.vis_dir, beam.low_bound, beam.high_bound);
	
	plane_lenght = calculate_plane_lenght(angle, beam.vis);
	beam.aperture_units = calculate_aperture_units(plane_lenght, RAYCAST_OFFSET);
	beam.aperture_units = roundl(beam.aperture_units);
	beam.plane_left = get_plane_vector(beam.vis, plane_lenght);
	beam.plane_right = invert_sense_vector(beam.plane_left);
	beam.plane_segment = calculate_plane_segment(beam.plane_left, beam.aperture_units); 
	//log_vector(beam.plane_right);
	cast_beam(image, &beam);
}

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void draw_player_position(mlx_image_t *image, double position[], t_prog *game)
{
	if (position[0] < 0 || position[1] < 0)
		ft_shutdown(EX, game);
	//coor_identifier(image, game, 10, 100, OY_MINIMAP, 0);
	//draw_centered_rectangle(image, position[0], position[1], x_size, y_size);
	t_vector dir;

	dir.x = 1;
	dir.y = 1;
	draw_vision(image, position, dir, FOV_DEGREE);
}