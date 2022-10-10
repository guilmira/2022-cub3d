/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/07 14:04:32 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/* NEXT QUITAR ESTO */
void	log_coor(double array[])
{
	printf("Coordinates:						\
	OX %f y  OY %f\n", array[0], array[1]);
}

void	log_coor_int(int i[])
{
	printf("INT:						\
	OX %i y  OY %i\n", i[0], i[1]);
}

/*void	print_map(char **map, t_prog *game, int **s_map)
{
	(void) map;
	printf("empieza\n");
	for (int j = 0; j < game->map2D.height; j++)
	{
		for (int i = 0; i < game->map2D.width; i++)
			printf("%i ", s_map[j][i]);
		printf("\n");
	}
	printf("altura %i\n", game->map2D.height);
	printf("anchura %i\n", game->map2D.width);
}
*/