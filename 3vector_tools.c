/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3vector_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:34:25 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 10:55:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : Module of vector: sqrt(Vx^2 + Vy^2)  */
double get_module(t_vector vec)
{
	if (!vec.x && ! vec.y)
		return (0);
	return (sqrt( pow(vec.x, 2) + pow(vec.y, 2)) );
}

/** PURPOSE : Gets unit vector.  */
t_unit_vec get_unit_vector(t_vector vec)
{
	double			module;
	t_unit_vec		unit_vec;

	module = get_module(vec);
	if (!module)
		ft_senderror("Attention: Module of vector = 0\n");
	unit_vec.x = vec.x / module;
	unit_vec.y = vec.y / module;
	return (unit_vec);
}