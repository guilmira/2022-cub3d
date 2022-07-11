/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/11 12:55:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Set limits for collisions of vectors. */
static void	correct_boundries(t_beam *beam, double position[])
{
	beam->position[0] = position[0];
	beam->position[1] = position[1];
	beam->low_bound[0] = 0 - beam->position[0];
	beam->low_bound[1] = 0 - beam->position[1];
	beam->high_bound[0] = OX_WINDOW - beam->position[0];
	beam->high_bound[1] = OY_WINDOW - beam->position[1];
}

/** PURPOSE : Total horizontal plane lenght. */ 
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
 * --- ^ --- ^ --- ^ ---     : 
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

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
static void draw_vision(mlx_image_t *image, t_prog *game, double position[], int aperture)
{
	t_vector	vis;
	t_vector	vis_dir;
	t_beam		beam_dim;
	int			aperture_units;

	vis_dir.x = 0;
	vis_dir.y = 1;
	correct_boundries(&beam_dim, position);


	vis = cast_ray(vis_dir, beam_dim.low_bound, beam_dim.high_bound);
	aperture_units = calculate_aperture_units(aperture, vis, RAYCAST_OFFSET);
	cast_beam(image, vis, &beam_dim, aperture_units, game);
}

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void draw_player_position(mlx_image_t *image, double position[], t_prog *game)
{
	if (position[0] < 0 || position[1] < 0)
		ft_shutdown(EX, game);
	coor_identifier(image, game, 10, 100, OY_MINIMAP, 0);

	draw_centered_rectangle(image, position[0], position[1], x_size, y_size);
	draw_vision(image, game, position, FOV_DEGREE);

}