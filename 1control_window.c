/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1control_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/29 18:59:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : Neat program exit.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Exit program without output message. */
void	clean_exit(t_prog *game)
{
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	exit(0);
}

/** PURPOSE : closes program with output signal. */
static int	ft_destroy(t_prog *game)
{
	clean_exit(game);
	exit(0);
}

/** PURPOSE : open window.
 * 1. Open window, save pointer for later use.
 * 2. Establishes closing window hook */
void	init_window(t_prog *game, t_vector window_dimensions)
{
	game->mlx_window = mlx_new_window(game->mlx, \
	window_dimensions.x, window_dimensions.y, TITLE_WINDOW);
	if (!game->mlx_window)
		//full shut;
	mlx_hook(game->mlx_window, 17, 0, ft_destroy, game);
}
