/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vison_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/22 16:56:54 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : correct vision by adding correct plane vector. */
static void update_player_vision(int key, t_prog *game)
{
	t_vector plane_perpendicular;

	plane_perpendicular = get_perpendicular(game->pl.beam.vis);
	if (key == key_lookright)
		game->pl.vis = sum_vec(game->pl.vis, get_unit_vector(plane_perpendicular));
	else
		game->pl.vis = sum_vec(game->pl.vis, get_unit_vector(invert_sense_vector(plane_perpendicular)));
}

/** PURPOSE : control field of vision. */
void	vison_control(mlx_key_data_t key, t_prog *game)
{
	(void) key;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		update_player_vision(key_lookright, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		update_player_vision(key_lookleft, game);
}