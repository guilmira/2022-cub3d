/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/27 15:13:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void draw_texture(mlx_texture_t *texture, int ray_number, int size, t_prog *game);
void centered_vertical(double x, int size, int colour, t_prog *game);
double get_wall_size(double distance, t_prog *game);


void draw_texture_stripe(mlx_texture_t *texture, int ray_number, int size, t_prog *game);

/** PURPOSE : get direction that the wall is facing. (ray hits on opposite side).
 * To be clear , it goes clockwise. 1 ray hits nort, 2 ray hits east, and so on.
 * 1 - NO
 * 2 - EA
 * 3 - SO
 * 4 - WE */
int get_wall_orientation(int wall_side, t_vector direction, t_prog *game)
{
	(void) game;
	if (wall_side == 2)
	{
		if (direction.y > 0)
			return (1);
		else
			return (3);
	}
	else
	{
		if (direction.x > 0)
			return (2);
		else
			return (4);
	}
}

mlx_texture_t *get_oriented_texture(int wall_side, t_vector direction, t_prog *game)
{
	int		wall_orientation;

	wall_orientation = get_wall_orientation(wall_side, direction, game);
	if (wall_orientation == 1)
		return (game->t_NO);
	if (wall_orientation == 2)
		return (game->t_EA);
	if (wall_orientation == 3)
		return (game->t_SO);
	if (wall_orientation == 4)
		return (game->t_WE);
	return (game->t_NO);
}

/** PURPOSE : draw a vertical line of calculated size. */
static inline void draw_wall_vertical_unit(int ray_number, t_prog *game)
{
	int		size;
	int		wall_colour;
	int		wall_side;
	double	distance;

	mlx_texture_t *oriented_texture;

	wall_side = game->rc->rc_wall_side[ray_number];
	distance = game->rc->rc_distance[ray_number];
	oriented_texture = get_oriented_texture(wall_side, game->rc->rc_vector[ray_number], game);
	size = get_wall_size(distance, game);
	wall_colour = choose_wall_shade(wall_side, size, game);
	centered_vertical(ray_number, size, wall_colour, game);
	draw_texture_stripe(oriented_texture, ray_number, size * 2, game);
}

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < game->rc->number_of_rays)
		draw_wall_vertical_unit(i, game);

}