/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8character.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/01 16:37:33 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

#define VISION_ANGLE 80
/** PURPOSE : Rectangle size. */
enum player_size
{
	x_size = 50,
	y_size = 50
};

static void draw_line(t_data *image, float x_limit, float y_limit, float x_origin, float y_origin, float slope)
{
	float y;
	int i;
	int x;
	float ordinate;

	ordinate = y_origin - slope * x_origin;
	printf("this %f\n", ordinate);

	i = -1;
	while (++i < OX_WINDOW)
	{
		x = x_origin + i;
		y = ft_line(slope, x, ordinate);
		if (x + x_origin >= x_limit || y + y_origin >= y_limit ) //hit cube wall
			break ;
		my_mlx_pixel_put(image, x, coor(y), trgb_translate(0, 0, 0, 255));
	}
}

static void draw_direction(t_data *image, int x, int y)
{
	int j;

	j = -1;
	while (++j < OY_WINDOW)
	{
		my_mlx_pixel_put(image, x, coor(y + j), trgb_translate(0, 0, 0, 255));
		if (y + j >= OX_WINDOW - 1) //hit cube wall
			break;
	}
}

/*  acos(x), asin(x), and atan(x) return the inverse cosine, inverse sine and inverse tangent of x, respectively.  Note that the result is an angle
in radians.  atan2(y, x) returns the inverse tangent of y/x in radians, with sign chosen according to the quadrant of (x,y). */

/** PURPOSE : Draw field of vision.
 * 1. Straight forward direction from point of origin.
 * 2. Side vectors depending of angle of vision. */
static void draw_vision(t_data *image, int x, int y, float aperture)
{

	float theta;
	float slope;

	theta = 90 - (aperture / 2);
	slope = tan(degree_to_radian(theta)); //probar con field of vision de 45
	draw_direction(image, x, y);
	printf("%f\n", degree_to_radian(theta));

	printf("%f\n", slope);
	draw_line(image, OX_WINDOW, OY_WINDOW, x, y, slope);
}

/** PURPOSE : Draw player with its vision. */
void draw_player_position(t_data *image, int x, int y, t_prog *game)
{
	draw_rectangle(image, x, y, 5, 5);
	draw_centered_rectangle(image, 150, 150, x_size, y_size);
	draw_vision(image, 150, 150, VISION_ANGLE);
	if (0)
		ft_shutdown(EX, game);
}