/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/20 19:44:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


//teoria, creo que estoy disparando pixeles a sitios usuper lejanos.

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
//int	main(int argc, char **argv)
int	main(int argc, char  **argv)
{
	t_prog	*game;
	/* --------------------------------------------------------------- */
	atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	/* --------------------------------------------------------------- */
	init_game(game);
	parser(game, argc, argv);
	framework_dimensions(game);
	create_image(game, 0, game->w1.size);
	create_image(game, 1, game->w2.size);
	main_image_framework(game);
	fill_player_pos(game, game->pl.position); //PACE tiene que autoactualizarse
	/* --------------------------------------------------------------- */
	//trace_rays();
	//virtualize_3D();
	/* --------------------------------------------------------------- */
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}