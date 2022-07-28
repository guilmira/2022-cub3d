/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/28 14:17:30 by guilmira         ###   ########.fr       */
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

	

void print_map(char **map, t_prog *game)
{

	(void) map;
	printf("empieza\n");

	for (int i = 0; i < 21; i++)
	{
			printf("%s ", map[i]);
		
		printf("\n");
	}

	printf("here: \n");
	for (int j = 0; j < game->map2D.height; j++)
	{
		for (int i = 0; i < game->map2D.width; i++)
			printf("%i ", game->map2D.layout[j][i]);
		
		printf("\n");
	}
}

void update_pixel_per_block(t_prog *game)
{
	game->map2D.pixel_per_block[0] = game->w2.size[0] / game->map2D.width;
	game->map2D.pixel_per_block[1] = game->w2.size[1] / game->map2D.height;
}


/** PURPOSE : Translate parser map into a wall map */
void init_map2D(char **map, t_prog *game)
{
	int j;
	int i;
	int **layout;
	
	printf("here: %i\n", game->map_x);
	printf("here: %i\n", game->map_y);
	j = -1;
	i = -1;
	layout = NULL;
	//PACE pregunta para JOAN: ajustado manual, necesito un calculo correcto
	//diria que el width llamado map_x esta desajustado dos unidades.
	game->map2D.width = ft_strlen(game->map[0]);
	game->map2D.height = game->map_y; 
	printf("here: %i\n", game->map2D.width);
	printf("here: %i\n", game->map2D.height);

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
	main_image_framework(game);
	fill_player_pos(game, game->pl.position); //PACE tiene que autoactualizarse
	/* --------------------------------------------------------------- */
	/* --------------------------------------------------------------- */
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}