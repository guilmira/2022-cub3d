/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3vectors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 08:15:33 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 08:32:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

float get_module(t_vector vec)
{
	if (!vec.x && ! vec.y)
		return (0);
	return (sqrt( pow(vec.x, 2) + pow(vec.y, 2)) );
}


static t_vector unit_vector(t_vector vec)
{
	t_vector unit_vec;
	int module;

	module = get_module(vec);
	if (!module)
		ft_senderror("Attention: Module of vector = 0\n");
	unit_vec.x = vec.x / module;
	unit_vec.y = vec.y / module;
	return (unit_vec);
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
	float		module_vec;
	t_vector	unit_vec;
	int			counter;
	int x_pixel;
	int y_pixel;

	counter = -1;
	unit_vec = unit_vector(vec);
	module_vec = get_module(vec);
	printf("here %i\n", unit_vec.y);

	while (++counter < module_vec)
	{
		x_pixel = x_origin + i;
		y_pixel = coor(y_origin + j);
		my_mlx_pixel_put(image, x_origin, y_pixel, trgb_translate(0, 200, 0, 0));
	}
	return ;
}

/** ¿Why no draw the line by using the ecuation of the line (y = mx + n)
 * As we are working with pixels, it will result in free spaces in the pixel map.
 * On th other hand, working with unitary vectors, will yield a continous line. */
