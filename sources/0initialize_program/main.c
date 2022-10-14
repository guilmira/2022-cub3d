/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 16:14:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
//NEXT
void			ft_leaks(void);

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
