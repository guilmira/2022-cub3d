/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_ray_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:41:08 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/01 13:15:48 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Defines coordinate  */
static void	get_stripe_coor(int stripe_coor[], int ray_number, \
int size, t_prog *game)
{
	int	mid_screen_oy;

	mid_screen_oy = game->w1.size[1] / 2;
	stripe_coor[0] = ray_number;
	stripe_coor[1] = mid_screen_oy - size / 2;
	if (stripe_coor[0] < 0)
		stripe_coor[0] = 0;
	if (stripe_coor[1] < 0)
		stripe_coor[1] = 0;
}

static double	get_collision_point(int ray_number, int wall_side, t_prog *game)
{
	t_vector	vector;
	double		player_coor[D2];

	player_coor[0] = game->rc->rc_origin_coor[0];
	player_coor[1] = game->rc->rc_origin_coor[1];
	vector = game->rc->rc_vector[ray_number];
	if (wall_side == 1)
		return (player_coor[1] + vector.y);
	else if (wall_side == 2)
		return (player_coor[0] + vector.x);
	else
		return (1);
}

/** PURPOSE : Stripe selector from 0 to 100
 * The stripe number will be calculated with this formula:
 *  - Xn : exact point where the ray hits the wall
 *  - Xo : begining of the wall
 * 	- Xtotal : the full lenght of the wall
 *  [(Xn - Xo) / Xtotal ] * 100 */
static int	get_wall_stripe(int ray_number, t_prog *game)
{
	int			stripe_number;
	double		collision_point;
	int			wall_side;

	stripe_number = 0;
	wall_side = game->rc->rc_wall_side[ray_number];
	collision_point = get_collision_point(ray_number, wall_side, game);
	if (wall_side == 1)
	{
		stripe_number = ((collision_point - \
		(game->rc->rc_wall_hit_y[ray_number] * game->map2D.pixel_per_block[1])) \
		/ game->map2D.pixel_per_block[1]) * 100;
	}
	if (wall_side == 2)
	{
		stripe_number = ((collision_point - \
		(game->rc->rc_wall_hit_x[ray_number] * game->map2D.pixel_per_block[0])) \
		/ game->map2D.pixel_per_block[0]) * 100;
	}
	if (stripe_number < 1)
		return (1);
	if (stripe_number > 99)
		return (99);
	return (stripe_number);
}

/** PURPOSE : draw a wall stripe by stripe, taken from a texture. */
void	draw_textured_wall(int wall_side, \
int ray_number, int size, t_prog *game)
{
	int				stripe_number;
	int				stripecoor[D2];
	mlx_texture_t	*stripe;
	mlx_texture_t	*texture;

	stripe_number = 0;
	stripe_number = get_wall_stripe(ray_number, game);
	get_stripe_coor(stripecoor, ray_number, size, game);
	texture = get_oriented_texture(wall_side, \
	game->rc->rc_vector[ray_number], game);
	stripe = get_texture_stripe(texture, stripe_number * 10, size, game);
	mlx_draw_texture(game->image[CUB_3D], stripe, stripecoor[0], stripecoor[1]);
	mlx_delete_texture(stripe);
}
