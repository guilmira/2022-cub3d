/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:40:26 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/23 09:42:10 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Horizontal line in given coordinate. */
static inline void put_horizontal_line(double coordinate_y, double limit_x, int colour, t_prog *game)
{
	int i;
	int coor_y;
	mlx_image_t *image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w1.size[1]);
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}
/** PURPOSE : extend horizonal lines through the screen. */
static inline void draw_horizon(double origin[], int size, int colour, t_prog *game)
{
	int i;
	double coor_y;
	
	i = -1;
	while (++i < size)
	{
		coor_y = origin[1] + i;
		put_horizontal_line(coor_y, game->w1.size[0], colour, game);
	}
}

mlx_texture_t *get_texture_stripe(mlx_texture_t *texture, int percentage, uint32_t stripeheight)
{
	mlx_texture_t	*ret;
	uint32_t		x;
	double			y;
	double			hw;
	uint32_t		count;
	uint32_t 		pixel;

	pixel = (percentage * texture->width) / 1000 * 4;
	if (pixel - 1 < 0)
		pixel = 1;
	x = pixel;
	y = 0;
	hw = (double)texture->height / (double)stripeheight;
	ret = malloc(sizeof(mlx_texture_t));
	ret->width = 1;
	ret->height = stripeheight;
	ret->bytes_per_pixel = 4;
	ret->pixels = malloc(sizeof(uint8_t) * (stripeheight * 4));
	count = 0;
	while(count < (stripeheight * 4))
	{
		ret->pixels[count] = texture->pixels[x + (int)y * (texture->width * 4)];
		ret->pixels[count + 1] = texture->pixels[x + 1 + (int)y * (texture->width * 4)];
		ret->pixels[count + 2] = texture->pixels[x + 2 + (int)y * (texture->width * 4)];
		ret->pixels[count + 3] = texture->pixels[x + 3 + (int)y * (texture->width * 4)];
		count += 4;
		y += hw;
	}
	return(ret);
}

/** PURPOSE : floor layer + horizon sky. 
 * 1. game->w1.size[1] / 2 represents the middlepoint at OY. */
void	draw_first_layer(t_prog *game)
{
	int colour_floor;
	int colour_sky;
	mlx_texture_t *sky_texture;	
	mlx_texture_t *stripe;
	double origin[D2];

	origin[0] = 0;
	origin[1] = 0;
	colour_floor = game->floor_clr;
	colour_sky = game->sky_clr;
	sky_texture = mlx_load_png("textures/brick_normal.png");
	stripe = get_texture_stripe(sky_texture, 503, 500);
	draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);
	origin[1] = game->w1.size[1] / 2;
	//mlx_draw_texture(game->image[CUB_3D], stripe, 100, 100);
	draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	mlx_delete_texture(sky_texture);
	mlx_delete_texture(stripe);
}