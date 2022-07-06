/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/05 14:43:36 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Close window if exists. */
/*static void	clear_window(t_prog *game)
{
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
}
*/
/** PURPOSE : Frees allocated memory in program. */
static void clear_memory(t_prog *game)
{
    if (game)
    {
        //Free all allocated memory (access by pointers);
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


/** PURPOSE : Neat program exit. Call at the end.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Exits with value 0. */
void	clean_exit(t_prog *game)
{
	//clear_window(game);
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
	//clear_window(game);
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