/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/28 16:15:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


/** PURPOSE : Translate parser map into a wall map */
void init_map2D(char **map, t_prog *game)
{
	int j;
	int i;
	int **layout;
	
	j = -1;
	i = -1;
	layout = NULL;
	/* --------------------------------------------------------------- */
	//PACE pregunta para JOAN: ajustado manual, necesito un calculo correcto
	//diria que el width llamado map_x esta desajustado dos unidades.
	game->map2D.width = ft_strlen(game->map[0]);
	game->map2D.height = game->map_y; 
	/* --------------------------------------------------------------- */
	layout = ft_calloc(game->map2D.height, sizeof(int *));
	while (++j < game->map2D.height)
	{
		layout[j] = ft_calloc(game->map2D.width, sizeof(int));
		while (++i < game->map2D.width)
		{
			if (map[j][i] == '1')
				layout[j][i] = 1;
			else
				layout[j][i] = 0;
		}
		i = -1;
	}
	game->map2D.layout = layout;
	/* print_map(map, game);
	sleep(100); */
	update_pixel_per_block(game);
}