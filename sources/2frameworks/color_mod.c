/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/01 09:44:08 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//						FILE DOCUMENTATION RED-BLUE-GREEN
/* Since each byte contains 2^8 = 256 values (1 byte = 8 bits), 
and RBG values range from 0 to 255, 
we can perfectly fit a integer (as an int is 4 bytes).  */

//Trnsparency : 0 = ALL. 255 = NONE

/** PURPOSE : Translates values for each colour to a single integer.
 * Values given as a parameter can only go from 0 to 255 in all cases. 
 * 
 * It works as the following example for blue
 *  0000 0011 (so i want 3 units of blue out of 255.)
 * Since blue is stored in the third byte, it has to become:
 * 0000 0000   0000 0000   0000 0011   0000 0000
 * 1011 1111 
 * 1011 
 * So the offset is 8. */
int	get_red(int colour_code)
{
	return ((colour_code & 0xFF000000) >> 24);
}

int	get_green(int colour_code)
{
	return ((colour_code & 0x00FF0000) >> 16);
}

int	get_blue(int colour_code)
{
	return ((colour_code & 0x0000FF00) >> 8);
}

int	get_transparent(int colour_code)
{
	return (colour_code & 0x0000FF);
}

int	get_opposite(int colour_code)
{
	return (rgb_t_translate(\
	(255 - get_red(colour_code)), \
	(255 - get_green(colour_code)), \
	(255 - get_blue(colour_code)), \
	get_transparent(colour_code)));
}

