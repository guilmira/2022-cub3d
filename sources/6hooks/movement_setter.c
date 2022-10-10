/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_setter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/07 12:54:32 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	set_key_state(t_prog *game)
{
	game->pl.key[MLX_KEY_W] = mlx_is_key_down(game->mlx, MLX_KEY_W);
	game->pl.key[MLX_KEY_S] = mlx_is_key_down(game->mlx, MLX_KEY_S);
	game->pl.key[MLX_KEY_A] = mlx_is_key_down(game->mlx, MLX_KEY_A);
	game->pl.key[MLX_KEY_D] = mlx_is_key_down(game->mlx, MLX_KEY_D);
	game->pl.key[MLX_KEY_RIGHT] = mlx_is_key_down(game->mlx, MLX_KEY_RIGHT);
	game->pl.key[MLX_KEY_LEFT] = mlx_is_key_down(game->mlx, MLX_KEY_LEFT);
	game->pl.key[MLX_KEY_C] = mlx_is_key_down(game->mlx, MLX_KEY_C);
	game->pl.key[MLX_KEY_V] = mlx_is_key_down(game->mlx, MLX_KEY_V);
}

void	reset_key_state(t_prog *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) == 0)
		game->pl.key[MLX_KEY_W] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) == 0)
		game->pl.key[MLX_KEY_S] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) == 0)
		game->pl.key[MLX_KEY_A] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) == 0)
		game->pl.key[MLX_KEY_D] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) == 0)
		game->pl.key[MLX_KEY_RIGHT] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) == 0)
		game->pl.key[MLX_KEY_LEFT] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_C) == 0)
		game->pl.key[MLX_KEY_C] = 0;
	if (mlx_is_key_down(game->mlx, MLX_KEY_V) == 0)
		game->pl.key[MLX_KEY_V] = 0;
}
