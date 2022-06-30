/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3color_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/30 12:07:07 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

/* Since each byte contains 2^8 = 256 values (1 byte = 8 bits), 
and RGB values range from 0 to 255, 
we can perfectly fit a integer (as an int is 4 bytes).  */

/** PURPOSE : Translates values for each colour to a single integer.
 * Values given as a parameter can only go from 0 to 255 in all cases. 
 * 
 * It works as the following example for green
 *  0000 0011 (so i want 3 units of green out of 255.)
 * Since green is stored in the third byte, it has to become:
 * 0000 0000   0000 0000   0000 0011   0000 0000
 * So the offset is 8. */
int	trgb_translate(int t, int red, int green, int blue)
{
	int	result;

	result = 0;
	t = t << 24;
	red = red << 16;
	green = green << 8;
	return (result | t | red | green | blue);
}
/* Now, if we introduce trgb_translate(0, 255, 0, 0) 
looking for a pure red, i get
the value 16711680 which is 
equivalent to 0x00FF0000 */

int	get_transparent(int colour_code)
{
	return ((colour_code >> 24) & 0xFF000000);
}

int	get_red(int colour_code)
{
	return ((colour_code >> 24) & 0x00FF0000);
}

int	get_green(int colour_code)
{
	return ((colour_code >> 24) & 0x000FF00);
}

int	get_blue(int colour_code)
{
	return ((colour_code >> 24) & 0x000000FF);
}

int	get_opposite(int colour_code)
{
	return (trgb_translate( get_transparent(colour_code) \
	, (255 - get_red(colour_code)) , (255 - get_green(colour_code)), \
	(255 - get_blue(colour_code)) ) );
}
