/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/15 11:50:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : general function to init variables. */
void update_pixel_per_block(t_prog *game)
{
	game->map2D.pixel_per_block[0] = game->w2.size[0] / game->map2D.width;
	game->map2D.pixel_per_block[1] = game->w2.size[1] / game->map2D.height;
}

static void fill_vis(t_prog *game, char dir)
{
	if(dir == 'N')
	{
		game->pl.vis.x = 0;
		game->pl.vis.y = 1;
	}
	else if(dir == 'S')
	{
		game->pl.vis.x = 0;
		game->pl.vis.y = -1;
	}
	else if(dir == 'E')
	{
		game->pl.vis.x = 1;
		game->pl.vis.y = 0;
	}
	else if(dir == 'W')
	{
		game->pl.vis.x = -1;
		game->pl.vis.y = 0;
	}
}

/** PURPOSE : Define intial location of player position in pixel screen. */
static void	update_player_position(int j, int i, t_prog *game)
{
	game->pl.position[0] = i;
	game->pl.position[1] = game->map2D.height - j - 1;

	game->pl.position_coor[0] = game->pl.position[0] * (double) game->map2D.pixel_per_block[0] + ( (double) game->map2D.pixel_per_block[0] / 2);
	game->pl.position_coor[1] = game->pl.position[1] * (double) game->map2D.pixel_per_block[1] + ( (double) game->map2D.pixel_per_block[1] / 2);
}

/** PURPOSE : Work with array [j][i] as a cartesian system. */
int shift_array(int y, int height)
{
	return ((height - 1) - y);
}

/** PURPOSE : Allocate all memory for 2D array. */
static int **allocate_all_layout(int height, int width)
{
	int j;
	int	**layout;
	
	j = -1;
	layout = ft_calloc(height, sizeof(int *));
	while (++j < height)
		layout[j] = ft_calloc(width, sizeof(int));
	return (layout);
}


static void do_spaced_map_h(int height, int width, int val, t_prog *game)
{
	int i;
	int k;
	int count;

	i = -1;
	while(++i < height)
	{
		k = -1;
		count = -1;
		while(++count != val)
			game->map2D.s_layout[i][count] = 0;
		while(++k < game->map2D.width)
		{
			game->map2D.s_layout[i][count] = game->map2D.layout[i][k];
			count++;
		}
		while(count != width)
		{
			game->map2D.s_layout[i][count] = 0;
			count++;
		}
	}
	k = -1;
	if (height % 2 != 0)
		while(++k != width)
			game->map2D.s_layout[height + 1][k] = 0;
}

static void do_spaced_map_w(int height, int width, int val, t_prog *game)
{
	int i;
	int k;
	int count;
	int flag;

	count = -1;
	if (width % 2 != 0)
		flag = 1;
	while(++count != val)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = 0;
		if (flag == 1)
			game->map2D.s_layout[count][k + 1] = 0;
	}
	i = -1;
	while (++i < game->map2D.height)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = game->map2D.layout[i][k];
		if (flag == 1)
			game->map2D.s_layout[count][k + 1] = 0;
		count++;
	}
	while(count != height)
	{
		k = -1;
		while (++k < width)
			game->map2D.s_layout[count][k] = 0;
		if (flag == 1)
			game->map2D.s_layout[count][k + 1] = 0;
		count++;
	}
}

static void	build_spaced_layout(t_prog *game, int height, int width)
{
	float val;
	int subti;

	if (height > width)
	{
		val = height - width;
		subti = width + (ceil(val/2) * 2);
		if (height % 2 == 0)
			game->map2D.s_layout = allocate_all_layout(height, subti);
		else
			game->map2D.s_layout = allocate_all_layout(height + 1, subti);
		do_spaced_map_h(height, subti, (int)ceil(val/2), game);
	}	
	else if(height < width)
	{
		val = width - height;
		subti = height + (ceil(val/2) * 2);
		if (width % 2 == 0)
			game->map2D.s_layout = allocate_all_layout(subti, width);
		else
			game->map2D.s_layout = allocate_all_layout(subti, width + 1);
		do_spaced_map_w(subti, width, (int)ceil(val/2), game);
	}
	else
		game->map2D.s_layout = game->map2D.layout;
}
/** PURPOSE : Translate parser map into a wall map. */
void init_map2D(char **map, t_prog *game)
{
	int	j;
	int	i;
	int	**layout;
	int	height;
	
	j = -1;
	i = -1;
	layout = NULL;
	height = game->map2D.height;
	/* --------------------------------------------------------------- */
	layout = allocate_all_layout(height, game->map2D.width);
	while (++j < height)
	{
		while (++i < game->map2D.width)
		{
			if (map[j][i] == '1')
				layout[shift_array(j, height)][i] = 1;
			else if (map[j][i] == '0' || map[j][i] == ' ')
				layout[shift_array(j, height)][i] = 0;
			else
			{
				update_player_position(j, i, game);
				fill_vis(game, game->map2D.map[j][i]);
			}

		}
		i = -1;
	}
	game->map2D.layout = layout;
	build_spaced_layout(game, game->map2D.height, game->map2D.width);
	print_map(map, game, layout);
	update_pixel_per_block(game);
}