/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline void	abort_crapping(t_prog *game, int pixel_per_block[])
{
	int	flag;
	int	count;

	flag = wall_coll(game, game->pl.v_position_coor, pixel_per_block);
	count = 0;
	while (wall_coll(game, game->pl.v_position_coor, \
	pixel_per_block) != 0)
	{
		if (flag == RIGHT_COLLISION)
			game->pl.v_position_coor[0] -= CORRECTION_PIXEL_NBR;
		else if (flag == LEFT_COLLISION)
			game->pl.v_position_coor[0] += CORRECTION_PIXEL_NBR;
		else if (flag == TOP_COLLISION)
			game->pl.v_position_coor[1] -= CORRECTION_PIXEL_NBR;
		else if (flag == BOTTOM_COLLISION)
			game->pl.v_position_coor[1] += CORRECTION_PIXEL_NBR;
		else
			break ;
		flag = wall_coll(game, game->pl.v_position_coor, pixel_per_block);
	}
	game->pl.position[0] = floor(game->pl.v_position_coor[0] / \
	pixel_per_block[0]);
	game->pl.position[1] = ceil(game->pl.v_position_coor[1] / \
	pixel_per_block[1]) - 1;
}

void	filter_final_pos(t_prog *game, double new_pos[], \
int flag, int pixel_per_block[])
{
	if (flag == 1 || flag == 2 || flag == 0)
	{
		game->pl.v_position_coor[1] = new_pos[1];
		game->pl.position[1] = ceil(new_pos[1] / pixel_per_block[1]) - 1;
	}
	if (flag == 3 || flag == 4 || flag == 0)
	{
		game->pl.v_position_coor[0] = new_pos[0];
		game->pl.position[0] = floor(new_pos[0] / pixel_per_block[0]);
	}
	if (wall_coll(game, game->pl.v_position_coor, pixel_per_block) != 0)
		abort_crapping(game, pixel_per_block);
	if (game->minimap_state == 2)
		update_player_location(game);
	else
	{
		game->pl.position_coor[0] = game->pl.v_position_coor[0];
		game->pl.position_coor[1] = game->pl.v_position_coor[1];
	}
}

int	wall_coll(t_prog *game, double new_pos[], int pixel_per_block[])
{
	int	pos[6];

	pos[0] = floor((new_pos[0] + (game->pl.ratio)) / pixel_per_block[0]);
	pos[1] = floor((new_pos[0] - (game->pl.ratio)) / pixel_per_block[0]);
	pos[2] = floor(new_pos[0] / pixel_per_block[0]);
	pos[3] = ceil((new_pos[1] + game->pl.ratio) / pixel_per_block[1] - 1);
	pos[4] = ceil((new_pos[1] - game->pl.ratio) / pixel_per_block[1] - 1);
	pos[5] = ceil(new_pos[1] / pixel_per_block[1] - 1);
	if (game->map2d.layout[pos[5]][pos[0]] == 1)
		return (RIGHT_COLLISION);
	if (game->map2d.layout[pos[5]][pos[1]] == 1)
		return (LEFT_COLLISION);
	if (game->map2d.layout[pos[3]][pos[2]] == 1)
		return (TOP_COLLISION);
	if (game->map2d.layout[pos[4]][pos[2]] == 1)
		return (BOTTOM_COLLISION);
	return (0);
}
