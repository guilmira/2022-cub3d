/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 17:24:27 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

# include "cube_defines.h"
/* ------------------------ STRUCTS ------------------------ */

/** PURPOSE : struct of a vector, 2D representation.
 * Origin is assumed at axis origin. */
typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

/** PURPOSE : Structure to define a full ray.
 * Not only the vector itself, but its origin, direction
 * blocks that covers in grid and in what face of wall impacts. */
typedef struct s_ray
{
	double			origin[D2];
	t_vector		dir;
	int				pos[D2];
	double			delta[D2];
	int				step[D2];
	int				step_increase[D2];
	double			relative_distance[D2];
	double			net_distance[D2];
	int				face;
	t_vector		resultant_vector;
}					t_ray;

/** PURPOSE : Set of dimensions of window. */
typedef struct s_dimensions
{
	double			origin[D2];
	double			size[D2];
	double			unit[D2];
}					t_dim;

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
	double			position[D2];
	t_vector		vis;
	t_vector		vis_dir;
	t_vector		plane_left;
	t_vector		plane_right;
	t_vector		plane_segment;
	int				number_of_rays;
}					t_beam;

/** PURPOSE : Info of the player
 * Where is located, where is it looking at. */
typedef struct s_player
{
	bool			key[512];
	int				fov;
	int				position[D2];
	double			position_coor[D2];
	double			v_position_coor[D2];
	double			ratio;
	t_vector		vis;
	t_beam			beam;
	t_vector		plane_perpendicular;
	int				flag_vis_perpend;
	int				flag_movement;
	int				flag_trance;
	double			speed;
	int				fast_r;
}					t_player;

/** PURPOSE : Map 2D given as an argument. */
typedef struct s_map
{
	int				**layout;
	int				**s_layout;
	int				val;
	int				height;
	int				width;
	int				s_height;
	int				s_width;
	int				pixel_per_block[D2];
	int				v_pixel_per_block[D2];
	char			**map;
	int				map_x;
	int				map_y;
}					t_map;

/** PURPOSE : Assist struct raycast. */
typedef struct s_data
{
	int				face;
	double			distance;
	t_vector		vector;
	int				wall_hit[D2];
}					t_data;

/** PURPOSE : Result of the raycast. */
typedef struct s_raycast
{
	t_vector		vision;
	t_vector		*rc_vector;
	double			*rc_distance;
	int				*rc_wall_side;
	int				*rc_wall_hit_x;
	int				*rc_wall_hit_y;
	double			rc_origin_coor[D2];
	int				number_of_rays;
}					t_raycast;

typedef struct s_program
{
	mlx_t			*mlx;
	mlx_image_t		*image[TOTAL_IMAGES + 1];
	t_map			map2d;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	mlx_texture_t	*t_north;
	mlx_texture_t	*t_south;
	mlx_texture_t	*t_west;
	mlx_texture_t	*t_east;
	int				sky_clr;
	int				floor_clr;
	t_dim			w1;
	t_dim			w2;
	t_player		pl;
	t_raycast		*rc;
	int				minimap_state;
	int				file;
	int				flag_engine_report;
}					t_prog;

#endif