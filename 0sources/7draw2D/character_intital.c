/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_intital.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 12:01:09 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"



void fill_vis(t_prog *game, char dir);

void	fill_player_pos(t_prog *game, double player_pos[])
{
	int i[2];

	i[0] = -1;
	if(game->map == NULL)
	{
		player_pos[0] = (double)(5 * game->w2.pixel_per_block);
		player_pos[1] = (double)(5 * game->w2.pixel_per_block);
		return ;
	}
	while (game->map[++i[0]])
	{
		i[1] = -1;
		while (game->map[i[0]][++i[1]])
		{
			if (game->map[i[0]][i[1]] != ' '
				&& game->map[i[0]][i[1]] != '1'
				&& game->map[i[0]][i[1]] != '0'
				&& game->map[i[0]][i[1]] != '\0')
			{
				player_pos[0] = (double)(((i[1] + 1) * game->w2.pixel_per_block));
				player_pos[1] = (double)((game->map_y - i[0]) * game->w2.pixel_per_block);
				fill_vis(game, game->map[i[0]][i[1]]);
				return ;
			}
		}
	}
	return ;
}

void fill_vis(t_prog *game, char dir)
{
	if(dir == 'N')
	{
		game->pl.vis.x = 0;
		game->pl.vis.y = 1;
	}
	else if(dir == 'S')
	{
		game->pl.vis.x = 0;
		game->pl.vis.y = -1;
	}
	else if(dir == 'E')
	{
		game->pl.vis.x = 1;
		game->pl.vis.y = 0;
	}
	else if(dir == 'W')
	{
		game->pl.vis.x = -1;
		game->pl.vis.y = 0;
	}
}