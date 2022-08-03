/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/03 11:03:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Requires parser executed and game stored at heap.
 * 1. Initialize the dimensions of both of the windows.
 * 2. Create images dor both of the frameworks, 3D and 2D minimap. */
void init_framework(t_prog *game)
{
	framework_dimensions(game);
	create_image(game, 0, game->w1.size);
	create_image(game, 1, game->w2.size);
}

//PACE:
//si tiene el offset de 2 (uno a cada lado, ese offset hay que meterseloa player)
//fluent movement
//parpadea un frame al hacer tab

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
int	main(int argc, char  **argv)
{
	t_prog	*game;
	/* --------------------------------------------------------------- */
	//atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	/* --------------------------------------------------------------- */
	init_game(game);
	parser(game, argc, argv);
	init_framework(game);
	init_map2D(game->map, game);
	
	/* --------------------------------------------------------------- */
	fill_player_pos(game, game->pl.position); //PACE tiene que autoactualizarse
	
	//PACE unificar pixel per block
	//map_x y map_y desvincular del offset y dejar solo uno.

	/* --------------------------------------------------------------- */
	/* --------------------------------------------------------------- */
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}