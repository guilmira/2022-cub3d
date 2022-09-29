/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:25:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/29 17:15:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draws on the minimap the result of the raycast calculations. */
static inline void	draw_raycast(t_prog *game)
{
	int			i;
	t_vector	ray;
	int			colour;

	colour = rgb_t_translate(255, 150, 0, 255);
	i = -1;
	while (++i < game->rc->number_of_rays)
	{
		ray = game->rc->rc_vector[i];
		ray.y = ray.y - 1;
		draw_vector(ray, game->pl.position_coor, colour, game);
	}
	ray = game->rc->vision;
	draw_vector(ray, game->pl.position_coor, colour, game);
}

/** PURPOSE : 60 frames per second function. 
 * pl.flag_movement to zero deactivates drawing until further movement. */
void	put_frame_two_dim(t_prog *game)
{
	if (game->minimap_state)
	{
		wash_screen(game, game->image[CUB_3D], game->w2, BLACK);
		framework_2D(game);
		draw_raycast(game);
	}
}
