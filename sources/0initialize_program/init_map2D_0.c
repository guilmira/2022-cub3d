/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline void	fill_vis(t_prog *game, char dir)
{
	if (dir == 'N')
	{
		game->pl.vis.x = 0;
		game->pl.vis.y = 1;
	}
	else if (dir == 'S')
	{
		game->pl.vis.x = 0;
		game->pl.vis.y = -1;
	}
	else if (dir == 'E')
	{
		game->pl.vis.x = 1;
		game->pl.vis.y = 0;
	}
	else if (dir == 'W')
	{
		game->pl.vis.x = -1;
		game->pl.vis.y = 0;
	}
}

/** PURPOSE : Define intial location of player position in pixel screen. */
static inline void	start_player_position(int j, int i, t_prog *game)
{
	game->pl.position[0] = i;
	game->pl.position[1] = game->map2d.height - j - 1;
	game->pl.position_coor[0] = game->pl.position[0] * \
	(double) game->map2d.pixel_per_block[0] + \
	((double) game->map2d.pixel_per_block[0] / 2);
	game->pl.position_coor[1] = game->pl.position[1] * \
	(double) game->map2d.pixel_per_block[1] + \
	((double) game->map2d.pixel_per_block[1] / 2);
	game->pl.v_position_coor[0] = game->pl.position_coor[0];
	game->pl.v_position_coor[1] = game->pl.position_coor[1];
}

/** PURPOSE : Work with array [j][i] as a cartesian system. */
static int	shift_array(int y, int height)
{
	return ((height - 1) - y);
}

static int	**fill_new_map(int height, t_prog *game, char **map)
{
	int	j;
	int	i;
	int	**layout;

	j = -1;
	i = -1;
	layout = NULL;
	layout = allocate_all_layout(game->map2d.height, game->map2d.width);
	while (++j < height)
	{
		while (++i < game->map2d.width)
		{
			if (map[j][i] == '1')
				layout[shift_array(j, height)][i] = 1;
			else if (map[j][i] == '0' || map[j][i] == ' ')
				layout[shift_array(j, height)][i] = 0;
			else
			{
				start_player_position(j, i, game);
				fill_vis(game, game->map2d.map[j][i]);
			}
		}
		i = -1;
	}
	return (layout);
}

/** PURPOSE : Translate parser map into a wall map. */
void	init_map2d(char **map, t_prog *game)
{
	game->map2d.layout = fill_new_map(game->map2d.height, game, map);
	build_spaced_layout(game, game->map2d.height, game->map2d.width);
	freemat_int(game->map2d.layout, game->map2d.height);
	game->map2d.layout = copy_double_pointer \
	(game->map2d.s_layout, game->map2d.s_height, game->map2d.s_width);
	game->map2d.height = game->map2d.s_height;
	game->map2d.width = game->map2d.s_width;
	update_pixel_per_block(game);
	start_player_position(game->pl.position[1], game->pl.position[0], game);
	control_window_limits(game);
}
