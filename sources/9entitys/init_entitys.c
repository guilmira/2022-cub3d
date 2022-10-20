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

void	draw_2d_enemys(double pos[], \
	int colour, t_prog *game, double ratio)
{
	double	i[2];

	i[0] = -1 - ratio;
	while (++i[0] < (ratio * 2))
	{
		i[1] = -1 - ratio;
		while (++i[1] < (ratio * 2))
		{
			if (check_radio(i, ratio))
			{
				solid_pixel(game->image[CUB_3D], i[0] + pos[0], \
				coor(i[1] + pos[1], game->w2.size[1]), colour);
			}
		}
	}
}

void	draw_all_entitys(t_prog *game)
{
	int i;

	i = -1;
	while (++i < game->n_entitys)
	{
		if (game->entity[i].letter == 'X')
			draw_2d_enemys(game->entity[i].position, BLUE + RED, game, game->entity[i].visual_ratio);
		if (game->entity[i].letter == 'C')
			draw_2d_enemys(game->entity[i].position, GREEN, game, game->entity[i].visual_ratio);
		if (game->entity[i].letter == 'R')
			draw_2d_enemys(game->entity[i].position, BLUE, game, game->entity[i].visual_ratio);
	}
}

static inline int count_entitys(char **layout, int height, int width, t_prog *game)
{
	int coord[2];
	int count;

	coord[1] = -1;
	count = 0;
	while(++coord[1] < height)
	{
		coord[0] = -1;
		while(++coord[0] < width)
		{
			if (layout[coord[1]][coord[0]] == 'X' || layout[coord[1]][coord[0]] == 'R' || layout[coord[1]][coord[0]] == 'C')
			{
				if (game)
					set_entitys_structure(layout[coord[1]][coord[0]], game, count, coord);
				count++;
			}
		}
	}
	return(count);
}



void init_entitys(t_prog *game, char **map)
{
	game->n_entitys = count_entitys(map, game->map2d.height, game->map2d.width, NULL);
	if (game->n_entitys != 0)
		game->entity =  malloc(sizeof(t_entity) * game->n_entitys);
	else
		return ;
	game->n_entitys = count_entitys(map, game->map2d.height, game->map2d.width, game);
	int i = -1;
	printf("PLAYER\n");
	printf("X:%f Y:%f\n", game->pl.position_coor[0], game->pl.position_coor[1]);
	printf("%F\n", game->pl.ratio);
	while(++i < game->n_entitys)
	{
		printf("%c:\n", game->entity[i].letter);
		printf("X:%f Y:%f\n", game->entity[i].position[0], game->entity[i].position[1]);
		printf("VISUAL: %f\n", game->entity[i].visual_ratio);
	}
}