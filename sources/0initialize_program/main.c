/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/11/03 15:25:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
int	main(int argc, char **argv)
{
	t_prog	*game;

	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	init_game(game);
	parser(game, argc, argv);
	prep_textures(game);
	framework_dimensions(game);
	init_map2d(game->map2d.map, game);
	/* int i;
	int j;
	i = -1;
	j = -1; */
	/* while (++j < game->map2d.height)
	{
		while (++i < game->map2d.width)
			printf("%i ", game->map2d.layout[j][i]);
		printf("\n");
	} */
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}
