/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/08/04 08:18:17 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void filter_final_pos(t_prog *game, double new_pos[], int flag, double prev_pos[])
{
	int prev_pos_c[2];

	prev_pos_c[0] = game->pl.position[0];
	prev_pos_c[1] = game->pl.position[1];
	printf("1:%f %f \n", prev_pos_c[0], prev_pos_c[1]);
	if (flag == 0)
	{
		game->pl.position_coor[0] = new_pos[0];
		game->pl.position_coor[1] = new_pos[1];
		game->pl.position[0] = round(new_pos[0] / game->map2D.pixel_per_block[0]);
		game->pl.position[1] = game->map2D.map_y - round(new_pos[1] / game->map2D.pixel_per_block[1]);
	}
	if (flag == 1)
	{
		game->pl.position_coor[1] = new_pos[1];
		game->pl.position[1] = game->map2D.map_y - round(new_pos[1] / game->map2D.pixel_per_block[1]);
	}
	if (flag == 2)
	{
		game->pl.position_coor[0] = new_pos[0];
		game->pl.position[0] = round(new_pos[0] / game->map2D.pixel_per_block[0]);
	}
	if (wall_coll(game, game->pl.position_coor) == 1 ||
		wall_coll(game, game->pl.position_coor) == 2 ||
		wall_coll(game, game->pl.position_coor) == 5)
	{
		game->pl.position_coor[0] = prev_pos_c[0];
		game->pl.position_coor[1] = prev_pos_c[1];
		printf("2:%f %f \n", prev_pos_c[0], prev_pos_c[1]);
		game->pl.position[0] = prev_pos[0];
		game->pl.position[1] = prev_pos[1];
	}
}
 
int wall_coll(t_prog *game, double new_pos[])
{
	int pos[6];

	pos[0] = floor((new_pos[0] + (game->pl.ratio)) / game->map2D.pixel_per_block[0]);
	pos[1] = floor((new_pos[0] - (game->pl.ratio)) / game->map2D.pixel_per_block[0]);
	pos[2] = floor(new_pos[0] / game->map2D.pixel_per_block[0]);
	pos[3] = ceil((new_pos[1] + game->pl.ratio) / game->map2D.pixel_per_block[1]) - 1;
	pos[4] = ceil((new_pos[1] - game->pl.ratio) / game->map2D.pixel_per_block[1]) - 1;
	pos[5] = ceil(new_pos[1] / game->map2D.pixel_per_block[1]) - 1;
	if ((game->map2D.layout[pos[5]][pos[0]] == 1 && game->map2D.layout[pos[4]][pos[2]] == 1) 
		|| (game->map2D.layout[pos[5]][pos[0]] == 1 && game->map2D.layout[pos[3]][pos[2]] == 1))
		return(5);
	if ((game->map2D.layout[pos[5]][pos[1]] == 1 && game->map2D.layout[pos[4]][pos[2]] == 1) 
		|| (game->map2D.layout[pos[3]][pos[2]] == 1 && game->map2D.layout[pos[5]][pos[1]] == 1))
		return(5);
	if (game->map2D.layout[pos[5]][pos[0]] == 1 || game->map2D.layout[pos[5]][pos[1]] == 1)
		return(1);
	if (game->map2D.layout[pos[3]][pos[2]] == 1 || game->map2D.layout[pos[4]][pos[2]] == 1)
		return(2);
	return(0);
}