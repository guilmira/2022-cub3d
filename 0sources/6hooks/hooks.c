/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:40:37 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 06:30:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : manage keys. */
void	hk_keys(mlx_key_data_t key, void *game)
{
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(game);
}

/** PURPOSE : manage window closing or 
 * exiting with other widgets/tools. */
void	hk_close(void *game)
{
	clean_exit(game);
}

//PARA BORRAR

void	draw_ggrid(mlx_image_t *image, t_prog *game, double size_x, double size_y)
{
	int nb;

	//coor_identifier(image, game, 1800, 20, game->w2.size[1], 0);
	nb = -1;
	while (++nb < 11)
	{
		put_horizontal(image, ( nb * game->w2.unit[1]), size_x, WHITE);
		put_vertical(image, ( nb * game->w2.unit[0]), size_y, WHITE);
	}
	if (0)
		ft_shutdown(EX, game);
}

void	secdd_image_framework(t_prog *game)
{
	mlx_image_t	*image;
	double	player_pos[2]; //PACE calcular el player position (meterlo en la estructura)

	player_pos[0] = 5 * game->w2.unit[0];
	player_pos[1] = 1 * game->w2.unit[1]; //PACE see whats up at 0,0

	image = mlx_new_image(game->mlx,\
	(int) game->w2.size[0], (int) game->w2.size[1]);
	if (!image)
		ft_shutdown(EX3, game);
	game->image[1] = image; 
	/* --------------------------------------------------------------- */
	draw_ggrid(image, game, game->w2.size[0], game->w2.size[1]);
	coor_identifier(image, game, player_pos[0], player_pos[1], OY_MINIMAP, 0);
	
	t_vector dir;
	dir.x = 0.2;
	dir.y = 1;
	draw_player_position(image, player_pos, dir, game); //PACE ejemplo, un 0,0 aqui provoca un seg fault
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	image, game->w2.origin[0], game->w2.origin[1]);
}

/** PURPOSE : Hook loop function. */
void next_frame(void *game)
{
	static int frame;

	
	/* double time_spent = 0.0;	
	clock_t begin = clock(); */
	frame++;

	usleep(1000000);

	secdd_image_framework(game);
	
	/* clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */
	
	
}

/** PURPOSE : execute main routine of program.
 * mlx_loop and mlx_loop_hook will tried to be executed a total
 * of 60 times pers second. Therefore 60 fps. */
void	hooks_and_loops(t_prog *game)
{
	mlx_close_hook(game->mlx, &hk_close, (void *) game);
	mlx_key_hook(game->mlx, &hk_keys, game);
	//
		
	mlx_loop_hook(game->mlx, &next_frame, game);
	//
	
	mlx_loop(game->mlx);
}