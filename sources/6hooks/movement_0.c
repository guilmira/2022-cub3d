/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/03 16:10:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : calculate new coordinates. */
static  inline void move_position(double v[], t_prog *game, int key, int pixel_per_block[])
{
	double new_pos[2];
	double speed_multiplier;
	int flag;

	if (game->pl.flag_trance)
		speed_multiplier = (WIND_MODE * 0.01);
	else
		speed_multiplier = 0.01;
	if (key == 0)
	{
		new_pos[0] = game->pl.v_position_coor[0] + (v[0]) * speed_multiplier;
		new_pos[1] = game->pl.v_position_coor[1] + (v[1]) * speed_multiplier;
	}
	else
	{
		new_pos[0] = game->pl.v_position_coor[0] - (v[0]) * speed_multiplier;
		new_pos[1] = game->pl.v_position_coor[1] - (v[1]) * speed_multiplier;
	}
	flag = wall_coll(game, new_pos, pixel_per_block);
	filter_final_pos(game, new_pos, flag, pixel_per_block);
}

/** PURPOSE : correct position by adding correct vector. */
void update_player_position(int key, t_prog *game)
{
	int i;
	int x;
	int speed;
	int pixel_per_block[2];
	double vp[2];

	i = -1;
	speed = PLAYER_SPEED * 2;
	if (game->map2D.v_pixel_per_block[0] != 0)
	{	
		pixel_per_block[0] = game->map2D.v_pixel_per_block[0];
		pixel_per_block[1] = game->map2D.v_pixel_per_block[1];
	}
	else
	{
		pixel_per_block[0] = game->map2D.pixel_per_block[0];
		pixel_per_block[1] = game->map2D.pixel_per_block[1];
	}
	vp[0] = ((game->pl.vis.x) / 2);
	vp[1] = ((game->pl.vis.y) / 2);
	x = 0;
	while (++i < 8)
	{
		if (key == i)
		{
			while(x++ < speed)
				move_position(vp, game, key, pixel_per_block);
		}
	}
}

/** PURPOSE : distribute proper key control
 * W A S D -- movement code.
 * Or combination of the above. */
void	movement_control(mlx_key_data_t t_key, t_prog *game)
{
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, t_key.key) == 1)
	{	
		game->pl.key[MLX_KEY_W] = mlx_is_key_down(game->mlx, MLX_KEY_W);
		game->pl.key[MLX_KEY_S] = mlx_is_key_down(game->mlx, MLX_KEY_S);
		game->pl.key[MLX_KEY_RIGHT] = mlx_is_key_down(game->mlx, MLX_KEY_RIGHT);
		game->pl.key[MLX_KEY_LEFT] = mlx_is_key_down(game->mlx, MLX_KEY_LEFT);
		game->pl.key[MLX_KEY_C] = mlx_is_key_down(game->mlx, MLX_KEY_C);
		game->pl.key[MLX_KEY_V] = mlx_is_key_down(game->mlx, MLX_KEY_V);		
	}
	else
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_W) == 0)
			game->pl.key[MLX_KEY_W] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_S) == 0)
			game->pl.key[MLX_KEY_S] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) == 0)
			game->pl.key[MLX_KEY_RIGHT] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) == 0)
			game->pl.key[MLX_KEY_LEFT] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_C) == 0)
			game->pl.key[MLX_KEY_C] = 0;
		if (mlx_is_key_down(game->mlx, MLX_KEY_V) == 0)
			game->pl.key[MLX_KEY_V] = 0;
	}
}
