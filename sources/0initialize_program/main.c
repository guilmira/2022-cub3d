/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:00:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/20 17:00:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	framework_2D(t_prog *game);

/** PURPOSE : CUB3 uses 
 * 1. make exe.
 * 2. ./cube + [map_name.cub] */
int	main(int argc, char **argv)
{
	t_prog	*game;
	//atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	init_game(game);
	parser(game, argc, argv);
	framework_dimensions(game);
	init_map2D(game->map2D.map, game);
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}


/*
int main(void)
{
	mlx_t		*mlx;
	mlx_texture_t *sky_texture;
	uint8_t	**sky_mat;

	mlx = mlx_init(1060, 1060, TITLE_WINDOW, 1);
	sky_texture = mlx_load_png("textures/d64van-sky1pal.png");
	sky_mat = texture_to_mat(sky_texture);

}*/