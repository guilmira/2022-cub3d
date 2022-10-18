/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Frees array of int. */
static void	clear_map_two_dim(int **map, int height)
{
	int	j;

	j = -1;
	while (++j < height)
	{
		free(map[j]);
		map[j] = NULL;
	}
	if (map)
		free(map);
	map = NULL;
}

/** PURPOSE : Frees allocated memory in program. */
static void	clear_memory(t_prog *game)
{
	if (game)
	{
		if (game->map2d.map)
			freemat(game->map2d.map);
		if (game->north)
			free(game->north);
		if (game->south)
			free(game->south);
		if (game->west)
			free(game->west);
		if (game->east)
			free(game->east);
		destroy_texture(game);
		clear_map_two_dim(game->map2d.layout, game->map2d.height);
		clear_map_two_dim(game->map2d.s_layout, game->map2d.s_height);
		clear_raycast(game);
		free(game);
	}
}

/** PURPOSE : Safely remove all images stored. */
static void	clear_images(t_prog *game)
{
	int	i;

	i = -1;
	while (game->image[++i])
		ft_mlx_delete_image_safe(i, game);
}

/** PURPOSE : Neat program exit. Call at the end.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Exits with value 0. */
void	clean_exit(t_prog *game)
{
	clear_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	clear_memory(game);
	exit(0);
}

/** PURPOSE : Neat program shut. Call if error.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated. 
 * 3. Outputs error message to STD_ERROR.
 * 4. Exit with error code. */
void	ft_shutdown(char *error_msg, t_prog *game)
{
	clear_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	clear_memory(game);
	ft_shut(error_msg);
}
