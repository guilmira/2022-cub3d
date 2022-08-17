/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_framework.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:33:47 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/17 18:34:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Scale a 2D grid. */
static void	draw_grid(t_prog *game, double size_x, double size_y)
{
	int nb;
	int colour;


	colour = trgb_translate(255, 255, 255, GRID_TRANSPARENCY);
	nb = -1;
	while (++nb < game->map2D.height + 1)
		put_horizontal(( nb * game->map2D.pixel_per_block[1]), size_x, colour, game);
	nb = -1;
	while (++nb < game->map2D.width + 1)
		put_vertical(( nb * game->map2D.pixel_per_block[0]), size_y, colour, game);
}


/** PURPOSE : From map parser draw in minimap2D each wall. */
static void draw_wall_unit(double map_position[], int pixel_per_block[], t_prog *game)
{
	int				j;
	mlx_image_t		*image;
	double			line_end[2];
	double			line_start[2];
	double			base_location[2];


	image = game->image[MAP_2D];
	if (map_position[0] < 0 || map_position[1] < 0)
		return ;
	
	translate_to_screen(map_position, base_location, pixel_per_block, game);
	line_start[0] = base_location[0];
	line_start[1] = base_location[1];
	line_end[0] = line_start[0] + pixel_per_block[0];
	line_end[1] = line_start[1];


	j = -1;
	while (++j < pixel_per_block[1])
	{
		line_start[1] = base_location[1] + j;
		line_end[1] = line_start[1];
		if (!j)
			put_lineH(line_start, line_end, GREEN, game);
		else
			put_lineH(line_start, line_end, BLUE, game);
	}
	put_lineH(line_start, line_end, GREEN, game);
	put_lineV(line_start, pixel_per_block[1], GREEN, game);
	put_lineV(line_end, pixel_per_block[1], GREEN, game);
}

/** PURPOSE : Draw all the 2D wall to screen. */
void	draw_wall2D(t_prog *game)
{
	int i;
	int j;
	double map_position[2];

	i = -1;
	j = -1;
	while (++j < game->map2D.height)
	{
		while (++i < game->map2D.width)
		{
			if (game->map2D.layout[j][i] == 1)
			{
				map_position[0] = i;
				map_position[1] = j;
				draw_wall_unit(map_position, game->map2D.pixel_per_block, game);
			}
		}
		i = -1;
	}
}

/** PURPOSE : Draw 2D image as main render.
 * 1. Obtain parameters by defining image size.
 * 2. Draw grid.
 * 3. Draw player position + its field of vision. */
void	framework_2D(t_prog *game)
{
	if (!game->minimap_state)
		return ;
	/* --------------------------------------------------------------- */
	draw_grid(game, game->w2.size[0], game->w2.size[1]);	
	/* --------------------------------------------------------------- */
	/* double pos[2] = {1, 1};
	draw_wall_unit(pos, game->map2D.pixel_per_block, game); */
	draw_wall2D(game);
	draw_player_position(game->image[MAP_2D], game->pl.position_coor, game->pl.vis, game); 
	/* --------------------------------------------------------------- */
	mlx_image_to_window(game->mlx,\
	game->image[MAP_2D], game->w2.origin[0], game->w2.origin[1]);
	
}
