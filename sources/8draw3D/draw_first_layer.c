/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:40:26 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/13 12:20:33 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Horizontal line in given coordinate. */
static inline void	put_horizontal_line(double coordinate_y, \
double limit_x, int colour, t_prog *game)
{
	int			i;
	int			coor_y;
	mlx_image_t	*image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w1.size[1]);
	while (++i < limit_x)
		solid_pixel(image, i, coor_y, colour);
}

/** PURPOSE : extend horizonal lines through the screen. */
static inline void	draw_horizon(double origin[], \
int size, int colour, t_prog *game)
{
	int		i;
	double	coor_y;

	i = -1;
	while (++i < size)
	{
		coor_y = origin[1] + i;
		put_horizontal_line(coor_y, game->w1.size[0], colour, game);
	}
}

mlx_texture_t	*fill_stripe(mlx_texture_t *tex, \
	uint32_t stripeheight, double start[], uint32_t x)
{
	uint32_t		c;
	double			y;
	double			hw;
	mlx_texture_t	*ret;

	c = 0;
	y = start[0];
	hw = start[1];
	ret = malloc(sizeof(mlx_texture_t));
	ret->width = 1;
	ret->height = stripeheight;
	ret->bytes_per_pixel = 4;
	ret->pixels = malloc(sizeof(uint8_t) * (stripeheight * 4));
	while (c < (stripeheight * 4))
	{
		ret->pixels[c] = tex->pixels[x + (int)y * (tex->width * 4)];
		ret->pixels[c + 1] = tex->pixels[x + 1 + (int)y * (tex->width * 4)];
		ret->pixels[c + 2] = tex->pixels[x + 2 + (int)y * (tex->width * 4)];
		ret->pixels[c + 3] = tex->pixels[x + 3 + (int)y * (tex->width * 4)];
		c += 4;
		y += hw;
	}
	return (ret);
}

mlx_texture_t	*get_texture_stripe(mlx_texture_t *texture, \
int percentage, uint32_t stripeheight, t_prog *game)
{
	uint32_t		pixel;
	double			start[2];

	start[0] = 0;
	pixel = (percentage * texture->width) / 1000 * 4;
	start[1] = (double)texture->height / (double)stripeheight;
	if ((int)stripeheight > game->w1.size[1])
	{
		start[0] = (double)(((int)stripeheight - game->w1.size[1])
				* start[1] / 2);
		stripeheight = (uint32_t)game->w1.size[1];
	}
	return (fill_stripe(texture, stripeheight, start, pixel));
}

/** PURPOSE : floor layer + horizon sky. 
 * 1. game->w1.size[1] / 2 represents the middlepoint at OY. */
void	draw_first_layer(t_prog *game)
{
	int		colour_floor;
	int		colour_sky;
	double	origin[D2];

	origin[0] = 0;
	origin[1] = 0;
	colour_floor = game->floor_clr;
	colour_sky = game->sky_clr;
	draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	origin[1] = game->w1.size[1] / 2;
	draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);
}
