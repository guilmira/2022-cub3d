/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/07 15:04:14 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Frees allocated memory in program. */
static void clear_memory(t_prog *game)
{
	if (game)
	{
		if (game->map)
			freemat(game->map);
		if (game->NO)
			free(game->NO);
		if (game->SO)
			free(game->SO);
		if (game->WE)
			free(game->WE);
		if (game->EA)
			free(game->EA);
		free(game);
    }
}

void	clear_images(t_prog *game)
{
	int	i;

	i = -1;
	while (game->image[++i])
		mlx_delete_image(game->mlx, game->image[i]);
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

void	ft_leaks(void)
{
	system("leaks -quiet cube");
}

void    freemat(char **mat)
{
    int i;

    i = -1;
    while (mat[++i])
        free(mat[i]);
    free(mat);
}