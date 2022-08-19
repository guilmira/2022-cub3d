/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_vision_beam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:42:03 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/19 14:14:26 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Calculate segment base on division. */
static t_vector calculate_plane_segment(t_vector plane_left, int number_of_rays)
{
	t_vector segment;

	segment.x = plane_left.x / number_of_rays;
	segment.y = plane_left.y / number_of_rays;
	return (segment);
}

/** PURPOSE : Calculate, given a plane lenght, how many rays are casted.
 * 
 * ---- ^ ---- ^ ---- ^ ----      
 *      |      |      |
 *      |      |      | 
 *      |      |      |
 * rayoffset = 4 ( - ) */
static double calculate_number_of_rays(double plane_lenght, double ray_offset)
{
	double	aperture_units;

	aperture_units = (double) (plane_lenght / ray_offset);
	return (aperture_units);
}


void	init_struct_raycast(int size, t_prog *game)
{
	t_raycast	*rc;
	size_t		heap_size;

	heap_size = (size_t) size;
	printf("SIZE %i\n", size);
	rc = ft_calloc(1, sizeof(t_raycast));
	rc->rc_vector = ft_calloc(heap_size, sizeof(t_vector));
	rc->rc_distance = ft_calloc(heap_size, sizeof(double));
	rc->rc_wall_side = ft_calloc(heap_size, sizeof(int));

	game->rc = rc;
}

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. 
 * 3. Find out plane x vector. ( <---------------- ).*/
void draw_vision_beam(double position[], t_vector vis, int angle, int ray_offset, t_prog *game)
{
	t_beam		beam;
	double		plane_lenght;
	double		rays;

	clear_raycast(game);
	init_beam(&beam, position, vis, game);
	beam.vis = raycast(beam.vis_dir, beam.position, game);
	plane_lenght = plane_lenght_and_direction(&beam, angle);
	rays = calculate_number_of_rays(plane_lenght, (double) ray_offset);
	beam.number_of_rays = (int) roundl(rays);
	init_struct_raycast(beam.number_of_rays * 2, game);
	beam.plane_segment = calculate_plane_segment(beam.plane_left, beam.number_of_rays); 
	cast_beam(&beam, game);
	game->pl.beam = beam;
	game->pl.flag_movement = 0;

}