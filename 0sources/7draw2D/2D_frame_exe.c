/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:25:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 12:25:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Draws on the minimap the result of the raycast calculations. */
static void	draw_raycast(t_prog *game)
{
	int			i;
	t_vector	ray;
	int			colour;

	colour = trgb_translate(255, 150, 0, 255);
	i = -1;
	while (++i < game->rc->number_of_rays)
	{
		ray = game->rc->rc_vector[i];
		ray.y = ray.y - 1; //ojo con este truco, habra que mirarlo
		draw_vector(ray, game->pl.position_coor, colour, game);
	}
	ray = game->rc->vision;
	draw_vector(ray, game->pl.position_coor, colour, game);


}

/** PURPOSE : 60 frames per second function. 
 * pl.flag_movement == 0 deactivates drawing until further movement. */
void	put_frame2D(t_prog *game)
{
	if (game->minimap_state)
	{
		framework_2D(game);
		draw_raycast(game);
	}
}

