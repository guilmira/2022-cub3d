/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9tools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:33:17 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/01 17:33:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/** PURPOSE : Position corrector.
 * The -1 avoids seg fault at screen limit (0, 0). */
float coor(float y)
{
	return (OY_WINDOW - y - 1);
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

/** PURPOSE : Base times height */
void draw_rectangle(t_data *image, int x, int y, int base, int height)
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
			my_mlx_pixel_put(image, x + i, coor(y + j), trgb_translate(0, 0, 255, 0));
		i = -1;
	}
}

/** PURPOSE : Base times height */
void draw_centered_rectangle(t_data *image, int x, int y, int base, int height)
{
	int i;
	int j;

	x = x - base / 2;
	y = y - height / 2;
	if (x < 0 || y < 0)
		return ;
	i = -1;
	j = -1;
	while (++j < height)
	{
		while (++i < base)
			my_mlx_pixel_put(image, x + i, coor(y + j), trgb_translate(0, 0, 255, 0));
		i = -1;
	}
}


