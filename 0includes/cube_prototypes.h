/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/06 09:11:22 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_PROTOTYPE_H
# define CUBE_PROTOTYPE_H

#include "cube_structs.h"




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
void 		init_map2D(char **map, t_prog *game);
void		minimap_dimensions(t_prog *game);



/* FRAMEWORKS */
int			trgb_translate(int red, int blue, int green, int transparency);
int			get_opposite(int colour_code);
void		main_image_framework(t_prog *game);
void		framework_2D(t_prog *game);
void update_pixel_per_block(t_prog *game);

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
t_vector	mul_vec(t_vector lhs, double escalar);
t_vector	div_vec(t_vector lhs, double escalar);
/* VECTOR ARITHMETIC ADVANCED */
t_vector	get_perpendicular(t_vector v);
t_vector	invert_sense_vector(t_vector v);
/* Initialize beam dimensions */
void init_beam(t_beam *beam, double position[], t_vector dir, t_prog *game);

/* RAY CASTING */
t_vector	cast_ray(t_vector direction, double position[], double low_boundry[], double high_boundry[], t_prog *game);

/* COLLISION */
int	collision_wall(t_vector ray, double position[], t_prog *game);
int	collision_window(t_vector ray, double low_boundry[], double high_boundry[]);

/* BEAM */
void cast_beam(t_beam *beam, t_prog *game);
void draw_vision_beam(double position[], t_vector vis, int angle, int ray_offset, t_prog *game);
double plane_lenght_and_direction(t_beam *beam, int angle);


/* CLEAR MEMORY */
void		clean_exit(t_prog *game);
void		ft_shutdown(char *error_msg, t_prog *game);
void		freemat(char **mat);
void	ft_mlx_delete_image_safe(int image_position, t_prog *game);

/* LOOP */
void		hooks_and_loops(t_prog *game);

/* RENDERING LOOP "2D" 60FPS */

void	put_frame2D(t_prog *game);
void	hook_control_minimap(t_prog *game);


/* RENDERING LOOP "3D" 60FPS */
void	put_frame3D(t_prog *game);


void	hk_keys(mlx_key_data_t key, void *g);

/* PLAYER */
void draw_player_position(mlx_image_t *image, double position[], t_vector vis, t_prog *game);
void draw_2d_player(mlx_image_t *image, double pos[], double radio, int colour, t_prog *game);
void fill_player_pos(t_prog *game, double player_pos[]);

/* MOVEMENT */
void	vison_control(mlx_key_data_t key, t_prog *game);
void	movement_control(mlx_key_data_t key, t_prog *game);

/* TOOLS */
double coor(double y, double size_y);
double degree_to_radian(double degree);
void draw_rectangle(int x, int y, int base, int height, t_prog *game);
void draw_centered_rectangle(double o_x, double o_y, int base, int height, t_prog *game);
void wash_screen(t_prog *game, mlx_image_t *image, t_dim window, int colour);
void put_lineH(double start[], double end[], int colour, t_prog *game);
void put_lineV(double start[], int size, int colour, t_prog *game);

void translate_to_screen(double position_map[], double position_screen[], int pixel_per_block[], t_prog *game);


//To remove from here before evaluation
void		ft_leaks(void);
void log_vector(t_vector v);
void log_coor(double array[]);
void log_d(double d);
void log_beam(t_beam *beam);
void print_map(char **map, t_prog *game);
void log_coor_int(int i[]);


int	collision_wall_trigonometric(t_vector ray, double position[], t_grid *grid, t_prog *game);

#endif
