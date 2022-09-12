/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/08 14:33:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_DEFINES_H
# define CUBE_DEFINES_H

/* ------------------------ VISUAL MODIFIABLE DEFINES ------------------------ */
# define TITLE_WINDOW "CUBE"
/* 								WINDOW SIZE
					Standard size of window: 1920x1080p
 						Mac Screen: 2560 x 1440 						*/
# define OX_WINDOW 1200
# define OY_WINDOW 1200
/* Minimap size ratio */
# define MINIMAP_WINDOW_RATIO 2

/* 								 MAP INTITAL STATE
				0 - no minimap
2 - minimap corner         4 - full minimap 						*/
# define MINIMAP_INTIAL_STATE 4
# define FULL_MINIMAP 4

/* ------------------------ VISUAL ARTWORK DEFINES ------------------------ */
#define SHADOWED_TRANSPARENCY 120
/* ------------------------ OTHER MODIFIABLE DEFINES ------------------------ */


# define PLAYER_RATIO 0.25
# define VISUAL_BLOCKS_W 10
# define VISUAL_BLOCKS_H 10

/* Player related. */
# define PLAYER_SPEED 500
# define TRANCE_BOOST 10
# define WIND_MODE 8
# define VISION_ANGLE_ROTATION 2


# define SAFE_OFFSET 0.0001
# define FOV_DEGREE 30
/* ------------------------ MODIFIABLE DEFINES FOR DEVS ------------------------ */



/* Raycast related. */
#define VISION_RAY 1

/* Corner minimap DIMENSIONS */
# define SPACES_AT_BORDER 2


/* Safe margin not to burst the window limits. */
# define SAFE_MARGIN 0.1

/* Safe margin not to wash the window limits. */
# define WASH_SIZE_OFFSET 1

/* From full at 0, to none at 255 */
# define GRID_TRANSPARENCY 15

/* From abort_crapping constant nbr that makes correction */
# define CORRECTION_PIXEL_NBR 0.5
/* ------------------------ BASE DEFINES ------------------------ */
/* Not meant to be modified. */
# define D2 2
# define TOTAL_IMAGES 1
# define CUB_3D 0
/* ------------------------ ERROR MESSAGES ------------------------ */
# define EX		"Error.\n"
# define EX0	"Error.\nDefines not according to standard. Check file cube_defines.h\n"
# define EX1	"Error.\nNo memory available for allocation.\n"
# define EX3	"Error.\nCould not generate image.\n"
/* ------------------------ STANDARD DEFINES ------------------------ */
/* COLOURS */
# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF

#endif
