/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3vectors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:15:33 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 10:33:20 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

#include <time.h>

float get_module(t_vector vec)
{
	if (!vec.x && ! vec.y)
		return (0);
	return (sqrt( pow(vec.x, 2) + pow(vec.y, 2)) );
}


static t_unit_vec get_unit_vector(t_vector vec)
{
	t_unit_vec	unit_vec;
	float			module;

	module = get_module(vec);
	if (!module)
		ft_senderror("Attention: Module of vector = 0\n");
	unit_vec.x = vec.x / module;
	unit_vec.y = vec.y / module;
	return (unit_vec);
}

/** PURPOSE : Draw vector recursive.
 * Must be passed by reference to make program faster.  */
void draw_vec_recursive(t_vector_adv *vec_adv, t_data *image, float x_pixel, float y_pixel)
{

	if (x_pixel <= vec_adv->x_origin \
	&& y_pixel <= vec_adv->y_origin)
		my_mlx_pixel_put(image, x_pixel, coor(y_pixel), vec_adv->colour_code);
	else
	{
		draw_vec_recursive(vec_adv, image, x_pixel - vec_adv->unit_vec.x, y_pixel - vec_adv->unit_vec.y);
		my_mlx_pixel_put(image, x_pixel, coor(y_pixel), vec_adv->colour_code);
	}
}

/** PURPOSE : Draw vector on screen.
 * Assuming position of player as a coordiante (0, 0).
 * Therefore, vector can be represented by having a single point in space
 *  (Vx, Vy) 
 * 1. First, unit vector (vector unitario is calulated). 
 * 2. As the unit of the grid is the pixel, to obtaing the line:
 * (unit_Vector + unit_Vector) repeated the module.  */
void draw_vector(t_data *image, t_vector vec, int x_origin, int y_origin)
{
	float				x_pixel;
	float				y_pixel;
	t_vector_adv		vec_adv;


	vec_adv.x = vec.x;
	vec_adv.y = vec.y;
	vec_adv.x_origin = x_origin;
	vec_adv.y_origin = y_origin;
	vec_adv.module = get_module(vec);
	vec_adv.colour_code = trgb_translate(0, 200, 0, 0);
	vec_adv.unit_vec = get_unit_vector(vec);
	

	double time_spent = 0.0;
    clock_t begin = clock();

	x_pixel = x_origin + vec_adv.x;
	y_pixel = y_origin + vec_adv.y;
	//draw_vec_recursive(&vec_adv, image, x_pixel, y_pixel);printf("RECURSIVE:  \n");
	//double the time .000054 vs 0.000026

//NOT recursive = measure times and final GRAPH RESULT.

	int counter;
	t_unit_vec v;
	
	v = get_unit_vector(vec);
	counter = get_module(vec);
	x_pixel = x_origin + v.x;
	y_pixel = y_origin + v.y;
	printf("NOT RECURSIVE:  \n");
	while (--counter > 0)
	{
		my_mlx_pixel_put(image, x_pixel, coor(y_pixel), trgb_translate(0, 0, 200, 0));
		x_pixel += v.x;
		y_pixel += v.y;
	}


	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent);
}

/** ¿Why not draw the line by using the ecuation of the line (y = mx + n)
 * As we are working with pixels, it will result in free spaces in the pixel map.
 * On th other hand, working with unitary vectors, will yield a continous line. */
