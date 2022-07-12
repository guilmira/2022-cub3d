/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_beam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:32:05 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/12 14:33:52 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Set limits for collisions of vectors. */
static void	correct_boundries(t_beam *beam, double position[])
{
	beam->position[0] = position[0];
	beam->position[1] = position[1];
	beam->low_bound[0] = 0 - beam->position[0];
	beam->low_bound[1] = 0 - beam->position[1];
	beam->high_bound[0] = OX_WINDOW - beam->position[0];
	beam->high_bound[1] = OY_WINDOW - beam->position[1];
}

/** PURPOSE : Init beam as a straight vector pointing north. */
void init_beam(t_beam *beam, double position[])
{
	beam->vis_dir.x = 0; 
	beam->vis_dir.y = 1;
	beam->plane_left.x = -1;
	beam->plane_left.y = 0;
	beam->plane_right.x = 1;
	beam->plane_right.y = 0;
	correct_boundries(beam, position);
}