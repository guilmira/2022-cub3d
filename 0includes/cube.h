/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/07 15:17:24 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/* ------------------------ INCLUDES ------------------------ */
/* LIBS */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
//# include <mlx.h>
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>
/* LIBFT */
# include "../libft_submodule/0includes/libft.h"
//-lm man man 3 math ALL functions allowed

/* ------------------------ MOD DEFINES ------------------------ */
/* WINDOW SIZE */
//size of window: 1920x1080p
/* MAXIMUN WINDOW SIZE ALLOWED - Mac Screen: 2560 x 1440 */
# define OX_WINDOW 1920
# define OY_WINDOW 1080
# define OX_MINIMAP OX_WINDOW - 8 * OX_UNIT
# define OY_MINIMAP OY_WINDOW - 8 * OY_UNIT
# define OX_MINIMAP_O 0 + 8 * OX_UNIT
# define OY_MINIMAP_O 0 + 8 * OY_UNIT

//only round numbers, preferable 10 or 100
# define OX_DIV 10
# define OY_DIV 10
# define OX_UNIT OX_WINDOW / OX_DIV
# define OY_UNIT OY_WINDOW / OY_DIV
# define TITLE_WINDOW "CUBE"

# define TOTAL_IMAGES 2

/* ------------------------ STRUCTS ------------------------ */

/** PURPOSE : struct of a vector, 2D representation.
 * Origin is assumed at axis origin. */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/** PURPOSE : Set of coordinates. */
typedef struct s_coordinates
{
	int ox;
	int oy;
	int	size_x;
	int	size_y;
}				t_coor;

/** PURPOSE : struct of a vector, 2D representation.
 * Origin is assumed at axis origin. */
typedef struct s_unit_vec
{
	float	x;
	float	y;
}				t_unit_vec;

/** PURPOSE : Set of coordinates. */
typedef struct s_dimensions
{
	double origin[2];
	double size[2];
	double limit[2];
	double sec_limit[2];
	double unit[2];
}				t_dim;

typedef struct s_program
{
    /* ----- SHARED ---- */
	mlx_t		*mlx;
	mlx_image_t	*image[TOTAL_IMAGES + 1];
	//void	*mlx_window;
	char	**map;
	/*---- MAP_INFO ----*/
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		sky_clr;
	int		floor_clr;
	/* ----- GUILLE ---- */
	t_coor	minimap;
	t_dim	w1;
	t_dim	w2;

	/* ----- KIRIAM ---- */
	int		file;
}               t_prog;


/* ------------------------ ENUMS ------------------------ */


/* ------------------------ DIMENSIONS OF CUBE ------------------------ */
enum e_minimap
{
	MAP_OX = 0 + OX_UNIT,
	MAP_OY = 0 + OY_UNIT,
	MAP_SIZE_X = OX_WINDOW - OX_UNIT,
	MAP_SIZE_Y = OY_WINDOW - OY_UNIT,
	MAP_UNIT_X = MAP_SIZE_X / 10,
	MAP_UNIT_Y = MAP_SIZE_Y / 10,
};

/* ------------------------ PROTOTYPES ------------------------ */
/* MAP PARSER */
void		parser(t_prog *game, int ac, char **av);

/* STRUCT INIT */
void		init_game(t_prog *game);
void		init_window(t_prog *game, t_vector window_dimensions);
t_vector	get_window_dimensions(t_vector dimensions);

/* FRAMEWORKS */
int			trgb_translate(int red, int blue, int green, int transparency);
int			get_opposite(int colour_code);
void		main_image_framework(t_prog *game);
void		secd_image_framework(t_prog *game);
/* VECTOR TREATMENT */
void draw_vector(mlx_image_t *image, t_vector vec, int x_origin, int y_origin);

/* VECTOR TOOLS */
double get_module(t_vector vec);
t_unit_vec get_unit_vector(t_vector vec);
t_vector rotate_vector(t_vector vec, int angle);


/* CLEAR MEMORY */
void		clean_exit(t_prog *game);
void		ft_shutdown(char *error_msg, t_prog *game);
void		freemat(char **mat);

/* LOOP */
void		hooks_and_loops(t_prog *game);

/* PLAYER */
void draw_player_position(mlx_image_t *image, float x, float y, t_prog *game);

/* TOOLS */
double coor(double y, double size_y);
float degree_to_radian(float degree);
float ft_line(float slope, float x, float ordinate);
void draw_rectangle(mlx_image_t *image, int x, int y, int base, int height);
void draw_centered_rectangle(mlx_image_t *image, int x, int y, int base, int height);


//To remove from here eventually
void		ft_leaks(void);

/* ------------------------ ERROR MESSAGES ------------------------ */
# define EX		"Error.\n"
# define EX1	"Error.\nNo memory available for allocation.\n"
# define EX2	"Error.\nCould not generate new window.\n"
# define EX3	"Error.\nCould not generate image.\n"

/* ------------------------ STANDARD DEFINES ------------------------ */

/* COLOURS */
/* It follows the TRGB format. 
Binary 0000 0000 		1111 1111
Hexa  0x00			0x  F 	 F
Decimal 0				255				 
Think that 1111 is 15, so F in hexa. 
Also T, stands for transparency. */
# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF

#endif
