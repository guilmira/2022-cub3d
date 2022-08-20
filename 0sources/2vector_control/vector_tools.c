/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:34:25 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 12:18:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Module of vector: sqrt(Vx^2 + Vy^2)  */
double	get_module(t_vector vec)
{
	if (!vec.x && ! vec.y)
		return (0);
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2)));
}

/** PURPOSE : Gets unit vector.  */
t_vector	get_unit_vector(t_vector vec)
{
	double			module;

	module = get_module(vec);
	if (!module)
		ft_senderror("Attention: Module of vector = 0\n");
	return (div_vec(vec, module));
}

/** PURPOSE : Rotation of a vector
 * V = Vx * a' + Vy* b'
 * a = sen(t) + cos(t)
 * b = -sen(t) + cos(t) */
t_vector	rotate_vector(t_vector vec, int angle)
{
	t_vector	rotate;

	rotate.x = (double)(vec.x * \
	(cos(degree_to_radian(angle)) + sin(degree_to_radian(angle))));
	rotate.y = (double)(vec.y * \
	(cos(degree_to_radian(angle)) - sin(degree_to_radian(angle))));
	return (rotate);
}
