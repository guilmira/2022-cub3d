/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/22 17:09:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void centered_vertical(double x, int size, int colour, t_prog *game)
{
	int				i;
	int				y;
	int				counter;
	double			start[D2];	

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
#define CONSTANT 2000

#define MIN_DIST 1

static int get_wall_size(int distance, t_prog *game)
{
	int	ret;
	int	max_size;

	max_size = (game->w1.size[1] / 4) - SAFE_OFFSET;
	if (distance < MIN_DIST)
		return (max_size);
	ret = CONSTANT / distance;
	if (ret > max_size)
		return (max_size);
	else
		return (ret);
}

/** PURPOSE : check if the wall hits on OX axis or OY axis.
 * 2 OX axis (vertical vector that hits on an horizontal)
 * 1 OXY axis (horizontal vector that hits on a vertical) */
static int is_shadowed(int value)
{
	if (value == 2)
		return (1);
	else
		return (0);
}

/** PURPOSE : choose what shade to put on wall. */
static int choose_shadow_colour(int wall_value, int size, t_prog *game)
{
	int	colour_normal;
	int	colour_far;
	int	colour_shadowed;
	int	colour_far_shadowed;
	(void) size;
	(void) game;

	colour_normal = BLUE;
	colour_far = trgb_translate(0, 255, 0, 0);
	colour_shadowed = get_trgb_shadowed(colour_normal);
	colour_far_shadowed = get_trgb_shadowed(colour_far);

	if (is_shadowed(wall_value))
		return (colour_shadowed);
	else
		return (colour_normal);

/* 	if (is_shadowed(wall_value) && size < game->w1.size[1] / 3)
		return (colour_shadowed);
	else if (is_shadowed(wall_value))
		return (colour_far_shadowed);
	else if (size < game->w1.size[1] / 3)
		return (colour_far);
	else
		return (colour_normal); */
}


// de x te estas pasando
/** PURPOSE : draw*/
static void draw_wall_vertical_unit(int i, int wall_side, double distance, int wall_ox_width, t_prog *game)
{
	int	size;
	int	pixel_ox;
	int	wall_colour;
	int	pixel_ox_counter;
	
	pixel_ox_counter = -1;
	size = get_wall_size(distance, game);
	while (++pixel_ox_counter < wall_ox_width)
	{
		pixel_ox = (wall_ox_width * i) + pixel_ox_counter;
		wall_colour = choose_shadow_colour(wall_side, size, game );
		centered_vertical(pixel_ox, size, wall_colour, game);
	}
}


//3 shades of blue for deepth

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int	i;
	int screen_width;
	int wall_ox_width;
	
	screen_width = game->w1.size[0];
	wall_ox_width = screen_width / game->rc->number_of_rays;
	i = -1;
	while (++i < game->rc->number_of_rays + 1)
	{
		//printf("here %i\n", game->rc->number_of_rays);
		/* if (i == game->rc->number_of_rays / 2)
			draw_wall_vertical_unit(i, game->rc->rc_, game->rc->rc_distance[i], wall_ox_width, game); */
		//printf("%.2f ", game->rc->rc_distance[i]);
		draw_wall_vertical_unit(i, game->rc->rc_wall_side[i], game->rc->rc_distance[i], wall_ox_width, game);
	}
}