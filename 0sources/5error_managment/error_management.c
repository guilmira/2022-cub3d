/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/19 12:52:03 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Frees array of int. */
static void clear_map2D(t_prog *game)
{
	int j;
	int i;
	
	j = -1;
	i = -1;
	while (++j < game->map2D.height)
	{
		free(game->map2D.layout[j]);
		game->map2D.layout[j] = NULL;
	}
	if (game->map2D.layout)
		free(game->map2D.layout);
	game->map2D.layout = NULL;
}

void clear_raycast(t_prog *game)
{
	if (game->rc)
	{
		if (game->rc->rc_vector)
			free(game->rc->rc_vector);
		if (game->rc->rc_distance)
			free(game->rc->rc_distance);
		if (game->rc->rc_wall_side)
			free(game->rc->rc_wall_side);
		free(game->rc);	
	}
}


/** PURPOSE : Frees allocated memory in program. */
static void clear_memory(t_prog *game)
{
	if (game)
	{
		if (game->map2D.map)
			freemat(game->map2D.map);
		if (game->NO)
			free(game->NO);
		if (game->SO)
			free(game->SO);
		if (game->WE)
			free(game->WE);
		if (game->EA)
			free(game->EA);
		clear_map2D(game);
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
	mlx_terminate(game->mlx);
	clear_memory(game);
	ft_shut(error_msg);
}

void	freemat(char **mat)
{
	int i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

void	ft_leaks(void)
{
	system("leaks -quiet cube");
}