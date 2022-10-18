/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_frame_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:25:41 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_2d_player(mlx_image_t *image, double pos[], \
	int colour, t_prog *game)
{
	double	i[2];
	double	radio;

	radio = game->pl.ratio;
	i[0] = -1 - radio;
	while (++i[0] < (radio * 2))
	{
		i[1] = -1 - radio;
		while (++i[1] < (radio * 2))
		{
			if (check_radio(i, radio))
			{
				solid_pixel(image, i[0] + pos[0], \
				coor(i[1] + pos[1], game->w2.size[1]), colour);
			}
		}
	}
}

/** PURPOSE : Draw player with its field of vision. 
 * 1. Requires player coordinates.
 * 2. From (x, y) coordinates, rays will be casted as vectors. */
void	draw_player_position(mlx_image_t *image, t_prog *game)
{
	double	position[D2];

	if (game->minimap_state != 2)
	{
		position[0] = game->pl.v_position_coor[0];
		position[1] = game->pl.v_position_coor[1];
	}
	else
	{
		update_player_location(game);
		position[0] = game->pl.position_coor[0];
		position[1] = game->pl.position_coor[1];
	}
	if (position[0] <= 0 || position[1] <= 0)
		ft_shutdown(EX, game);
	game->pl.ratio = (PLAYER_RATIO * game->map2d.pixel_per_block[0]);
	draw_2d_player(image, position, GREEN + RED, game);
	if (game->minimap_state == 4)
		draw_centered_rectangle(position, x_size, y_size, game);
	if (game->minimap_state == 2)
		draw_centered_rectangle(position, 1, 1, game);
}

/** PURPOSE : Draw vector on screen.
 * Assuming position of player as a coordinate (0, 0).
 * Therefore, vector can be represented by having a single 
 * point in space (Vx, Vy) 
 * 1. First, unit vector (vector unit is calulated). 
 * 2. As the unit of the grid is the pixel, to obtain the line:
 * (unit_Vector + unit_Vector) repeated n module times.  */
static void	draw_vector(t_vector vec, double origin[], \
uint32_t colour, t_prog *game)
{
	double		x_pixel;
	double		y_pixel;
	double		counter;
	t_vector	unit_vec;
	mlx_image_t	*image;

	image = game->image[CUB_3D];
	counter = get_module(vec);
	unit_vec = get_unit_vector(vec);
	x_pixel = origin[0] + unit_vec.x;
	y_pixel = origin[1] + unit_vec.y;
	while (--counter > 0)
	{	
		solid_pixel(image, (int) x_pixel, \
		(int) coor(y_pixel, game->w2.size[1]), colour);
		x_pixel += unit_vec.x;
		y_pixel += unit_vec.y;
	}
}

/** PURPOSE : Draws on the minimap the result of the raycast calculations. */
static inline void	draw_raycast(t_prog *game)
{
	int			i;
	t_vector	ray;
	int			colour;

	colour = rgb_t_translate(255, 150, 0, 255);
	i = -1;
	while (++i < game->rc->number_of_rays)
	{
		ray = game->rc->rc_vector[i];
		ray.y = ray.y - 1;
		draw_vector(ray, game->pl.position_coor, colour, game);
	}
	ray = game->rc->vision;
}

/** PURPOSE : 60 frames per second function. 
 * pl.flag_movement to zero deactivates drawing until further movement. */
void	put_frame_two_dim(t_prog *game)
{
	if (game->minimap_state)
	{
		wash_screen(game, game->image[CUB_3D], game->w2, BLACK);
		framework_two_dim(game);
		draw_raycast(game);
	}
}
