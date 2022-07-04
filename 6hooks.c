/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6hooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:40:37 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 06:30:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : manage esc key and normal mov (in the future). */
static int	movement_character(int key, t_prog *game)
{
	if (key == ESCAPE_KEY)
		clean_exit(game);
	return (0);
}

/** PURPOSE : execute main routine of program.
 * mlx_loop and mlx_loop_hook will tried to be executed a total
 * of 60 times pers second. Therefore 60 fps. */
void	hooks_and_loops(t_prog *game)
{
	mlx_key_hook(game->mlx_window, movement_character, game);
	mlx_loop(game->mlx);
}
