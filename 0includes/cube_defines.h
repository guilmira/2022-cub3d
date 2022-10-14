/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 16:48:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_DEFINES_H
# define CUBE_DEFINES_H

/* ------------------------ VISUAL MODIFIABLE DEFINES --------------------- */
# define TITLE_WINDOW "CUBE"
/* 								WINDOW SIZE
					Standard size of window: 1920x1080p
 						Mac Screen: 2560 x 1440 						*/
# define OX_WINDOW 1860
# define OY_WINDOW 1040
/* Minimap size ratio */
# define MINIMAP_WINDOW_RATIO 5

/* 								 MAP INTITAL STATE
				0 - no minimap
2 - minimap corner         4 - full minimap 						*/
# define MINIMAP_INTIAL_STATE 4
# define FULL_MINIMAP 4

/* Window boundry condition. */
# define WINDOW_LOWER_LIMIT 1000
# define WINDOW_UPPER_LIMIT 2500

/* ------------------------ VISUAL ARTWORK DEFINES ------------------------ */
# define SHADOWED_TRANSPARENCY 120
/* ------------------------ OTHER MODIFIABLE DEFINES ---------------------- */
/* Wall size */
# define CONSTANT_HEIGHT_WALL 1600

# define PLAYER_RATIO 0.25
# define VISUAL_BLOCKS_W 10
# define VISUAL_BLOCKS_H 10

/* Player related. */
# define PLAYER_SPEED 700
# define TRANCE_BOOST 10
# define WIND_MODE 1.5
# define VISION_ANGLE_ROTATION 2

# define SAFE_OFFSET 0.0001
# define FOV_DEGREE 30

/* Activates messages showing rendering inefficiencies. */
# define GRAPHIC_ENGINE_REPORT 0
/* ------------------------ MODIFIABLE DEFINES FOR DEVS --------------------- */
/* Raycast related. */
# define VISION_RAY 1

/* Corner minimap DIMENSIONS */
# define SPACES_AT_BORDER 2

/* Safe margin not to burst the window limits. */
# define SAFE_MARGIN 0.01

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
# define EX0	"Error.\nDefines not according to standard. \
Check file cube_defines.h\n"
# define EX1	"Error.\nNo memory available for allocation.\n"
# define EX3	"Error.\nCould not generate image.\n"
/* ------------------------ STANDARD DEFINES ------------------------ */
/* COLOURS */
# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define YELLOW 0xFFBB2DFF
/* MESSAGE COLOURS */
# define C_RED		"\033[0;31m"
# define C_YELLOW	"\033[0;33m"
# define C_BLUE		"\033[0;34m"
# define C_WHITE	"\033[0;37m"
# define C_NONE		"\033[0m"
/* MESSAGES */
# define EXECUTION	"\nWelcome to the nightwing boyz cube.\nFrames in execution\n"
# define INSTR	"\n--------Instructions of use------------\n"
# define MOVE	C_YELLOW	"Movement keys		-	W A S D\n"C_NONE
# define VISION	C_BLUE		"Vision control		-	Arrows\n"C_NONE
# define MINI	C_YELLOW	"Minimap trigger		-	Tab\n"C_NONE
# define FOV	C_BLUE		"Altered reality		-	V\n"C_NONE
# define WIND	C_RED		"Wind mode🗡		-	F\n"C_NONE
# define ESC	C_WHITE		"Close program		-	ESC\n"C_NONE
# define CLOSE	"---------------------------------------\n\n"
/* README */
# define READ	"README.md"
#endif
