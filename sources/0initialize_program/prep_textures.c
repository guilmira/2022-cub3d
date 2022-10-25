/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/25 12:11:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//NEXT: poner en load png solid un testeo de que la pueda abrir y tenga permisos

static inline mlx_texture_t	*load_png_solid(const char *path, t_prog *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_shutdown("Error. PNG file invalid\n", game);
	return (texture);
}

#define SPRITE "maps_and_media/textures/entities/armor1.png"
void	prep_textures(t_prog *game)
{
	game->t_north = load_png_solid(game->north, game);
	game->t_south = load_png_solid(game->south, game);
	game->t_west = load_png_solid(game->west, game);
	game->t_east = load_png_solid(game->east, game);
	game->t_east = load_png_solid(game->east, game);
//NEXT: porvisional, llevar a la estructura
	game->spr = load_png_solid(SPRITE, game);
	
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

	//NEXT: provisional
	if (game->spr)
		mlx_delete_texture(game->spr);
}
