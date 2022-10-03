/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/03 12:50:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline mlx_texture_t *load_png_solid(const char *path, t_prog *game)
{
	mlx_texture_t *texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_shutdown("Error. PNG file invalid\n", game);
	return (texture);
}

void	prep_textures(t_prog *game)
{
	game->t_NO = load_png_solid(game->NO, game);
	game->t_SO = load_png_solid(game->SO, game);
	game->t_WE = load_png_solid(game->WE, game);
	game->t_EA = load_png_solid(game->EA, game);
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
