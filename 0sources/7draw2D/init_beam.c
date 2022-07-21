/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_beam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:32:05 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 14:07:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Set limits for collisions of vectors. 
 * The safe offset prevents printing at walls. */
static void	correct_boundries(t_beam *beam, t_prog *game)
{
	double safe_offset;


	(void) game;
	safe_offset = 1;
	beam->low_bound[0] = 0 - beam->position[0] + safe_offset;
	beam->low_bound[1] = 0 - beam->position[1] + safe_offset;
	//log_coor(beam->low_bound);
	//sleep(1);
	beam->high_bound[0] = game->w2.size[0] - beam->position[0] - safe_offset;
	beam->high_bound[1] = game->w2.size[1] - beam->position[1] - safe_offset;
	//log_coor(beam->high_bound);

}

/** PURPOSE : Init beam as a straight vector pointing north. */
void init_beam(t_beam *beam, double position[], t_vector dir, t_prog *game)
{
	beam->vis_dir = dir;
	beam->plane_left.x = -1;
	beam->plane_left.y = 0;
	beam->plane_right.x = 1;
	beam->plane_right.y = 0;
	beam->position[0] = position[0];
	beam->position[1] = position[1];
	correct_boundries(beam, game);
}