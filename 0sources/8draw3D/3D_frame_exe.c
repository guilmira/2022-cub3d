/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:48:19 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/21 21:24:30 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

#define CONSTANT 5000


void centered_vertical(double x, int size, int colour, t_prog *game)
{
	int				i;
	int				y;
	int				counter;
	double start[D2];	

	i = -1;
	counter = (int) size;

	start[0] = x;
	start[1] = game->w1.size[1] / 2;
	if (counter <= 0)
		return ;
	while (++i < counter)
	{
		y = (int) coor(start[1] - i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], \
		(int) (start[0]), y, colour);

		y = (int) coor(start[1] + i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], \
		(int) (start[0]), y, colour);
	}
}

int get_wall_size(int distance, t_prog *game)
{
	(void) game;
	return (CONSTANT / distance);
}


/* static void draw_horizon(double origin[], int size, int colour, t_prog *game)
{
	double start[D2];
	double end[D2];
	int i;

	i = -1;
	start[0] = origin[0];
	end[0] = (double) size - start[0];
	start[1] = origin[0] + i;
	end[1] = start[1];
	while (++i < game->w2.size[1] / 2)
	{
		start[1] = origin[0] + i;
		end[1] = start[1];
		put_lineH(start, end, colour, game);
	}
} */




/** PURPOSE : Horizontal line in given coordinate. */
static void put_horizontal1(double coordinate_y, double limit_x, int colour, t_prog *game)
{
	int i;
	int coor_y;
	mlx_image_t *image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w1.size[1]); //!!!ojo que aqui podria ser x
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}


static void draw_horizon(double origin[], int size, int colour, t_prog *game)
{
	int i;
	double coor_y;
	
	i = -1;
	while (++i < size)
	{
		coor_y = origin[1] + i;
		put_horizontal1(coor_y, game->w1.size[0], colour, game);
	}
}

/** PURPOSE : Raise 3D images.
 * 1. Build image.
 * 2. Put to window. */
void	put_frame3D(t_prog *game)
{
	int colour_floor;
	int colour_sky;
	double origin[D2];

	origin[0] = 0;
	origin[1] = 0;

	colour_floor = trgb_translate(120, 20, 20, 255);
	colour_sky = trgb_translate(0, 40, 40, 255);
	draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	origin[1] = game->w1.size[1] / 2;
	draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);

	int	i;
	i = -1;
	int screen_width;
	int wall_ox_unit;
	int pixel_ox_counter;
	int size;
	int pixel_ox;
	int shadowed;
	int colour_shadowed;
	int colour_normal;

	colour_normal = BLUE;
	colour_shadowed = trgb_translate(0, 0, 255, 120);

	shadowed = 0;
	pixel_ox_counter = -1;
	screen_width = game->w1.size[0];
	wall_ox_unit = screen_width / game->rc->number_of_rays;
	while (++i < game->rc->number_of_rays)
	{
		
		size = get_wall_size(game->rc->rc_distance[i], game);
		while (++pixel_ox_counter < wall_ox_unit)
		{
			if (game->rc->rc_wall_side[i] == 2)
				shadowed++;
			else
				shadowed = 0;
			pixel_ox = (wall_ox_unit * i) + pixel_ox_counter;
			if (shadowed)
				centered_vertical(pixel_ox, size, colour_normal, game);
			else
				centered_vertical(pixel_ox, size, colour_shadowed, game);

		}
		pixel_ox_counter = -1;

	}
}
