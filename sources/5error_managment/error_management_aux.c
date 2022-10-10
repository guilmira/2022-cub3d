/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/07 13:08:59 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	clear_raycast(t_prog *game)
{
	if (game->rc)
	{
		if (game->rc->rc_vector)
			free(game->rc->rc_vector);
		if (game->rc->rc_distance)
			free(game->rc->rc_distance);
		if (game->rc->rc_wall_side)
			free(game->rc->rc_wall_side);
		if (game->rc->rc_wall_hit_x)
			free(game->rc->rc_wall_hit_x);
		if (game->rc->rc_wall_hit_y)
			free(game->rc->rc_wall_hit_y);
		free(game->rc);
	}
}

void	freemat(char **mat)
{
	int	i;

	i = -1;
	while (mat[++i])
		free(mat[i]);
	free(mat);
}

void	ft_leaks(void)
{
	system("leaks -quiet cube");
}
