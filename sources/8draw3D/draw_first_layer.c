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
static void put_horizontal_line(double coordinate_y, double limit_x, int colour, t_prog *game)
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

/*static void horizontal_line_mat(double coordinate_y, int limit_x, mlx_texture_t *sky_texture, t_prog *game)
{
	int i;
	int colour;
	int rgb[4];
	int coor_y;
	int j;
	mlx_image_t *image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w1.size[1]);
	while (++i < limit_x && i < (game->w1.size[1] * 8))
	{
		j = i + coordinate_y * sky_texture->width;
		rgb[0] = get_red(sky_texture->pixels[j]);
		rgb[1] = get_blue(sky_texture->pixels[j]);
		rgb[2] = get_green(sky_texture->pixels[j]);
		rgb[3] = get_transparent(sky_texture->pixels[j]);
		colour = rgb_t_translate(rgb[0], rgb[1], rgb[2], rgb[3]);
		//printf("%hhu\n", sky_texture->pixels[j]);
		solid_pixel(image, i, coor_y, colour);
	}
}
*/
/** PURPOSE : extend horizonal lines through the screen. */
static void draw_horizon(double origin[], int size, int colour, t_prog *game)
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

/*static void draw_sf_mat(double origin[], uint32_t size, mlx_texture_t *sky_texture, t_prog *game)
{
	int i;
	double coor_y;
	
	i = -1;
	while (++i < (int)size)
	{
		coor_y = origin[1] + i;
		horizontal_line_mat(coor_y, (int)(sky_texture->width * 8), sky_texture, game);
	}
}*/

/** PURPOSE : floor layer + horizon sky. 
 * 1. game->w1.size[1] / 2 represents the middlepoint at OY. */
void	draw_first_layer(t_prog *game)
{
	int colour_floor;
	int colour_sky;
	mlx_texture_t *sky_texture;	
	double origin[D2];

	origin[0] = 0;
	origin[1] = 0;
	colour_floor = rgb_t_translate(151, 151, 151, 255);
	colour_sky = rgb_t_translate(40, 40, 40, 255);
	sky_texture = mlx_load_png("textures/brick_normal.png");
	draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);
	origin[1] = 300;
	//draw_sf_mat(origin, sky_texture->height, sky_texture, game);
	origin[1] = game->w1.size[1] / 2;
	mlx_draw_texture(game->image[CUB_3D], sky_texture, 1, game->w1.size[1]/2);
	draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	mlx_delete_texture(sky_texture);
}