/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/11 08:58:29 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Boolean used to stop casting of vector. */
static int	collision_condition(double x, double y, double condition_x, double condition_y)
{
	if (x >= condition_x)
		return (1);
	if (y >= condition_y)
		return (1);
	return (0);
}

/** PURPOSE : Cast direction vector until colision. */
t_vector	cast_straight(double position[], double limit[])
{
	int			j;
	double			collision_y;
	t_vector	vector;

	j = -1;
	collision_y = position[1];
	while (++j <= OY_WINDOW)
	{
		if (collision_condition(position[0], collision_y, limit[0], limit[1]))
			break ;
		collision_y = position[1] + j;
	}
	vector.x = 0;
	vector.y = j;
	return (vector);
}


void	correct_boundries(double origin[], double low_bound[], double high_bound[])
{
	low_bound[0] = 0 - origin[0];
	low_bound[1] = 0 - origin[1];
	high_bound[0] = OX_WINDOW - origin[0];
	high_bound[1] = OY_WINDOW - origin[1];
}


/* TODO block negative boundaries in vector. */

/* acos(x), asin(x), and atan(x) return the inverse cosine, inverse sine and inverse tangent of x, respectively.  Note that the result is an angle
in radians.  atan2(y, x) returns the inverse tangent of y/x in radians, with sign chosen according to the quadrant of (x,y). */


double calculate_plane_lenght(double aperture, t_vector vis)
{
	double theta;
	double vis_module;

	vis_module = get_module(vis);
	theta = degree_to_radian(aperture / 2);
	return (vis_module * tan(theta));
}

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
static void draw_vision(mlx_image_t *image, double pos_x, double pos_y, int aperture)
{
	t_vector	vis;
	t_vector	vis_dir;
	double		position[2];

	position[0] = pos_x;
	position[1] = pos_y;
	vis_dir.x = 0;
	vis_dir.y = 1;
	
	int plane_lenght;
	int aperture_units;
	

	double low_bound[2];
	double high_bound[2];
	
	correct_boundries(position, low_bound, high_bound); //consultar si esto es correcto
	vis = cast_ray(vis_dir, low_bound, high_bound);
	plane_lenght = calculate_plane_lenght(aperture, vis);
	aperture_units = (plane_lenght / RAYCAST_OFFSET) * 2;
	cast_beam(image, vis, position, low_bound, high_bound, aperture_units);
}

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void draw_player_position(mlx_image_t *image, double pos_x, double pos_y, t_prog *game)
{
	if (pos_x < 0 || pos_y < 0)
		ft_shutdown(EX, game);
	draw_centered_rectangle(image, pos_x, pos_y, x_size, y_size); //TODO, no esta centrando exacto
	draw_vision(image, pos_x, pos_y, FOV_DEGREE);
}