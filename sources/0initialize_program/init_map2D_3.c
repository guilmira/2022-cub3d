/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/08/20 16:55:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static	inline int	fill_s_map(t_prog *game, int width, int flag)
{
	int	i;
	int	k;
	int	count;

	i = -1;
	count = -1;
	while (++count != game->map2D.val)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = 0;
		if (flag == 1)
			game->map2D.s_layout[count][width] = 0;
	}
	while (++i < game->map2D.height)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = game->map2D.layout[i][k];
		if (flag == 1)
			game->map2D.s_layout[count][width] = 0;
		count++;
	}
	return (count);
}

static inline void	do_spaced_w(int height, int width, int flag, t_prog *game)
{
	int	k;
	int	count;

	count = fill_s_map(game, width, flag);
	while (count != height)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = 0;
		if (flag == 1)
			game->map2D.s_layout[count][width] = 0;
		count++;
	}
	game->map2D.s_height = height;
	if (flag == 0)
		game->map2D.s_width = width;
	else
	{
		game->map2D.s_width = width + 1;
		game->pl.position[0] += 1;
	}
}

void	buildwidth(t_prog *game, int height, int width)
{
	float	val;
	int		subti;
	int		flag;

	val = width - height;
	subti = height + (ceil(val / 2) * 2);
	if ((int)ceil(val) % 2 == 0)
	{
		flag = 0;
		game->map2D.s_layout = allocate_all_layout(subti, width);
	}
	else
	{
		flag = 1;
		game->map2D.s_layout = allocate_all_layout(subti, width + 1);
	}
	game->map2D.val = (int)ceil(val / 2);
	do_spaced_w(subti, width, flag, game);
	game->pl.position[1] = (game->map2D.s_height - game->map2D.val
			- game->pl.position[1] - 1);
}
