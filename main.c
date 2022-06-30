/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:39:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/30 11:08:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

void ft_leaks(void)
{
	system("leaks -quiet cube");
}

/** PURPOSE : Describe CUBE.
 * 1. Define structure of program. */
int main(void)
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
	//parser();
	init_game(game);
	init_window(game, window_dimensions);
	/* --------------------------------------------------------------- */
	
	//trace_rays();
	//create_images();
	//detect_hooks();
	t_data image;

	image.img = mlx_new_image(game->mlx, OX_WINDOW, OX_WINDOW);

	image.addr = mlx_get_data_addr\
	(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	for (int i = 500; i < 1915; i++)
		my_mlx_pixel_put(&image, i, 501, get_opposite( trgb_translate(0, 150, 150, 0)));

	mlx_put_image_to_window(game->mlx, game->mlx_window, image.img, 0, 0);
	/* --------------------------------------------------------------- */
	
	mlx_loop(game->mlx);
	return (0);
}