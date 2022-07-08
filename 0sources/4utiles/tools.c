/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:33:17 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/07 15:05:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Position corrector.
 * The -1 avoids seg fault at screen limit (0, 0). */
double coor(double y, double size_y)
{
	if (y < 0 || size_y - y < 0)
	{
		ft_senderror("Invalid 'y' coordinate.\n");
		return (0);
	}
	return (size_y - y - 1);
}

/** PURPOSE :  Converter.
 * 1. 180 º = π rad */
float degree_to_radian(float degree)
{
	return (degree * (float) M_PI / 180);
}

/** PURPOSE : Explicit ecuation of a line.
 *  y = m * x + n . */
float ft_line(float slope, float x, float ordinate)
{
	return (slope * x + ordinate);
}

/** PURPOSE : Base times height.
 * Its starting point will be the lefmost inferior corner. */
void draw_rectangle(mlx_image_t *image, int x, int y, int base, int height)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (x < 0 || y < 0)
		return ;
	while (++j < height)
	{
		while (++i < base)
			mlx_put_pixel(image, x + i, coor(y + j, OY_MINIMAP), BLUE);
		i = -1;
	}
}

/** PURPOSE : Base times height.
 * 1. Requires dimensions and position of origin. */
void draw_centered_rectangle(mlx_image_t *image, int x, int y, int base, int height)
{
	int i;
	int j;

	if (x < 0 || y < 0)
		return ;
	i = -1;
	j = -1;
	y = y - height / 2;
	x = x - base / 2;
	while (++j < height)
	{
		while (++i < base)
			mlx_put_pixel(image, x + i, coor(y + j, OY_MINIMAP), GREEN);
		i = -1;
	}
}


