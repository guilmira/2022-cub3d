/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arith_advanced.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 05:44:20 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/12 14:29:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Gives vector perendicular counterclockwise. */
t_vector	get_perpendicular(t_vector v)
{
	t_vector new;

	new.x = -v.y;
	new.y = v.x;
	return (new);
}

/** PURPOSE : Invert sense(sentido). */
t_vector invert_sense_vector(t_vector v)
{
	t_vector inverted;
	inverted.x = -v.x;
	inverted.y = -v.y;
	return (inverted);
}