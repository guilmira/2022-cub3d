/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/29 19:02:06 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/* ------------------------ INCLUDES ------------------------ */
/* LIBS */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

/* LIBFT */
# include "../libft_submodule/0includes/libft.h"
//-lm man man 3 math ALL functions allowed

/* ------------------------ DEFINES ------------------------ */
/* WINDOW SIZE */
//size of window: 1920x1080p
/* MAXIMUN WINDOW SIZE ALLOWED - Mac Screen: 2560 x 1440 */
#define OX_WINDOW 1920
#define OY_WINDOW 1080
#define TITLE_WINDOW "CUBE"

/* COLOURS */
/* It follows the TRGB format. 
Binary 0000 0000 		1111 1111
Hexa  0x00			0x  F 	 F
Decimal 0				255				 
Think that 1111 is 15, so F in hexa. 
Also T, stands for transparency. */
#define RED_PURE 0x00FF0000
#define GREEN_PURE 0x0000FF00
#define BLUE_PURE 0x000000FF

/* ------------------------ STRUCTS ------------------------ */

/** PURPOSE : struct of a vector, 2D representation. */
typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

/** PURPOSE : struct that stores image data. Coordinates are
 * necessary when working with sprites. */
typedef struct s_data
{
	void		*img;
	char		*addr;
	t_vector	coords;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_program
{
	/* ----- SHARED ---- */
	void *mlx;
	void *mlx_window;
	/* ----- GUILLE ---- */
	
	
	/* ----- KIRIAM ---- */



}				t_prog;


/* ------------------------ PROTOTYPES ------------------------ */
int			trgb_translate(int t, int red, int green, int blue);
int			get_opposite(int colour_code);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init_window(t_prog *game, t_vector window_dimensions);
t_vector	get_window_dimensions(t_vector dimensions);

/* ------------------------ ERROR MESSAGES ------------------------ */


#endif
