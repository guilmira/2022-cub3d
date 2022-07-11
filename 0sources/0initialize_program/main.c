/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/08 15:37:47 by guilmira         ###   ########.fr       */
=======
/*   Updated: 2022/07/09 14:23:44 by guilmira         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* Notas guille: 
PACE s en el code. Intentar reducir al minimo.
JAMAS METER DECIMALES, DIVISIONES; Desde DEFINE
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
	//parser(game, argc, argv);
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