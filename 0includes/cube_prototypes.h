/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/07 13:13:29 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_PROTOTYPES_H
# define CUBE_PROTOTYPES_H

# include "cube_structs.h"

/* ------------------------ PROTOTYPES ------------------------ */
/* MAP PARSER */
void			parser(t_prog *game, int ac, char **av);
void			fill_lst(t_prog *game, t_list **aux_lst);
void			printlist(t_list *list);
int				map_build(int data_len, t_prog *game, t_list *aux_lst);
void			build_spaced_layout(t_prog *game, int height, int width);
int				**allocate_all_layout(int height, int width);
char			*getlimiter(char *limiter);
int				parse_limit(char *limiter);
int				parse_and_storage(char *limiter, t_prog *game, char *content);
int				getinfovisual(char *content, t_prog *game);
int				storage_info(char *limiter, t_prog *game, char *content);
char			*cacht_info_str(char *info);
int				catch_number(char *info);
int				parselst(t_prog *game, t_list *aux_lst);
int				check_num(int num);
int				check_comas(char *data);
int				parse_content(char *content);
int				getcoords(t_prog *game, t_list *aux_lst);
void			fill_spaces_map(t_prog *game, t_list *aux_lst);
int				is_closed(char **map);
int				get_maxlen(t_prog *game, t_list *aux_lst);
int				ret_l(t_list *aux_lst);
void			map_refill(t_prog *game, int c, t_list *aux_lst);


/*VISUAL UTILITIES PARSER*/

void			show_info(t_prog *game);
void			show_map(t_prog *game);


/* STRUCT INIT */
void			init_game(t_prog *game);
void			create_image(t_prog *game, int array_position, double size[]);
void			framework_dimensions(t_prog *game);
void			init_map2d(char **map, t_prog *game);
void			minimap_dimensions(t_prog *game);
int				**copy_double_pointer(int **var, int height, int width);
void			print_smap(int **s_map, int height, int width);
void			prep_textures(t_prog *game);
/* ------------------------ FPS ------------------------ */
/* FRAMEWORKS */
int				rgb_t_translate(int red, int green, int blue, int transparency);
int				get_red(int colour_code);
int				get_blue(int colour_code);
int				get_green(int colour_code);
int				get_transparent(int colour_code);
int				get_rgb_shadowed(int colour_code);
int				get_opposite(int colour_code);
void			framework_two_dim(t_prog *game);
void			update_pixel_per_block(t_prog *game);

/* LOOP AND FRAME CONTROL 60FPS */
void			hooks_and_loops(t_prog *game);
void			reset_and_wash_frame(t_prog *game);
void			hk_close(void *game);
void			put_frame_two_dim(t_prog *game);
void			put_frame_three_dim(t_prog *game);
void			hk_keys(mlx_key_data_t key, void *g);
void			update_player_location(t_prog *game);

/* CLEAR MEMORY */
void			clean_exit(t_prog *game);
void			ft_shutdown(char *error_msg, t_prog *game);
void			freemat(char **mat);
void			freemat_int(int **mat, int len);
int				check_radio(double coord[], double radio);
void			ft_mlx_delete_image_safe(int image_position, t_prog *game);
void			destroy_texture(t_prog *game);

/* ------------------------ RAYCAST ------------------------ */
/* RAY CASTING AND DDA ALGORITHM */
void			main_raycast_calculation(int angle, t_prog *game);
void			init_ray(t_ray *ray, double origin[], t_vector dir, \
t_prog *game);
t_vector		raycast(t_data *aux, t_vector dir, double origin[], \
t_prog *game);
mlx_texture_t	*get_texture_stripe(mlx_texture_t *texture, int percentage, \
uint32_t stripeheight, t_prog *game);
void			get_relative_distance(t_ray *ray, t_prog *game);
void			fix_net_distance(t_ray *ray, int case_factor, int block[]);

void			clear_raycast(t_prog *game);
double			calculate_plane_lenght(double angle, t_vector vis);
int				is_wall2d(int j, int i, t_prog *game);
void			correct_minimap_value(t_prog *game);

/* BEAM */
void			cast_beam(t_beam *beam, t_data *aux, t_prog *game);
double			plane_lenght_and_direction(t_beam *beam, int angle);
/* ------------------------ RAYCAST ------------------------ */
/* VECTOR TOOLS */
double			get_module(t_vector vec);
t_vector		get_unit_vector(t_vector vec);
/* VECTOR ARITHMETIC */
t_vector		sum_vec(t_vector lhs, t_vector rhs);
t_vector		sub_vec(t_vector lhs, t_vector rhs);
t_vector		mul_vec(t_vector lhs, double escalar);
t_vector		div_vec(t_vector lhs, double escalar);
/* VECTOR ARITHMETIC ADVANCED */
t_vector		get_perpendicular(t_vector v);
t_vector		invert_sense_vector(t_vector v);
/* ------------------------ DRAWING ------------------------ */
/* GEOMETRY TOOLS */
void			put_vertical(double coordinate_x, \
double limit_y, int colour, t_prog *game);
void			put_horizontal(double coordinate_y, \
double limit_x, int colour, t_prog *game);
void			put_line_h(double start[], double end[], \
int colour, t_prog *game);
void			put_line_v(double start[], int size, int colour, t_prog *game);
double			degree_to_radian(double degree);
/* ------------------------ 2D CUBE ------------------------ */
void			wash_screen(t_prog *game, mlx_image_t *image, \
t_dim window, int colour);
/* DRAWING TOOLS */
double			coor(double y, double size_y);
void			solid_pixel(mlx_image_t *image, \
int coor_x, int coor_y, uint32_t colour);
/* ------------------------ 3D CUBE ------------------------ */
void			draw_first_layer(t_prog *game);
void			draw_three_dimension_walls(t_prog *game);
void			draw_solid_wall(int ray_number, \
int wall_side, int size, t_prog *game);
void			draw_textured_wall(int wall_side, \
int ray_number, int size, t_prog *game);
mlx_texture_t	*get_oriented_texture(int wall_side, \
t_vector direction, t_prog *game);
/* ------------------------ PLAYER AND MOVEMENT ------------------------ */
/* PLAYER */
void			draw_player_position(mlx_image_t *image, t_prog *game);
/* MOVEMENT */
void			vison_control(mlx_key_data_t key, t_prog *game);
void			movement_control(mlx_key_data_t key, t_prog *game);
void			update_player_position(int key, t_prog *game);
void			update_player_vision(int key, t_prog *game);
int				wall_coll(t_prog *game, double new_pos[], \
int pixel_per_block[]);
void			filter_final_pos(t_prog *game, double new_pos[], \
int flag, int pixel_per_block[]);

/* TOOLS */
void			draw_centered_rectangle(double position[], \
int base, int height, t_prog *game);

void			translate_to_screen(double position_map[], \
double position_screen[], int pixel_per_block[], t_prog *game);

//To remove from here before evaluation
void			ft_leaks(void);
void			log_vector(t_vector v);
void			log_coor(double array[]);
void			log_d(double d);
void			log_beam(t_beam *beam);
void			print_map(char **map, t_prog *game, int **s_map);
void			log_coor_int(int i[]);
void			log_arrays(t_prog *game);
#endif