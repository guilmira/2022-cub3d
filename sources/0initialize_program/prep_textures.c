/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/01 09:43:29 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	prep_textures(t_prog *game)
{
	game->t_NO = mlx_load_png(game->NO);
	game->t_SO = mlx_load_png(game->SO);
	game->t_WE = mlx_load_png(game->WE);
	game->t_EA = mlx_load_png(game->EA);
}

void	destroy_texture(t_prog *game)
{
	if (game->t_NO)
		mlx_delete_texture(game->t_NO);
	if (game->t_SO)
		mlx_delete_texture(game->t_SO);
	if (game->t_WE)
		mlx_delete_texture(game->t_WE);
	if (game->t_EA)
		mlx_delete_texture(game->t_EA);
}
