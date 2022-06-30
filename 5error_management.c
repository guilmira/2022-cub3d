/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5error_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/30 15:24:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : Close window if exists. */
static void	clear_window(t_prog *game)
{
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
}

/** PURPOSE : Frees allocated memory in program. */
static void	clear_memory(t_prog *game)
{
	if (game)
	{
		//Free all allocated memory (access by pointers);
		free(game);
	}
}

/** PURPOSE : Neat program exit. Call at the end.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated.
 * 3. Exits with value 0. */
void	clean_exit(t_prog *game)
{
	clear_window(game);
	clear_memory(game);
	//exit(0);
}

/** PURPOSE : Neat program shut. Call if error.
 * 1. Close window if exists.
 * 2. Clean memory for all structs allocated. 
 * 3. Outputs error message to STD_ERROR.
 * 4. Exit with error code. */
void	ft_shutdown(char *error_msg, t_prog *game)
{
	clear_window(game);
	clear_memory(game);
	ft_shut(error_msg);
}

void	ft_leaks(void)
{
	system("leaks -quiet cube");
}
