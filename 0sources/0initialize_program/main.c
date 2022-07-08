/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/08 13:26:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* Notas guille: 
TODOs en el code. Intentar reducir al minimo.
COORDINATES on a map ar array[2], meanwhile, vectors will be t_vector!
*/

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
//int	main(int argc, char **argv)
int	main(void)
{
	t_prog		*game;

	/* --------------------------------------------------------------- */
	atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	/* --------------------------------------------------------------- */
	init_game(game);
	parser(game, argc, argv);
	//input_management();
	main_image_framework(game);
	secd_image_framework(game);
	
	/* --------------------------------------------------------------- */
	//trace_rays();
	//virtualize_3D();
	/* --------------------------------------------------------------- */
	printf("loopeando\n");
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}