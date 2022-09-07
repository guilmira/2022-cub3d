/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 16:55:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void do_spaced_map_h(int height, int width, int flag, t_prog *game)
{
	int i;
	int k;
	int count;

	i = -1;
	while(++i < height)
	{
		k = -1;
		count = -1;
		while(++count != game->map2D.val)
			game->map2D.s_layout[i][count] = 0;
		while(++k < game->map2D.width)
		{
			game->map2D.s_layout[i][count] = game->map2D.layout[i][k];
			count++;
		}
		while(count != width)
			game->map2D.s_layout[i][count++] = 0;
	}
	k = -1;
	if (flag == 1)
		while(++k != width)
			game->map2D.s_layout[height][k] = 0;
}

static void do_spaced_map_w(int height, int width, int flag, t_prog *game)
{
	int i;
	int k;
	int count;

	count = -1;
	while(++count != game->map2D.val)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = 0;
		if (flag == 1)
			game->map2D.s_layout[count][width] = 0;
	}
	i = -1;
	while (++i < game->map2D.height)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = game->map2D.layout[i][k];
		if (flag == 1)
			game->map2D.s_layout[count][width] = 0;
		count++;
	}
	while(count != height)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = 0;
		if (flag == 1)
			game->map2D.s_layout[count][width] = 0;
		count++;
	}
}

static void buildheight(t_prog *game, int height, int width)
{
	float	val;
	int		subti;
	int		flag;

	val = height - width;
	subti = width + (ceil(val/2) * 2);
	if ((int)ceil(val) % 2 == 0)
	{
		flag = 0;
		game->map2D.s_layout = allocate_all_layout(height, subti);
	}
	else
	{
		flag = 1;
		game->map2D.s_layout = allocate_all_layout(height + 1, subti);
	}
	game->map2D.val = (int)ceil(val/2);
	do_spaced_map_h(height, subti, flag, game);
	game->map2D.s_width = subti;
	if (flag == 0)
		game->map2D.s_height = height;
	else
		game->map2D.s_height = height + 1;
	game->pl.position[0] += game->map2D.val;
}

static void buildwidth(t_prog *game, int height, int width)
{
	float	val;
	int		subti;
	int		flag;

	val = width - height;
	subti = height + (ceil(val/2) * 2);
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
	game->map2D.val = (int)ceil(val/2);
	do_spaced_map_w(subti, width, flag, game);
	game->map2D.s_height = subti;
    if (flag == 0)
        game->map2D.s_width = width;
    else
    {
        game->map2D.s_width = width + 1;
    	game->pl.position[0] += 1;
    }
    game->pl.position[1] = (game->map2D.s_height - game->map2D.val - game->pl.position[1] - 1);
}

void	build_spaced_layout(t_prog *game, int height, int width)
{

	if (height > width)
		buildheight(game, height, width);
	else if (height < width)
		buildwidth(game, height, width);
	else
	{
		game->map2D.s_layout = copy_double_pointer(game->map2D.layout, game->map2D.height, game->map2D.width);
		game->map2D.s_height = game->map2D.height;
		game->map2D.s_width = game->map2D.width;
		game->pl.position[1] = game->map2D.s_height - game->pl.position[1] - 1;
	}
	print_smap(game->map2D.s_layout, game->map2D.s_height, game->map2D.s_width);
}
