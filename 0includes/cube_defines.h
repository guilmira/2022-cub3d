/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/28 16:08:27 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_DEFINES_H
# define CUBE_DEFINES_H

/* ------------------------ MODIFIABLE DEFINES ------------------------ */
# define TITLE_WINDOW "CUBE"
/* 								WINDOW SIZE
					Standard size of window: 1920x1080p
 						Mac Screen: 2560 x 1440 						*/
# define OX_WINDOW 1920
# define OY_WINDOW 1080

/* 								 MAP INTITAL STATE
								0 - no minimap
								2 - minimap corner
								4 - full minimap 						*/
# define MINIMAP_INTIAL_STATE 4

# define MOVEMENT_PIXEL_UNIT 4 //velocity 
# define TRANCE_BOOST 10 //velocity 
/* Corner minimap DIMENSIONS */
# define OX_CORNER_WINDOW_FACTOR 6
# define OY_CORNER_WINDOW_FACTOR 6
# define OX_CORNER_WINDOW_DESPLACEMENT 6
# define OY_CORNER_WINDOW_DESPLACEMENT 6
 
/* Only round noumbers, preferable 10 */
# define OX_DIV 12
# define OY_DIV OX_DIV

/* Player ratio of (see code) */
# define PLAYER_RATIO 0.5

# define SAFE_OFFSET 0.0001
//# define RAYCAST_OFFSET 100 // pixels per aperture
# define RAYCAST_OFFSET 100
# define FOV_DEGREE 30
/* ------------------------ MODIFIABLE DEFINES FOR DEVS ------------------------ */
# define TOTAL_IMAGES 2
/* References to slots of images in image[TOTAL_IMAGES + 1];
CUB_3D for 3D and MAP_2D Minimap */
#define CUB_3D 0
#define MAP_2D 1
/* Safe margin not to burst the window limits. */
#define SAFE_MARGIN 30
/* ------------------------ BASE DEFINES ------------------------ */
/* Not meant to be modified. */
# define D2 2
# define MOVE_OPTIONS 8
/* ------------------------ ERROR MESSAGES ------------------------ */
# define EX		"Error.\n"
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
