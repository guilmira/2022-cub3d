/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline void	do_spaced_h(int height, int width, int flag, t_prog *game)
{
	int	i;
	int	k;
	int	count;

	i = -1;
	while (++i < height)
	{
		k = -1;
		count = -1;
		while (++count != game->map2d.val)
			game->map2d.s_layout[i][count] = 0;
		while (++k < game->map2d.width)
		{
			game->map2d.s_layout[i][count] = game->map2d.layout[i][k];
			count++;
		}
		while (count != width)
			game->map2d.s_layout[i][count++] = 0;
	}
	k = -1;
	if (flag == 1)
		while (++k != width)
			game->map2d.s_layout[height][k] = 0;
}

static inline void	buildheight(t_prog *game, int height, int width)
{
	float	val;
	int		subti;
	int		flag;

	val = height - width;
	subti = width + (ceil(val / 2) * 2);
	if ((int)ceil(val) % 2 == 0)
	{
		flag = 0;
		game->map2d.s_layout = allocate_all_layout(height, subti);
	}
	else
	{
		flag = 1;
		game->map2d.s_layout = allocate_all_layout(height + 1, subti);
	}
	game->map2d.val = (int)ceil(val / 2);
	do_spaced_h(height, subti, flag, game);
	game->map2d.s_width = subti;
	if (flag == 0)
		game->map2d.s_height = height;
	else
		game->map2d.s_height = height + 1;
	game->pl.position[0] += game->map2d.val;
	game->pl.position[1] = game->map2d.s_height - game->pl.position[1] - 1;
}

void	build_spaced_layout(t_prog *game, int height, int width)
{
	if (height > width)
		buildheight(game, height, width);
	else if (height < width)
		buildwidth(game, height, width);
	else
	{
		game->map2d.s_layout = copy_double_pointer(game->map2d.layout,
				game->map2d.height, game->map2d.width);
		game->map2d.s_height = game->map2d.height;
		game->map2d.s_width = game->map2d.width;
		game->pl.position[1] = game->map2d.s_height - game->pl.position[1] - 1;
	}
	print_smap(game->map2d.s_layout, game->map2d.s_height, game->map2d.s_width);
}
