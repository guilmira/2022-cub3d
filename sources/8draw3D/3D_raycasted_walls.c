/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_raycasted_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:49:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/23 14:03:19 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//por que son static inline??

void draw_texture(mlx_texture_t *texture, int ray_number, int size, t_prog *game);
void centered_vertical(double x, int size, int colour, t_prog *game);
double get_wall_size(double distance, t_prog *game);


void draw_texture_stripe(mlx_texture_t *texture, int ray_number, int size, t_prog *game);


/** PURPOSE : draw a vertical line of calculated size. */
static inline void draw_wall_vertical_unit(mlx_texture_t *texture, int ray_number, t_prog *game)
{
	int		size;
	int		wall_colour;
	int		wall_side;
	double	distance;

	wall_side = game->rc->rc_wall_side[ray_number];
	distance = game->rc->rc_distance[ray_number];
	size = get_wall_size(distance, game);
	wall_colour = choose_wall_shade(wall_side, size, game);
	centered_vertical(ray_number, size, wall_colour, game);
	draw_texture_stripe(texture, ray_number, size * 2, game);
}

#define WALL_IMAGE "textures/d64van-sky1pal.png"

/** PURPOSE : walls are represented adding vertical lines of different
 * lenght depending on distance to player.*/
void	draw_3D_walls(t_prog *game)
{
	int				i;
	mlx_texture_t	*texture;
	char wall_image_file[] = WALL_IMAGE;

	texture = mlx_load_png(wall_image_file);
	i = -1;
	while (++i < game->rc->number_of_rays)
		draw_wall_vertical_unit(texture, i, game);
	mlx_delete_texture(texture);
}