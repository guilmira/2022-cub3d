/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/12 14:35:04 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Total horizontal plane lenght. 
 * 1. Get module of vision vector. 
 * 2. Pass it to radian. 
 * 3. tan(thetha) = opposite/ adyacent
 * 4. Therefore: result = adyacent * tan(thetha) */ 
static double calculate_plane_lenght(double aperture, t_vector vis)
{
	double theta;
	double vis_module;

	vis_module = get_module(vis);
	theta = degree_to_radian(aperture / 2);
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
static int calculate_aperture_units(double aperture, t_vector vis, int ray_offset)
{
	int		aperture_units;
	double	plane_lenght;

	plane_lenght = calculate_plane_lenght(aperture, vis);
	aperture_units = (int) (plane_lenght / ray_offset) * 2;
	return (aperture_units);
}

/** PURPOSE : Get plane vector, perpendicular to vision vector,
 * but is treated as only half of the plane. */
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

/** PURPOSE : Calculate segment base on division. */
static t_vector calculate_plane_segment(t_vector plane_left, int aperture_units)
{
	t_vector segment;

	segment.x = plane_left.x / aperture_units;
	segment.y = plane_left.y / aperture_units;
	if (segment.x < 0)
		segment.x *= -1;
	if (segment.y < 0)
		segment.x *= -1;
	return (segment);
}

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. 
 * 3. Find out plane x vector. ( <---------------- ).*/
static void draw_vision(mlx_image_t *image, double position[], int angle)
{
	t_beam		beam;

	init_beam(&beam, position);
	beam.vis = cast_ray(beam.vis_dir, beam.low_bound, beam.high_bound);
	beam.aperture_units = calculate_aperture_units(angle, beam.vis, RAYCAST_OFFSET);
	beam.plane_left = get_plane_vector(beam.vis, beam.aperture_units);
	beam.plane_right = invert_sense_vector(beam.plane_left);
	beam.plane_segment = calculate_plane_segment(beam.plane_left, beam.aperture_units); 
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
	draw_centered_rectangle(image, position[0], position[1], x_size, y_size);
	draw_vision(image, position, FOV_DEGREE);

}