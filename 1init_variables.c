/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1init_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:33:53 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/30 12:06:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

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
	game->map = NULL;
	game->file = 0;
}
