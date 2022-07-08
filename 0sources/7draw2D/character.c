/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/08 13:47:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



/** PURPOSE : Boolean used to stop casting of vector. */
static int	collision_condition(int x, int y, int condition_x, int condition_y)
{
	if (x >= condition_x)
		return (1);
	if (y >= condition_y)
		return (1);
	return (0);
}

/** PURPOSE : Cast direction vector until colision. */
t_vector	cast_straight(int pos_x, int pos_y)
{
	int			j;
	int			collision_y;
	t_vector	vector;

	j = -1;
	collision_y = pos_y;
	while (++j <= OY_WINDOW)
	{
		if (collision_condition(pos_x, collision_y, OX_WINDOW, OY_WINDOW))
			break ;
		collision_y = pos_y + j;
	}
	vector.x = 0;
	vector.y = j;
	return (vector);
}


/* acos(x), asin(x), and atan(x) return the inverse cosine, inverse sine and inverse tangent of x, respectively.  Note that the result is an angle
in radians.  atan2(y, x) returns the inverse tangent of y/x in radians, with sign chosen according to the quadrant of (x,y). */

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
/* static void draw_vision(mlx_image_t *image, float pos_x, float pos_y, int aperture)
{
	t_vector	direction;

	aperture = 0;
	direction = cast_straight(pos_x, pos_y);
	draw_vector(image, direction, pos_x, pos_y);
	direction.x = 700;//ver que pasa ahi
	direction.x = 400;//ver que pasa ahi //ES UN ERROR. NO DEBERIA CRUZAR.
	//ABSTRAER BIEN LOS BOUNDRY CONDITION PARA QUE NO SALGA DEL DIBUJO
	direction = rotate_vector(direction, 43);
	draw_vector(image, direction, pos_x, pos_y);
	direction = rotate_vector(direction, -90);
	draw_vector(image, direction, pos_x, pos_y);

} */

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void draw_player_position(mlx_image_t *image, float pos_x, float pos_y, t_prog *game)
{
	if (pos_x < 0 || pos_y < 0)
		ft_shutdown(EX, game);

	draw_centered_rectangle(image, pos_x, pos_y, x_size, y_size); //TODO, no esta centrando exacto
	//draw_vision(image, pos_x, pos_y, VISION_ANGLE);
}