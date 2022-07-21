/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_player_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:01:02 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 13:11:56 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void draw_player_position(mlx_image_t *image, double position[], t_vector dir, t_prog *game)
{
	double ratio;
	if (position[0] < 0 || position[1] < 0)
		ft_shutdown(EX, game);
	ratio = (0.5 * game->w2.pixel_per_block[0]);
	/* --------------------------------------------------------------- */
	/* 						CIRCLE + RECTANGLE IN THE MIDDLE */
	draw_2d_player(image, position, ratio, GREEN + RED, game); //!!! CHECKS OUT ON ENGINE.
	draw_centered_rectangle(position[0], position[1], x_size, y_size, game);
	/* --------------------------------------------------------------- */
	/* 			MAIN FUNCTION RAYCAST */
	draw_vision_beam(position, dir, FOV_DEGREE, RAYCAST_OFFSET, game);
	//coor_identifier(game->image[MAP_2D], game, game->pl.position[0], game->pl.position[1], game->w2.size[1]);
}