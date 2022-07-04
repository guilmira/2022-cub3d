/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8character.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 12:23:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

#define VISION_ANGLE 140 //con esto
/** PURPOSE : Rectangle size. */
enum player_size
{
	x_size = 25,
	y_size = 25
};

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
static void draw_vision(t_data *image, int pos_x, int pos_y, float aperture)
{
	t_vector	direction;

	aperture = 0;
	
	direction = cast_straight(pos_x, pos_y);
	draw_vector(image, direction, pos_x, pos_y);
	direction.x = 700;//ver que pasa ahi
	direction.x = 400;//ver que pasa ahi
	direction = rotate_vector(direction, 43);
	printf("h %i y %i\n", direction.x, direction.y);
	draw_vector(image, direction, pos_x, pos_y);
	direction = rotate_vector(direction, -90);
	draw_vector(image, direction, pos_x, pos_y);

}


/** PURPOSE : Draw player with its vision. */
void draw_player_position(t_data *image, int pos_x, int pos_y, t_prog *game)
{
	draw_centered_rectangle(image, pos_x, pos_y, x_size, y_size);
	draw_vision(image, pos_x, pos_y, VISION_ANGLE);
	if (0)
		ft_shutdown(EX, game);
}