/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/10 17:40:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : draw a vertical symetric line starting in the 
 * middle of the screen. */
static void centered_vertical(double x, int size, int colour, t_prog *game)
{
	int		i;
	int		y;
	int		counter;
	double	start[D2];	

	i = -1;
	counter = size;
	start[0] = x;
	start[1] = game->w1.size[1] / 2;
	if (counter <= 0)
		return ;
	while (++i < counter)
	{
		y = (int) coor(start[1] - i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], (int) (start[0]), y, colour);
		y = (int) coor(start[1] + i, game->w1.size[1]);
		solid_pixel(game->image[CUB_3D], (int) (start[0]), y, colour);
	}
}

#define CONSTANT 1200 //constant for a perpendicular distance
//#define CONSTANT 8000 //for a fisheye
#define MIN_DIST 1

static double get_height_constant(t_prog *game)
{
	double height;
	
	(void) game;
	height = CONSTANT;
	return (height);
}


/** PURPOSE : calculate wall height. */
static double get_wall_size(double distance, t_prog *game)
{
	double	ret;
	int		max_size;
	double	height;

	height = get_height_constant(game);
	max_size = (game->w1.size[1] / 4) - SAFE_OFFSET;
	if (distance < MIN_DIST)
		return (max_size);
	ret = height / distance;
	ret = (int) ret;
	if (ret > max_size)
		return (max_size);
	else
		return (ret);
}

/** PURPOSE : Stripe selector from 0 to 100. */
int get_wall_stripe(int ray_number, t_prog *game)
{
	t_vector vector;
	double player_coor[D2];
	int wall_side;
	int stripe;
	double collision_point;
	double wall_init;


	stripe = 0;

	vector = game->rc->rc_vector[ray_number];
	wall_side = game->rc->rc_wall_side[ray_number];
	player_coor[0] = game->rc->rc_origin_coor[0];
	player_coor[1] = game->rc->rc_origin_coor[1];
	if (wall_side == 1)
	{
		collision_point = player_coor[1] + vector.y;
		wall_init = game->rc->rc_wall_hit_y[ray_number] + 1 * game->map2D.pixel_per_block[1];
		stripe = ((collision_point - wall_init) * 100) / game->map2D.pixel_per_block[1];

	}
	if (wall_side == 2)
	{
		printf("vector %f\n", vector.x);
		collision_point = player_coor[0] + vector.x;
		wall_init = (game->rc->rc_wall_hit_x[ray_number] + 1) * game->map2D.pixel_per_block[0];
		printf("aqui %f y %i y %f y %d\n ", collision_point, game->rc->rc_wall_hit_x[ray_number] ,wall_init, game->map2D.pixel_per_block[0]);
		stripe = ((collision_point - wall_init) * 100) / game->map2D.pixel_per_block[0];

	}
	return (stripe);

}

/** PURPOSE : draw a vertical line of calculated size. */
static void draw_wall_vertical_unit(int ray_number, t_prog *game)
{
	int	size;
	int	wall_colour;
	int wall_side;
	double distance;

	wall_side = game->rc->rc_wall_side[ray_number];
	distance = game->rc->rc_distance[ray_number];
	
	size = get_wall_size(distance, game);
	wall_colour = choose_wall_shade(wall_side, size, game);
	centered_vertical(ray_number, size, wall_colour, game);

	//printf("%i\n", get_wall_stripe(ray_number, game));
	//get_wall_stripe(ray_number, game);
}

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int	i;
	int ray_number;

	i = -1;
	while (++i < game->rc->number_of_rays)
	{	
		ray_number = i;
		draw_wall_vertical_unit(ray_number, game);
	}
}