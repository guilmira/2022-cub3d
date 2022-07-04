/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8character.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 10:06:29 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

#define VISION_ANGLE 140
/** PURPOSE : Rectangle size. */
enum player_size
{
	x_size = 25,
	y_size = 25
};

/** PURPOSE : Draw a straight line.
 * 1. Uses equation of line y = mx + n.
 * 2. Recalculates coordinates appropiatly. */
/* static void draw_line(t_data *image, float x_limit, float y_limit, float x_origin, float y_origin, float slope, float ordinate)
{
	float y;
	float i;
	float x;
	
	i = -1;
	while (++i < OX_WINDOW)
	{
		x = i;
		y = ft_line(slope, x, ordinate);
		if (x + x_origin >= x_limit) //hit cube wall
			break ;
		if (y + y_origin >= y_limit || y + y_origin <= 0)
			break ;
		my_mlx_pixel_put(image, x + x_origin, coor(y + y_origin), trgb_translate(0, 0, 0, 255));
	}
} */

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
/* void draw_direction_vertical(t_data *image, int x, int y)
{
	int j;

	j = -1;
	while (++j < OY_WINDOW)
	{
		my_mlx_pixel_put(image, x, coor(y + j), trgb_translate(0, 0, 0, 255));
		if (y + j >= OX_WINDOW - 1) //hit cube wall
			break;
	}
} */

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
	//reviar porque vector podria dar nulo si hay colision justo en frente
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



/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */





/* acos(x), asin(x), and atan(x) return the inverse cosine, inverse sine and inverse tangent of x, respectively.  Note that the result is an angle
in radians.  atan2(y, x) returns the inverse tangent of y/x in radians, with sign chosen according to the quadrant of (x,y). */

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
static void draw_vision(t_data *image, int pos_x, int pos_y, float aperture)
{
	float theta;
	float slope;
	float ordinate;

	if (aperture > 180)
		return ;
	theta = 90 - (aperture / 2);
	slope = tan(degree_to_radian(theta)); //probar con field of vision de 45
	ordinate = 0;
	//draw_direction_vertical(image, x, y);
/* 	draw_line(image, OX_WINDOW, OY_WINDOW, pos_x, pos_y, 0, ordinate);
	draw_line(image, OX_WINDOW, OY_WINDOW, pos_x, pos_y, slope, ordinate);
	draw_line(image, OX_WINDOW, OY_WINDOW, pos_x, pos_y, -slope, ordinate);
 */
	//----

	t_vector	direction;
	direction = cast_straight(pos_x, pos_y);
	printf("%i\n", direction.y);

	direction.x = OX_UNIT;
	direction.y = OY_UNIT;
	draw_vector(image, direction, pos_x, pos_y);
	printf("termina\n");
}



/** PURPOSE : Draw player with its vision. */
void draw_player_position(t_data *image, int pos_x, int pos_y, t_prog *game)
{
	draw_centered_rectangle(image, pos_x, pos_y, x_size, y_size);
	draw_vision(image, pos_x, pos_y, VISION_ANGLE);
	if (0)
		ft_shutdown(EX, game);
}