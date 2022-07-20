/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/20 20:01:47 by guilmira         ###   ########.fr       */
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

#include <time.h> //para borrar

/* ------------------------ MOD DEFINES ------------------------ */
/* WINDOW SIZE */
//size of window: 1920x1080p
/* MAXIMUN WINDOW SIZE ALLOWED - Mac Screen: 2560 x 1440 */
# define OX_WINDOW 1920
# define OY_WINDOW 1080

/* Full minimap */
# define OX_MINIMAP OX_WINDOW 
# define OY_MINIMAP OY_WINDOW 
# define OX_MINIMAP_O 0 
# define OY_MINIMAP_O 0

/* 0 - no minimap
2 - minimap corner
4 - full minimap */
# define MINIMAP_INTIAL_STATE 2

/* Corner minimap */
# define OX_CORNER_WINDOW_FACTOR 6
# define OY_CORNER_WINDOW_FACTOR 6
# define OX_CORNER_WINDOW_DESPLACEMENT 6
# define OY_CORNER_WINDOW_DESPLACEMENT 6
 

# define D2 2
//only round numbers, preferable 10 or 100
# define OX_DIV 10
# define OY_DIV 10
# define TITLE_WINDOW "CUBE"

//player info
# define PLAYER_RATIO 0.5

# define TOTAL_IMAGES 2
# define SAFE_OFFSET 0.0001
//# define RAYCAST_OFFSET 100 // pixels per aperture
# define RAYCAST_OFFSET 6
# define FOV_DEGREE 30
/* ------------------------ STRUCTS ------------------------ */

/** PURPOSE : struct of a vector, 2D representation.
 * Origin is assumed at axis origin. */
typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

/** PURPOSE : Set of coordinates. */
typedef struct s_coordinates
{
	int ox;
	int oy;
	int	size_x;
	int	size_y;
}				t_coor;

/** PURPOSE : Set of coordinates. */
typedef struct s_dimensions
{
	double origin[D2];
	double size[D2];
	double limit[D2];
	double unit[D2];
	double pixel_per_block[D2];

}				t_dim;

/** PURPOSE : Beam dimensions
 * ^ - - - - ^ - - - - ^
 * \ - - - - | - - - - /
 * - \ - - - | - - - / -  
 * - - \ - - | - - / - - 
 * - - - \ - | - / - - - 
 * - - - - \ | / - - - -
 * - - - - - o - - - - - */
typedef struct s_beam
{
	double		position[D2];
	double		low_bound[D2];
	double		high_bound[D2];
	t_vector	vis;
	t_vector	vis_dir;
	t_vector	plane_left;
	t_vector	plane_right;
	t_vector	plane_segment;
	double		aperture_units;
}				t_beam;

typedef struct s_player
{
	double		position[D2];
	t_vector	vis;
	
}				t_player;

typedef struct s_program
{
    /* ----- SHARED ---- */
	mlx_t		*mlx;
	mlx_image_t	*image[TOTAL_IMAGES + 1];
	//void	*mlx_window;
	char		**map;
	/*---- MAP_INFO ----*/
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int			sky_clr;
	int			floor_clr;
	/* ----- GUILLE ---- */
	t_coor		minimap;
	int			minimap_state;
	t_dim		w1;
	t_dim		w2;
	t_player	pl;
	/* ----- KIRIAM ---- */
	int			file;
    int			map_x;
    int			map_y;
}               t_prog;

/* references to slots of images in image[TOTAL_IMAGES + 1];
Window 1 for 3D and window 2 Minimap */
#define W0 0
#define W1 1

/* ------------------------ ENUMS ------------------------ */
/** PURPOSE : Rectangle size. */
enum player_size
{
	x_size = 3,
	y_size = 3
};

/* ------------------------ DIMENSIONS OF CUBE ------------------------ */

//prototipos rapidos.
void	minimap_state(t_prog *game);
void	minimap_dimensions(t_prog *game);

/* ------------------------ PROTOTYPES ------------------------ */
/* MAP PARSER */
void		parser(t_prog *game, int ac, char **av);
void		fill_lst(t_prog *game, t_list **aux_lst);
int			parselst(t_prog *game, t_list *aux_lst);
void		printlist(t_list *list);
int 		map_build(int data_len, t_prog *game, t_list *aux_lst);

/* STRUCT INIT */
void		init_game(t_prog *game);
void		init_window(t_prog *game, t_vector window_dimensions);
t_vector	get_window_dimensions(t_vector dimensions);
void 		create_image(t_prog *game, int array_position, double size[]);
void		framework_dimensions(t_prog *game);

/* FRAMEWORKS */
int			trgb_translate(int red, int blue, int green, int transparency);
int			get_opposite(int colour_code);
void		main_image_framework(t_prog *game);
void		framework_2D(t_prog *game);

/* GEOMETRY TOOLS */
void		coor_identifier(mlx_image_t *image, t_prog *game, double coor_x, double coor_y, double window_size);
void put_vertical(double coordinate_x, double limit_y, int colour, t_prog *game);
void put_horizontal(double coordinate_y, double limit_x, int colour, t_prog *game);
void 		solid_pixel(mlx_image_t *image, int coor_x, int coor_y, uint32_t colour);

/* VECTOR TREATMENT */
void draw_vector(t_vector vec, double origin[], uint32_t colour, t_prog *game);

/* VECTOR TOOLS */
double get_module(t_vector vec);
t_vector get_unit_vector(t_vector vec);
t_vector rotate_vector(t_vector vec, int angle);

/* VECTOR ARITHMETIC */
t_vector	sum_vec(t_vector lhs, t_vector rhs);
t_vector	sub_vec(t_vector lhs, t_vector rhs);
t_vector	mul_vec(t_vector lhs, float escalar);
t_vector	div_vec(t_vector lhs, float escalar);
/* VECTOR ARITHMETIC ADVANCED */
t_vector	get_perpendicular(t_vector v);
t_vector	invert_sense_vector(t_vector v);
/* Initialize beam dimensions */
void init_beam(t_beam *beam, double position[], t_vector dir, t_prog *game);

/* RAY CASTING */
t_vector	cast_ray(t_vector direction, double low_boundry[], double high_boundry[], t_prog *game);
void cast_beam(t_beam *beam, t_prog *game);

/* CLEAR MEMORY */
void		clean_exit(t_prog *game);
void		ft_shutdown(char *error_msg, t_prog *game);
void		freemat(char **mat);

/* LOOP */
void		hooks_and_loops(t_prog *game);

/* PLAYER */
void draw_player_position(mlx_image_t *image, double position[], t_vector dir, t_prog *game);
void draw_2d_player(mlx_image_t *image, double pos[], double radio, int colour, t_prog *game);
void fill_player_pos(t_prog *game, double player_pos[]);

/* TOOLS */
double coor(double y, double size_y);
double degree_to_radian(double degree);
float ft_line(float slope, float x, float ordinate);
void draw_rectangle(int x, int y, int base, int height, t_prog *game);
void draw_centered_rectangle(double o_x, double o_y, int base, int height, t_prog *game);
void wash_screen(t_prog *game, mlx_image_t *image, t_dim window, int colour);


//To remove from here eventually
void		ft_leaks(void);
void log_vector(t_vector v);
void log_coor(double array[]);
void log_d(double d);
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
