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

/*static void horizontal_line_mat(double coordinate_y, int limit_x, uint8_t *colour, t_prog *game)
{
	int i;
	int coor_y;
	mlx_image_t *image;

	image = game->image[CUB_3D];
	i = -1;
	if (coordinate_y == 0)
		coordinate_y += SAFE_OFFSET;
	coor_y = (int) coor(coordinate_y, game->w1.size[1]);
	while (++i < limit_x && i < game->w1.size[1])
		mlx_put_pixel(image, i, coor_y, (uint32_t)colour);
}*/

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
/*
static void draw_sf_mat(double origin[], uint32_t size, uint8_t **sky_mat, t_prog *game)
{
	int i;
	int x;
	double coor_y;
	
	i = -1;
	while (++i < (int)size)
	{
		x = -1;
		coor_y = origin[1] + i;
		while(sky_mat[++x]);
		horizontal_line_mat(coor_y, x, sky_mat[i], game);
	}
}*/

/*static uint8_t  **texture_to_mat(mlx_texture_t*	texture)
{
	uint8_t  **mat;
	uint32_t y;
	uint32_t x;
	uint32_t j;

	y = 0;
	j = 0;
	mat = ft_calloc(sizeof(uint8_t *), texture->height * 8);
	if (!mat)
		return (NULL);
	printf("paso\n");
	while (y < texture->height)
	{
		x = 0;
		mat[y] = malloc(sizeof(uint8_t) * texture->width * 8);
		while (x < texture->width)
		{
			printf("entro\n");
			printf("%hhu\n", texture->pixels[j]);
			mat[y][x] = texture->pixels[j];
			printf("%hhu\n", mat[y][x]);
			j++;
			x++;
		}
		y++;
	}
	return (mat);
}
*/
/** PURPOSE : floor layer + horizon sky. 
 * 1. game->w1.size[1] / 2 represents the middlepoint at OY. */
void	draw_first_layer(t_prog *game)
{
	int colour_floor;
	int colour_sky;
	//mlx_texture_t *sky_texture;
	//uint8_t	**sky_mat;
	
	double origin[D2];

	origin[0] = 0;
	origin[1] = 0;
	//sky_mat = NULL;
	colour_floor = rgb_t_translate(151, 151, 151, 255);
	colour_sky = rgb_t_translate(40, 40, 40, 255);
	//sky_texture = mlx_load_png("textures/d64van-sky1pal.png");
	//sky_mat = texture_to_mat(sky_texture);
	//mlx_draw_texture(game->image[0], sky_texture, 0, 0);
	draw_horizon(origin, game->w1.size[0] / 2, colour_sky, game);
	origin[1] = game->w1.size[1] / 2;
	//draw_sf_mat(origin, sky_texture->height, sky_mat, game);
	draw_horizon(origin, game->w1.size[0] / 2, colour_floor, game);
	//clear_uint8(sky_mat, sky_texture->height);
	//mlx_delete_texture(sky_texture);
}