/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:39:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/01 12:09:10 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

//->
void	draw_grid(t_data *image, t_prog *game)
{
	

	image->img = mlx_new_image(game->mlx, OX_WINDOW, OY_WINDOW);
	image->addr = mlx_get_data_addr\
	(image->img, image->bits_per_pixel, image->line_length, image->endian);
	for (int nb = 0; nb < 10; nb++)
	{
		for (int j = 0; j < OY_WINDOW; j++)
			my_mlx_pixel_put(image, ( nb * (OX_WINDOW /10) ), j, trgb_translate(0, 255, 255, 255));
		for (int i = 0; i < OX_WINDOW; i++)
			my_mlx_pixel_put(image, i, ( nb * (OY_WINDOW /10) ), trgb_translate(0, 255, 255, 255));
	}
}

/* void draw_line(t_data *image, int limit, int slope, int n)
{	
	int y;

	for (int x = 0; x < n + limit; x++)
	{
		y = slope * x + n;
		my_mlx_pixel_put(image, x + n , y, trgb_translate(0, 0, 0, 255));
		my_mlx_pixel_put(image, limit - (x + n) , y, trgb_translate(0, 0, 0, 255));
	}
} */

/* void	draw_arrow(t_prog *game, int x, int y, int size)
{
	t_data image;
	int height_image;
	int width_image;

	if (x - size < 0 || y  - size < 0)
		return ;


	height_image = size + 1;
	width_image = size + 1;
	image.img = mlx_new_image(game->mlx, width_image, height_image);
	image.addr = mlx_get_data_addr\
	(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	draw_line(&image, size / 140 , 1, width_image / 2);

	my_mlx_pixel_put(&image, width_image / 2 , height_image / 2, trgb_translate(0, 0, 255, 0));
	mlx_put_image_to_window(game->mlx, game->mlx_window, image.img, x - size, y - size);
} */

int coor(int y)
{
	return (OY_WINDOW - y);
}


void draw_player_position(t_data *image, t_prog *game)
{
	my_mlx_pixel_put(&image, 0, coor(5), trgb_translate(0, 0, 255, 0));

}


void draw_image(t_prog *game)
{
	t_data image;

	draw_grid(&image, game);
	draw_player_position(&image, game);

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