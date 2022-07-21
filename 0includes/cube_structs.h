/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 13:20:53 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

#include "cube.h"
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

/* BEAM */
void cast_beam(t_beam *beam, t_prog *game);
void draw_vision_beam(double position[], t_vector dir, int angle, int ray_offset, t_prog *game);
double plane_lenght_and_direction(t_beam *beam, int angle);


/* CLEAR MEMORY */
void		clean_exit(t_prog *game);
void		ft_shutdown(char *error_msg, t_prog *game);
void		freemat(char **mat);

/* LOOP */
void		hooks_and_loops(t_prog *game);

/* RENDERING LOOP 60FPS */
void	put_frame(t_prog *game);
void	hook_control_minimap(t_prog *game);

void	hk_keys(mlx_key_data_t key, void *g);

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
void log_beam(t_beam *beam);


#endif
