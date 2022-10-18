/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/13 15:13:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline int count_enemys(int *layout, int height, int width, t_prog *game)
{
	int i;
	int x;
	int count;

	i = -1;
	count = 0;
	while(++i < height)
	{
		x = -1;
		while(++x < width)
		{
			if(layout[i][x] == 'X')
			{
				if (game)
				{
					game->enemys[count].position[0] = x * \
						(double) game->map2D.pixel_per_block[0] + \
						((double) game->map2D.pixel_per_block[0] / 2);
					game->enemys[count].position[1] = y * \
					(double) game->map2D.pixel_per_block[1] + \
					((double) game->map2D.pixel_per_block[1] / 2);
				}
				count++;
			}
		}
	}
	return(count);
}



void init_enemys(t_prog *game)
{
	int i;

	game->n_alive_enemy = count_enemys(game->layout, game->height, game->width, NULL);
	if (game->n_alive_enemy != 0)
		game->enemys =  malloc(sizeof(t_enemy) * game->n_alive_enemy);
	else
		return ;
	game->n_alive_enemy = count_enemys(game->layout, game->height, game->width, game);
	i = -1;
	while (++i < game->n_alive_enemy)
	{
		game->enemys[i].ratio = game->pl.ratio;
		game->enemys[i].speed = 0.001;
		game->enemys[i].health = 100;
		game->enemys[i].damage = 25;
	}
}