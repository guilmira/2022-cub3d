/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_ray_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:41:08 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/27 13:15:26 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Defines coordinate  */
static void get_stripe_coor(int stripe_coor[], int ray_number, int size, t_prog *game)
{
	int mid_screen_oy;

	mid_screen_oy = game->w1.size[1] / 2;
	stripe_coor[0] = ray_number;
	stripe_coor[1] = mid_screen_oy - size / 2;
	if (stripe_coor[0] < 0)
		stripe_coor[0] = 0;
	if (stripe_coor[1] < 0)
		stripe_coor[1] = 0;
}


/** PURPOSE : Stripe selector from 0 to 100. */
static int get_wall_stripe(int ray_number, t_prog *game)
{
	int         stripe_number;
	t_vector    vector;

	double		player_coor[D2];
	int			wall_side;
	double		collision_point;
	double		wall_init;

	stripe_number = 0;
	vector = game->rc->rc_vector[ray_number];
	wall_side = game->rc->rc_wall_side[ray_number];

	player_coor[0] = game->rc->rc_origin_coor[0];
	player_coor[1] = game->rc->rc_origin_coor[1];

	if (wall_side == 1)
	{
		collision_point = player_coor[1] + vector.y;
		wall_init = game->rc->rc_wall_hit_y[ray_number] * game->map2D.pixel_per_block[1];
		stripe_number = ((collision_point - wall_init) * 100) / game->map2D.pixel_per_block[1];

	}
	if (wall_side == 2)
	{
		collision_point = player_coor[0] + vector.x;
		wall_init = (game->rc->rc_wall_hit_x[ray_number]) * game->map2D.pixel_per_block[0];
		stripe_number = ((collision_point - wall_init) * 100) / game->map2D.pixel_per_block[0];
	}

	if (stripe_number < 1) //esto super peligroso, puede dar un efecto optico nefasto.
		return (1);
	if (stripe_number > 99) //esto super peligroso, puede dar un efecto optico nefasto.
		return (99);
	return (stripe_number);

}

void draw_texture_stripe(mlx_texture_t *texture, int ray_number, int size, t_prog *game)
{
	mlx_texture_t *stripe;
	int stripe_number;
	int	stripe_coor[D2];
	
	stripe_number = 0;
	stripe_number = get_wall_stripe(ray_number, game);
	get_stripe_coor(stripe_coor, ray_number, size, game);
	stripe = get_texture_stripe(texture, stripe_number * 10, size); //falta proteger esta funcion, muy necesario
	mlx_draw_texture(game->image[CUB_3D], stripe, stripe_coor[0], stripe_coor[1]);
	mlx_delete_texture(stripe);
}