/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/07 14:03:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* #define N 0.0000001
 	printf("h %d y %.15f\n", N, N); //NEXT
	printf("%.15f\n", 1 / 1000); //NEXT
	printf("%.15f\n", (double) 1 / (double) 1000); //NEXT */

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
int	main(int argc, char **argv)
{
	t_prog	*game;

	atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	init_game(game);
	parser(game, argc, argv);
	prep_textures(game);
	framework_dimensions(game);
	init_map2d(game->map2D.map, game);
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}
