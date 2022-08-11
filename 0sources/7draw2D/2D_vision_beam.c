/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_vision_beam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:42:03 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/11 12:30:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Calculate segment base on division. */
static t_vector calculate_plane_segment(t_vector plane_left, int aperture_units)
{
	t_vector segment;

	segment.x = plane_left.x / aperture_units;
	segment.y = plane_left.y / aperture_units;
	return (segment);
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

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. 
 * 3. Find out plane x vector. ( <---------------- ).*/
void draw_vision_beam(double position[], t_vector vis, int angle, int ray_offset, t_prog *game)
{
	t_beam		beam;
	double		plane_lenght;

	init_beam(&beam, position, vis, game);
	beam.vis = raycast(beam.vis_dir, beam.position, game);
	plane_lenght = plane_lenght_and_direction(&beam, angle);
	beam.aperture_units = calculate_aperture_units(plane_lenght, (double) ray_offset);
	beam.aperture_units = roundl(beam.aperture_units);
	beam.plane_segment = calculate_plane_segment(beam.plane_left, beam.aperture_units); 
	cast_beam(&beam, game);
	game->pl.beam = beam;
	game->pl.flag_movement = 0;

}