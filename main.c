/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:39:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/29 19:01:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

void ft_leaks(void)
{
	system("leaks -quiet cube");
}

/** PURPOSE : init 42minilibx and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Inits the rest of the variables within the struct. */
void	init_game(t_prog *game)
{
	game->mlx = mlx_init();//genera 3 root leaks at exit. Hay que actualizar a la nueba MLX
	if (!game->mlx)
		//hacer un shutdown;
	game->mlx_window = NULL;
	
}

/** PURPOSE : init 42minilibx, open window, and load an image.
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
		ft_shut("Malloc error\n");
	/* --------------------------------------------------------------- */
	//parser();
	init_game(game);
	init_window(game, window_dimensions);
	/* --------------------------------------------------------------- */
	
	//esto puede ser create images
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