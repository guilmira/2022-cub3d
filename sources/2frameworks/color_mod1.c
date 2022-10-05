/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mod1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/01 09:44:08 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

//                                              FILE DOCUMENTATION RED-BLUE-GREEN
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

int     rgb_t_translate(int red, int green, int blue, int transparency)
{
        int     result;

        result = 0;
        red = red << 24;
        green = green << 16;
        blue = blue << 8;
        return (result | red | green | blue | transparency);
}

int get_rgb_shadowed(int colour_code)
{
        int     red;
        int     green;
        int     blue;
        int     shadowed_transparency;

        red = get_red(colour_code);
        green = get_green(colour_code);
        blue = get_blue(colour_code);
        shadowed_transparency = SHADOWED_TRANSPARENCY;
        return (rgb_t_translate(red, green, blue, SHADOWED_TRANSPARENCY));
}
