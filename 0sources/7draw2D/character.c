/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/11 06:46:28 by guilmira         ###   ########.fr       */
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

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
static void draw_vision(mlx_image_t *image, double pos_x, double pos_y, int aperture)
{
	t_vector	vis;
	double		position[2];
	double		limit[2];

	position[0] = pos_x;
	position[1] = pos_y;
	limit[0] = OX_WINDOW;
	limit[1] = OY_WINDOW;
	aperture = 0;

	t_vector new;
	new.x = 0;
	new.y = 1;

	double low_bound[2];
	double high_bound[2];
	correct_boundries(position, low_bound, high_bound); //consultar si esto es correcto

	printf("%f y %f\n", position[0], position[1]);
	printf("%f y %f\n", low_bound[0], high_bound[0]);

	//vis = cast_straight(position, limit);

	vis = cast_ray(new, low_bound, high_bound);
	draw_vector(image, vis, position);

	printf("aqui vamos \n");

	cast_beam(image, vis, position, low_bound, high_bound, 50);


}

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void draw_player_position(mlx_image_t *image, double pos_x, double pos_y, t_prog *game)
{
	if (pos_x < 0 || pos_y < 0)
		ft_shutdown(EX, game);
	draw_centered_rectangle(image, pos_x, pos_y, x_size, y_size); //TODO, no esta centrando exacto
	draw_vision(image, pos_x, pos_y, VISION_ANGLE);
}