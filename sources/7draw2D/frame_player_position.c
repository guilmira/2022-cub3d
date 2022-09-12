/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_player_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:01:02 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 12:26:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void	draw_player_position(mlx_image_t *image, t_prog *game)
{
	double	position[D2];

	if (game->minimap_state != 2)
	{
		position[0] = game->pl.v_position_coor[0];
		position[1] = game->pl.v_position_coor[1];
	}
	else
	{
		update_player_location(game);
		position[0] = game->pl.position_coor[0];
		position[1] = game->pl.position_coor[1];
	}
	if (position[0] <= 0 || position[1] <= 0)
		ft_shutdown(EX, game);
	game->pl.ratio = (PLAYER_RATIO * game->map2D.pixel_per_block[0]);
	draw_2d_player(image, position, game->pl.ratio, GREEN + RED, game);
	if (game->minimap_state == 4)
		draw_centered_rectangle(position[0], position[1], x_size, y_size, game);
	if (game->minimap_state == 2)
		draw_centered_rectangle(position[0], position[1], 1, 1, game);
}
