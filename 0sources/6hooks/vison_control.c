/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vison_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/15 18:02:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : correct vision by adding correct plane vector. */
static void update_player_vision(int key, t_prog *game)
{
	t_vector	plane_perpendicular;
	t_vector	new_vision;
	double		speed_multiplier;

	speed_multiplier = 30;
	if (game->pl.flag_trance)
		speed_multiplier = TRANCE_BOOST * 5;
	printf("--------------\n");
	log_vector(get_perpendicular(game->pl.vis));
	printf("--------------\n");
	plane_perpendicular = get_unit_vector(get_perpendicular(game->pl.vis));
	plane_perpendicular = mul_vec(plane_perpendicular, speed_multiplier);
	
	if (key == key_lookright)
		new_vision = get_unit_vector(sum_vec(game->pl.beam.vis, invert_sense_vector(plane_perpendicular)));
	else
		new_vision = get_unit_vector(sum_vec(game->pl.beam.vis, (plane_perpendicular)));
	game->pl.vis = new_vision;
	printf("--------------\n");
	log_vector(plane_perpendicular);
	log_vector(game->pl.vis);
	log_vector(new_vision);
	printf("--------------\n");
}

/** PURPOSE : control field of vision. */
void	vison_control(mlx_key_data_t key, t_prog *game)
{
	(void) key;
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		update_player_vision(key_lookright, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		update_player_vision(key_lookright, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		update_player_vision(key_lookleft, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		update_player_vision(key_lookleft, game);
}