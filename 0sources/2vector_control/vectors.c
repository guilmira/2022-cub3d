/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:15:33 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/05 11:24:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#include <time.h>

//TODO, poner una condicion de collison

/** PURPOSE : Draw vector on screen.
 * Assuming position of player as a coordinate (0, 0).
 * Therefore, vector can be represented by having a single point in space (Vx, Vy) 
 * 1. First, unit vector (vector unitario is calulated). 
 * 2. As the unit of the grid is the pixel, to obtaing the line:
 * (unit_Vector + unit_Vector) repeated n module times.  */
void draw_vector(mlx_image_t *image, t_vector vec, int x_origin, int y_origin)
{
	double	x_pixel;
	double	y_pixel;
	double	counter;

	printf("hola\n");

	double time_spent = 0.0;	
    clock_t begin = clock();

	t_unit_vec	unit_vec;

	counter = get_module(vec);
	unit_vec = get_unit_vector(vec);
	x_pixel = x_origin + unit_vec.x;
	y_pixel = y_origin + unit_vec.y;
	while (--counter > 0)
	{	
		//my_mlx_pixel_put(image, x_pixel, coor(y_pixel), colour_code);
		mlx_put_pixel(image, x_pixel, coor(y_pixel), RED);
		x_pixel += unit_vec.x;
		y_pixel += unit_vec.y;
		if (x_pixel >= OX_WINDOW || y_pixel >= OY_WINDOW)
			break ;
	}
	
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent);
}

/** ADDITIONAL NOTES
 * ¿Why not draw the line by using the ecuation of the line (y = mx + n)
 * As we are working with pixels, it will result in free spaces in the pixel map.
 * On th other hand, working with unitary vectors, will yield a continous line. */
