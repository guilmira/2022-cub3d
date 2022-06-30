/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2control_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/30 15:20:58 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : its necesary because clean_exit returns void. */


/** PURPOSE : open window.
 * 1. Open window, save pointer for later use.
 * 2. Establishes closing window hook */
void	init_window(t_prog *game, t_vector window_dimensions)
{
	game->mlx_window = mlx_new_window(game->mlx, \
	window_dimensions.x, window_dimensions.y, TITLE_WINDOW);
	if (!game->mlx_window)
		ft_shutdown(EX2, game);
		
	printf("va x aki\n");
	//mlx_hook(game->mlx_window, DESTROY_EVENT, 0, ft_destroy, game);

	printf("va x aki2\n");

}
