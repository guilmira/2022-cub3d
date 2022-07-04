/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 12:03:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/* ------------------------ INCLUDES ------------------------ */
/* LIBS */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
/* LIBFT */
# include "../libft_submodule/0includes/libft.h"
//-lm man man 3 math ALL functions allowed

/* ------------------------ MOD DEFINES ------------------------ */
/* WINDOW SIZE */
//size of window: 1920x1080p
/* MAXIMUN WINDOW SIZE ALLOWED - Mac Screen: 2560 x 1440 */
# define OX_WINDOW 1920
# define OY_WINDOW 1080
# define OX_DIV 10
# define OY_DIV 10
# define OX_UNIT OX_WINDOW / OX_DIV
# define OY_UNIT OY_WINDOW / OY_DIV

# define TITLE_WINDOW "CUBE"

/* ------------------------ STRUCTS ------------------------ */

/** PURPOSE : struct of a vector, 2D representation.
 * Origin is assumed at axis origin. */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/** PURPOSE : struct of a vector, 2D representation.
 * Origin is assumed at axis origin. */
typedef struct s_unit_vec
{
	float	x;
	float	y;
}				t_unit_vec;



/** PURPOSE : struct that stores image data.
 * Coordinates might not be necessary. */
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
	void	*mlx;
	void	*mlx_window;
	char	**map;
	/* ----- GUILLE ---- */
	
	/* ----- KIRIAM ---- */
	int		file;
}				t_prog;

/* ------------------------ ENUMS ------------------------ */
enum e_hook_events
{
	TEST_EVENT,
	DESTROY_EVENT	= 17
};
enum e_hook_keys
{
	LEFT_KEY	= 0,
	DOWN_KEY	= 1,
	RIGHT_KEY	= 2,
	UP_KEY		= 13,
	ESCAPE_KEY	= 53
};

/* ------------------------ DIMENSIONS OF CUBE ------------------------ */


/* ------------------------ PROTOTYPES ------------------------ */
/* MAP PARSER */
void		parser(t_prog *game, int ac, char **av);

/* STRUCT INIT */
void		init_game(t_prog *game);
void		init_window(t_prog *game, t_vector window_dimensions);
t_vector	get_window_dimensions(t_vector dimensions);

/* IMAGE TREATMENT */
int			trgb_translate(int t, int red, int green, int blue);
int			get_opposite(int colour_code);
void		my_mlx_pixel_put(t_data *image, int x, int y, int color);

/* VECTOR TREATMENT */
void draw_vector(t_data *image, t_vector vec, int x_origin, int y_origin);

/* VECTOR TOOLS */
double get_module(t_vector vec);
t_unit_vec get_unit_vector(t_vector vec);
t_vector rotate_vector(t_vector vec, int angle);


/* CLEAR MEMORY */
void		clean_exit(t_prog *game);
void		ft_shutdown(char *error_msg, t_prog *game);

/* LOOP */
void		hooks_and_loops(t_prog *game);

/* PLAYER */
void draw_player_position(t_data *image, int x, int y, t_prog *game);

/* TOOLS */
float coor(float y);
float degree_to_radian(float degree);
float ft_line(float slope, float x, float ordinate);
void draw_rectangle(t_data *image, int x, int y, int base, int height);
void draw_centered_rectangle(t_data *image, int x, int y, int base, int height);


//To remove from here eventually
void		ft_leaks(void);

/* ------------------------ ERROR MESSAGES ------------------------ */
# define EX		"Error.\n"
# define EX1	"Error.\nNo memory available for allocation.\n"
# define EX2	"Error.\nCould not generate new window.\n"

/* ------------------------ STANDARD DEFINES ------------------------ */

/* COLOURS */
/* It follows the TRGB format. 
Binary 0000 0000 		1111 1111
Hexa  0x00			0x  F 	 F
Decimal 0				255				 
Think that 1111 is 15, so F in hexa. 
Also T, stands for transparency. */
# define RED_PURE 0x00FF0000
# define GREEN_PURE 0x0000FF00
# define BLUE_PURE 0x000000FF

#endif
