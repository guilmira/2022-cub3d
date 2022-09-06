/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/09/06 17:13:10 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : evaluate if movement gets close to window limit. */
static int	window_limit(double new_pos[], t_dim win, double margin, t_prog *game)
{
	(void) game;
	if (new_pos[0] + margin >= win.size[0] || new_pos[0] - margin <= 0)
		return (1);
	if (new_pos[1] + margin >= win.size[1] || new_pos[1] - margin <= 0)
		return (1);
	return (0);
}

/** PURPOSE : calculate new coordinates. */
static void move_position(t_vector v, t_prog *game, int key)
{
	double new_pos[2];
	double speed_multiplier;
	int flag;

	if (game->pl.flag_trance)
		speed_multiplier = TRANCE_BOOST;
	else
		speed_multiplier = 1;
	if (key == 0)
	{
		new_pos[0] = game->pl.position_coor[0] + (v.x/126) * speed_multiplier;
		new_pos[1] = game->pl.position_coor[1] + (v.y/126) * speed_multiplier;
	}
	else
	{
		new_pos[0] = game->pl.position_coor[0] - (v.x/126) * speed_multiplier;
		new_pos[1] = game->pl.position_coor[1] - (v.y/126) * speed_multiplier;
	}
	/* log_coor_int(game->pl.position); //NEXT
	log_coor(game->pl.position_coor); //NEXT */
	flag = wall_coll(game, new_pos);
	if (window_limit(new_pos, game->w2, (double) SAFE_MARGIN, game))
		return ;
	filter_final_pos(game, new_pos, flag);
}

/** PURPOSE : correct position by adding correct vector. */
static void update_player_position(int key, t_prog *game)
{
	int i;
	int x;

	i = -1;
	while (++i < 8)
	{
		if (key == i)
		{
			x = -1;
			while(++x < 126)
				move_position(game->pl.vis, game, key);
		}
	}
}

/** PURPOSE : distribute proper key control
 * W A S D -- movement code.
 * Or combination of the above. */
void	movement_control(mlx_key_data_t key, t_prog *game)
{
	(void) key;
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		update_player_position(key_up, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		update_player_position(key_down, game);
}
