/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vison_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:11:49 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/06 15:49:12 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : correct vision by adding correct plane vector. */
static void update_player_vision(int key, t_prog *game)
{
	t_vector	plane_perpendicular;
	t_vector	original_vision;
	double		angle_rotation;
	double		lenght;

	original_vision = game->pl.vis;
	angle_rotation = VISION_ANGLE_ROTATION + 20;
	plane_perpendicular = get_unit_vector(get_perpendicular(original_vision));
	if (game->pl.flag_trance)
		angle_rotation = TRANCE_BOOST; //it will be halved
	lenght = calculate_plane_lenght(angle_rotation, original_vision);
	lenght = fabs(lenght);
	plane_perpendicular = mul_vec(plane_perpendicular, lenght);
	if (key == key_lookright)
		game->pl.vis = get_unit_vector(sum_vec(original_vision, invert_sense_vector(plane_perpendicular)));
	else
		game->pl.vis = get_unit_vector(sum_vec(original_vision, (plane_perpendicular)));	
}

/** PURPOSE : control field of vision. */
void	vison_control(mlx_key_data_t key, t_prog *game)
{
	(void) key;
	game->pl.flag_movement = 1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		update_player_vision(key_lookright, game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		update_player_vision(key_lookleft, game);
}