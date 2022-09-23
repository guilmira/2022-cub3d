/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/23 11:12:45 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : draw a vertical symetric line starting in the 
 * middle of the screen. */
static inline void centered_vertical(double x, int size, int colour, t_prog *game)
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

#define CONSTANT 800 //constant for a perpendicular distance
//#define CONSTANT 8000 //for a fisheye
#define MIN_DIST 1

static inline double get_height_constant(t_prog *game)
{
	double height;
	
	(void) game;
	height = CONSTANT;
	return (height);
}


/** PURPOSE : calculate wall height. */
static inline double get_wall_size(double distance, t_prog *game)
{
	double	ret;
	int		max_size;
	double	height;

	height = get_height_constant(game);
	max_size = (game->w1.size[1] / 2) - SAFE_OFFSET;
	if (distance < MIN_DIST)
		return (max_size);
	ret = height / distance;
	if (ret > max_size)
		return (max_size);
	else
		return (ret);
}



int get_wall_stripe(int ray_number, t_prog *game);


void get_stripe_coor(int stripe_coor[], int ray_number, int size, t_prog *game);


void draw_texture(mlx_texture_t *texture, int ray_number, int size, t_prog *game)
{
	mlx_texture_t *stripe;
	int stripe_number;
	int	stripe_coor[D2];
	
	stripe_number = 0;
	stripe_number = get_wall_stripe(ray_number, game);
	get_stripe_coor(stripe_coor, ray_number, size, game);

	
	/* int i;
	i = -1;
	stripe_number = i + 1; */

	printf("aqui %i\n", stripe_number);

	stripe = get_texture_stripe(texture, stripe_number * 10, size); //falta proteger esta funcion, muy necesario

	mlx_draw_texture(game->image[CUB_3D], stripe, stripe_coor[0], stripe_coor[1]);

	mlx_delete_texture(stripe);
}

/** PURPOSE : draw a vertical line of calculated size. */
static inline void draw_wall_vertical_unit(mlx_texture_t *texture, int ray_number, t_prog *game)
{
	int	size;
	int	wall_colour;
	int wall_side;
	double distance;

	wall_side = game->rc->rc_wall_side[ray_number];
	distance = game->rc->rc_distance[ray_number];
	
	size = get_wall_size(distance, game);
	wall_colour = choose_wall_shade(wall_side, size, game);
	//centered_vertical(ray_number, size, wall_colour, game);



	draw_texture(texture, ray_number, size, game);

	
}

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int	i;
	int ray_number;

	mlx_texture_t *texture;	
	texture = mlx_load_png("textures/brick_normal.png");
	i = -1;
	while (++i < game->rc->number_of_rays)
	{	
		ray_number = i;
		draw_wall_vertical_unit(texture, ray_number, game);
	}
	mlx_delete_texture(texture);
}