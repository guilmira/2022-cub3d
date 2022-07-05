/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_recusive_obsolete.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:29:50 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 11:40:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/** PURPOSE : vector. */
typedef struct s_vector_adv
{
	int			x;
	int			x_origin;
	int			y;
	int			y_origin;
	int			module;
	int			colour_code;
	t_unit_vec	unit_vec;
}				t_vector_adv;

/** PURPOSE : Draw vector recursive.
 * Must be passed by reference to make program faster. */
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

void draw_vector(t_data *image, t_vector vec, int x_origin, int y_origin)
{
	double				x_pixel;
	double				y_pixel;
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
}