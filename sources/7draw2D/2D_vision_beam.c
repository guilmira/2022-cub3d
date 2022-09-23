/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_vision_beam.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:42:03 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/23 07:50:19 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Calculate segment base on division. */
static inline t_vector	calculate_plane_segment(t_vector plane_left, int number_of_rays)
{
	t_vector	segment;

	segment.x = plane_left.x / number_of_rays;
	segment.y = plane_left.y / number_of_rays;
	return (segment);
}

/** PURPOSE : Init beam as a straight vector pointing north. */
static inline void	init_beam(t_beam *beam, double position[], \
t_vector dir, t_prog *game)
{
	(void) game;
	beam->vis_dir = dir;
	beam->plane_left.x = -1;
	beam->plane_left.y = 0;
	beam->plane_right.x = 1;
	beam->plane_right.y = 0;
	beam->position[0] = position[0];
	beam->position[1] = position[1];
}

/** PURPOSE : Initialize pointers to contain raycast information
 * (for later drawing).*/
static inline void	init_struct_raycast(int number_of_rays, double position[], \
t_vector vision, t_prog *game)
{
	t_raycast	*rc;
	size_t		heap_size;

	heap_size = (size_t) number_of_rays + VISION_RAY;
	rc = ft_calloc(1, sizeof(t_raycast));
	rc->rc_vector = ft_calloc(heap_size, sizeof(t_vector));
	rc->rc_distance = ft_calloc(heap_size, sizeof(double));
	rc->rc_wall_side = ft_calloc(heap_size, sizeof(int));
	rc->rc_wall_hit_x = ft_calloc(heap_size, sizeof(int));
	rc->rc_wall_hit_y = ft_calloc(heap_size, sizeof(int));
	rc->rc_origin_coor[0] = position[0];
	rc->rc_origin_coor[1] = position[1];
	rc->number_of_rays = number_of_rays;
	rc->vision = vision;
	game->rc = rc;
}

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. 
 * 3. Find out plane x vector. ( <---------------- ).*/
void	main_raycast_calculation(int angle, t_prog *game)
{
	t_beam		beam;
	double		plane_lenght;
	double		rays;
	t_data		aux;

	clear_raycast(game);
	init_beam(&beam, game->pl.position_coor, game->pl.vis, game);
	beam.vis = raycast(&aux, beam.vis_dir, beam.position, game);
	aux.vector = beam.vis;
	plane_lenght = plane_lenght_and_direction(&beam, angle);
	rays = game->w1.size[0];
	beam.number_of_rays = (int) roundl(rays);
	init_struct_raycast(beam.number_of_rays, beam.position, beam.vis, game);
	beam.plane_segment = calculate_plane_segment(beam.plane_left, beam.number_of_rays / 2);
	cast_beam(&beam, &aux, game);
	game->pl.beam = beam;
	game->pl.flag_movement = 0;
}
