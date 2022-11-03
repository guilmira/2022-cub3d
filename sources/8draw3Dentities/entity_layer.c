/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_layer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:23:33 by guilmira          #+#    #+#             */
/*   Updated: 2022/11/03 15:15:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	draw_entity_layer(t_prog *game)
{
	mlx_texture_t *spr;

	//falta un open y parseo, checkeo de que existe
	//hacer con el raycast, que venga previamente calculado que calcularse en el raycast
	int i  = -1;
	while (++i < game->rc->number_of_rays)
		printf("%.2f ", game->rc->rc_distance[i]);

	printf("\n");

	spr = game->spr;
	mlx_draw_texture(game->image[CUB_3D], spr, game->w1.size[0] / 2, game->w1.size[1] / 2);

	//draw_textured_enemy()

}