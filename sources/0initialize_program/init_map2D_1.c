/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/13 14:39:13 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	control_window_limits(t_prog *game)
{
	if (game->w1.size[0] < WINDOW_LOWER_LIMIT \
	|| game->w1.size[1] < WINDOW_LOWER_LIMIT)
		ft_shutdown("Window size must be bigger than 1000\n", game);
	if (game->w1.size[0] > WINDOW_UPPER_LIMIT \
	|| game->w1.size[1] > WINDOW_UPPER_LIMIT)
		ft_shutdown("Window size must be smaller than 2500\n", game);
}

void	freemat_int(int **mat, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		free(mat[i]);
	free(mat);
}

/** PURPOSE : general function to init variables. */
void	update_pixel_per_block(t_prog *game)
{
	if (game->w2.size[1] < game->w2.size[0])
	{
		game->map2D.pixel_per_block[0] = game->w2.size[1] / game->map2D.width;
		game->map2D.pixel_per_block[1] = game->w2.size[1] / game->map2D.height;
	}
	else
	{
		game->map2D.pixel_per_block[0] = game->w2.size[0] / game->map2D.width;
		game->map2D.pixel_per_block[1] = game->w2.size[0] / game->map2D.height;
	}
}

/** PURPOSE : Allocate all memory for 2D array. */
int	**allocate_all_layout(int height, int width)
{
	int	j;
	int	**layout;

	j = -1;
	layout = ft_calloc(height, sizeof(int *));
	while (++j < height)
		layout[j] = ft_calloc(width, sizeof(int));
	return (layout);
}
