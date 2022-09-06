/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_color_selection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:40:12 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/06 16:34:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : check if the wall hits on OX axis or OY axis.
 * 2 OX axis (vertical vector that hits on an horizontal)
 * 1 OXY axis (horizontal vector that hits on a vertical) */
static int is_shadowed(int value)
{
	if (value == 2)
		return (1);
	else
		return (0);
}


//sky_clr
//floor_clr

/** PURPOSE : choose what shade to put on wall. 
 * 0 - normal
 * 1 - far
 * 2 - shadowed
 * 3 - far shadowed */
int choose_wall_shade(int wall_value, int size, t_prog *game)
{
	int colour[4];
	(void) size;
	(void) game;

	colour[0] = BLUE;
	colour[1] = rgb_t_translate(0, 0, 190, 255);
	colour[2] = get_rgb_shadowed(colour[0]);
	colour[3] =  get_rgb_shadowed(colour[1]);
	
	if (is_shadowed(wall_value) && size < game->w1.size[1] / 15)
		return (colour[3]);
	else if (is_shadowed(wall_value))
		return (colour[2]);
	else if (size < game->w1.size[1] / 15)
		return (colour[1]);
	else
		return (colour[0]);
}