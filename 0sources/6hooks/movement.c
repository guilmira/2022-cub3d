/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/27 09:53:54 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


//PACE funcion pendiente de mas testeo
//CUidado con el paso de doubles a int sin casteo explicito. (variable new_pos)
/* static int wall_coll(t_prog *game, double new_pos[])
{
	int pos[6];

	pos[0] = round(new_pos[0] / game->w2.pixel_per_block[0]);
	pos[1] = round((new_pos[0] - SAFE_MARGIN) / game->w2.pixel_per_block[0]);
	pos[2] = round((new_pos[0] + SAFE_MARGIN) / game->w2.pixel_per_block[0]);
	pos[3] = game->map_y - round(new_pos[1] / game->w2.pixel_per_block[1]);
	pos[4] = game->map_y - round((new_pos[1] - SAFE_MARGIN)  / game->w2.pixel_per_block[1]);
	pos[5] = game->map_y - round((new_pos[1] + SAFE_MARGIN) / game->w2.pixel_per_block[1]);
	if (game->map[pos[3]][pos[1]] == '1' || game->map[pos[3]][pos[2]] == '1'
		|| game->map[pos[4]][pos[0]] == '1' || game->map[pos[5]][pos[0]] == '1')
		return (1);
	return (0);
} */

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
static int wall_coll(t_prog *game, double new_pos[])
{
	int pos[6];


	pos[0] = floor((new_pos[0] + (game->pl.ratio)) / game->w2.pixel_per_block[0]);
	pos[1] = floor((new_pos[0] - (game->pl.ratio)) / game->w2.pixel_per_block[0]);
	pos[2] = floor(new_pos[0] / game->w2.pixel_per_block[0]);
	pos[3] = game->map_y - floor((new_pos[1] + (game->pl.ratio)) / game->w2.pixel_per_block[1]);
	pos[4] = game->map_y - floor((new_pos[1] - (game->pl.ratio)) / game->w2.pixel_per_block[1]);
	pos[5] = game->map_y - floor(new_pos[1] / game->w2.pixel_per_block[1]);
	if (game->map[pos[5]][pos[0]] == '1' || game->map[pos[5]][pos[1]] == '1'
		|| game->map[pos[3]][pos[2]] == '1' || game->map[pos[4]][pos[2]] == '1')
		return(1);
	return(0);
}
/** PURPOSE : calculate new coordinates. */
static void move_position(t_vector v, t_prog *game)
{
	double new_pos[2];
	double speed_multiplier;

	if (game->pl.flag_trance)
		speed_multiplier = TRANCE_BOOST;
	else
		speed_multiplier = 1;
	new_pos[0] = game->pl.position[0] + (v.x) * speed_multiplier;
	new_pos[1] = game->pl.position[1] + (v.y) * speed_multiplier;
	if (wall_coll(game, new_pos))
	{
		printf("ITS COLLIDING\n");
		return ;
	}
	if (window_limit(new_pos, game->w2, (double) SAFE_MARGIN, game))
		return ;
	game->pl.position[0] = new_pos[0];
	game->pl.position[1] = new_pos[1];
}

/** PURPOSE : correct position by adding correct vector. */
static void update_player_position(int key, t_prog *game)
{
	int i;

	i = -1;
	while (++i < 8)
		if (key == i)
			move_position(game->wind_rose[i], game);
}

/** PURPOSE : distribute proper key control
 * W A S D -- movement code.
 * Or combination of the above. */
void	movement_control(mlx_key_data_t key, t_prog *game)
{
	(void) key;
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_position(key_NE, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W) && mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_position(key_NW, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_position(key_SE, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_position(key_SW, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		update_player_position(key_up, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		update_player_position(key_down, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_position(key_right, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_position(key_left, game);
}