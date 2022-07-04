/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:39:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 12:16:55 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

void	draw_grid(t_data *image, t_prog *game)
{
	for (int nb = 0; nb < 10; nb++)
	{
		for (int j = 0; j < OY_WINDOW; j++)
			my_mlx_pixel_put(image, ( nb * (OX_WINDOW / OX_DIV) ), j, trgb_translate(0, 255, 255, 255));
		for (int i = 0; i < OX_WINDOW; i++)
			my_mlx_pixel_put(image, i, ( nb * (OY_WINDOW / OY_DIV) ), trgb_translate(0, 255, 255, 255));
	}
	if (0)
		ft_shutdown(EX, game);
}

/** PURPOSE : Build basic image parameters
 * 1. Creates image of given size
 * 2. Once the size of the image is */
void build_image_parameters(t_data *image, t_prog *game)
{
	image->img = mlx_new_image(game->mlx, OX_WINDOW, OY_WINDOW);
	image->addr = mlx_get_data_addr\
	(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

void draw_image(t_prog *game)
{
	t_data image;

	build_image_parameters(&image, game);
	draw_grid(&image, game);
	draw_player_position(&image, 2 * OX_UNIT, 2 * OY_UNIT, game);
	mlx_put_image_to_window(game->mlx, game->mlx_window, image.img, 0, 0);

	//draw_arrow(&image, game, 500, 520, 80);
}

/** PURPOSE : Describe CUBE.
 * 1. Define structure of program. */
int	main(void)
{
	t_prog		*game;
	t_vector	window_dimensions;

	window_dimensions.x = OX_WINDOW;
	window_dimensions.y = OY_WINDOW;
	/* --------------------------------------------------------------- */
	atexit(ft_leaks);
	game = ft_calloc(1, sizeof(t_prog));
	if (!game)
		ft_shut(EX1);
	/* --------------------------------------------------------------- */
	init_game(game);

	//parser(game, argc, argv);
	//input_management();

	init_window(game, window_dimensions);

	/* --------------------------------------------------------------- */
	//trace_rays();
	//create_images();
	//detect_hooks();

	draw_image(game);
	
	
	/* --------------------------------------------------------------- */
	hooks_and_loops(game);
	clean_exit(game);
	return (0);
}