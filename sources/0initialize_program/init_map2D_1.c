/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/01 09:51:22 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : general function to init variables. */
void	update_pixel_per_block(t_prog *game)
{
	if (!game->minimap_state)
		return ;
	else if (game->minimap_state == 2)
	{
		game->map2D.pixel_per_block[0] = game->w2.size[0] / game->map2D.width;
		game->map2D.pixel_per_block[1] = game->w2.size[1] / game->map2D.height;
	}
	else
	{
		game->map2D.pixel_per_block[0] = game->w2.size[0] / game->map2D.width;
		game->map2D.pixel_per_block[1] = game->w2.size[1] / game->map2D.height;
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
