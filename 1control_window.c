/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1control_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/30 11:30:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : its necesary because clean_exit returns void. */
static int	ft_destroy(t_prog *game)
{
	clean_exit(game);
	return (0);
}

/** PURPOSE : open window.
 * 1. Open window, save pointer for later use.
 * 2. Establishes closing window hook */
void	init_window(t_prog *game, t_vector window_dimensions)
{
	game->mlx_window = mlx_new_window(game->mlx, \
	window_dimensions.x, window_dimensions.y, TITLE_WINDOW);
	if (!game->mlx_window)
		ft_shutdown(EX2, game);
	mlx_hook(game->mlx_window, DESTROY_EVENT, 0, ft_destroy, game);
}


/** PURPOSE : init 42minilibx and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). 
 * The library functions need it in order to work.
 * 2. Inits the rest of the variables within the struct. */
void	init_game(t_prog *game)
{
	game->mlx_window = NULL; //it has to go 1st
	game->mlx = mlx_init(); //genera 3 root leaks at exit. Hay que actualizar a la nueba MLX
	if (!game->mlx)
		ft_shutdown("MLX could not be initialized\n", game);
	//INIT all pointers to NULL, variables to zero.
	//game->whatever_ptr = NULL;


}