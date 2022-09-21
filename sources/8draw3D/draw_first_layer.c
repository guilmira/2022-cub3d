/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_first_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:40:26 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/06 16:37:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Horizontal line in given coordinate. */
/*static void put_horizontal_line(double coordinate_y, double limit_x, int colour, t_prog *game)
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
}*/
/** PURPOSE : extend horizonal lines through the screen. */
/*static void draw_horizon(double origin[], int size, int colour, t_prog *game)
{
	int i;
	double coor_y;
	
	i = -1;
	while (++i < size)
	{
		coor_y = origin[1] + i;
		put_horizontal_line(coor_y, game->w1.size[0], colour, game);
	}
}*/


/*inputs percentage of the stripe desired and outputs the stripe in texture*/
mlx_texture_t *get_texture_stripe(mlx_texture_t *texture, int percentage, t_prog *game)
{
	mlx_texture_t	*ret;
	mlx_image_t		*aux;
	uint32_t		xy[2];
	uint32_t		hw[2];
	uint32_t		count;
	uint32_t 		pixel;

	pixel = (percentage * texture->width) / 100;
	if (pixel - 1 < 0)
		pixel = 1;
	xy[0] = pixel - 1;
	xy[1] = 0;
	hw[0] = 1;
	hw[1] = texture->height;
	printf("%d texture->width\n", texture->width);
	aux = mlx_texture_area_to_image(game->mlx, texture, xy, hw);
	ret = malloc(sizeof(mlx_texture_t));
	ret->width = aux->width;
	ret->height = aux->height;
	ret->bytes_per_pixel = 4;
	ret->pixels = malloc(sizeof(uint8_t) * hw[1] * 4);
	count = -1;
	while(++count < (hw[1] * 4))
		ret->pixels[count] = aux->pixels[count];
	mlx_delete_image(game->mlx, aux);
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
	colour_floor = rgb_t_translate(151, 151, 151, 255);
	colour_sky = rgb_t_translate(40, 40, 40, 255);
	sky_texture = mlx_load_png("textures/brick_normal.png");
	stripe = get_texture_stripe(sky_texture, 50, game);
	//draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);
	origin[1] = game->w1.size[1] / 2;
	mlx_draw_texture(game->image[CUB_3D], stripe, 100, 100);
	//draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	mlx_delete_texture(sky_texture);
	mlx_delete_texture(stripe);
}