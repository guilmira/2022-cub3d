/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline mlx_texture_t	*load_png_solid(const char *path, t_prog *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_shutdown("Error. PNG file invalid\n", game);
	return (texture);
}

void	prep_textures(t_prog *game)
{
	game->t_north = load_png_solid(game->north, game);
	game->t_south = load_png_solid(game->south, game);
	game->t_west = load_png_solid(game->west, game);
	game->t_east = load_png_solid(game->east, game);
}

void	destroy_texture(t_prog *game)
{
	if (game->t_north)
		mlx_delete_texture(game->t_north);
	if (game->t_south)
		mlx_delete_texture(game->t_south);
	if (game->t_west)
		mlx_delete_texture(game->t_west);
	if (game->t_east)
		mlx_delete_texture(game->t_east);
}
