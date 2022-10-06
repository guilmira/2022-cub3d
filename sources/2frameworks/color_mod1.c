/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mod1.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/01 09:44:08 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	rgb_t_translate(int red, int green, int blue, int transparency)
{
	int	result;

	result = 0;
	red = red << 24;
	green = green << 16;
	blue = blue << 8;
	return (result | red | green | blue | transparency);
}

int	get_rgb_shadowed(int colour_code)
{
	int	red;
	int	green;
	int	blue;
	int	shadowed_transparency;

	red = get_red(colour_code);
	green = get_green(colour_code);
	blue = get_blue(colour_code);
	shadowed_transparency = SHADOWED_TRANSPARENCY;
	return (rgb_t_translate(red, green, blue,
			SHADOWED_TRANSPARENCY));
}
