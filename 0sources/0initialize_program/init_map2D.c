/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/04 09:20:47 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : general function to init variables. */
void update_pixel_per_block(t_prog *game)
{
	game->map2D.pixel_per_block[0] = game->w2.size[0] / game->map2D.width;
	game->map2D.pixel_per_block[1] = game->w2.size[1] / game->map2D.height;
}

static void fill_vis(t_prog *game, char dir)
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

/** PURPOSE : Define intial location of player position in pixel screen. */
static void	update_player_position(int j, int i, t_prog *game)
{
	game->pl.position[0] = i;
	game->pl.position[1] = game->map2D.height - j - 1;
	game->pl.position_coor[0] = (double) game->pl.position[0] * game->map2D.pixel_per_block[0] + (game->map2D.pixel_per_block[0] / 2);
	game->pl.position_coor[1] = (double) game->pl.position[1] * game->map2D.pixel_per_block[1] + (game->map2D.pixel_per_block[1] / 2);
}

/** PURPOSE : Translate parser map into a wall map */
void init_map2D(char **map, t_prog *game)
{
	int j;
	int i;
	int **layout;
	
	j = -1;
	i = -1;
	layout = NULL;
	/* --------------------------------------------------------------- */
	layout = ft_calloc(game->map2D.height, sizeof(int *));
	while (++j < game->map2D.height)
	{
		layout[j] = ft_calloc(game->map2D.width, sizeof(int));
		while (++i < game->map2D.width)
		{
			if (map[j][i] == '1')
				layout[j][i] = 1;
			else if (map[j][i] == '0' || map[j][i] == ' ')
				layout[j][i] = 0;
			else
			{
				update_player_position(j, i, game);
				fill_vis(game, game->map2D.map[j][i]);
			}

		}
		i = -1;
	}
	game->map2D.layout = layout;
	print_map(map, game);
	update_pixel_per_block(game);
}