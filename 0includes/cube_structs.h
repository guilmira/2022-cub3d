/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/15 08:32:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_STRUCTS_H
# define CUBE_STRUCTS_H

#include "cube_defines.h"
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
	double		origin[D2];
	t_vector	dir;
	int 		position_2D[D2];
	double		delta[D2];
	int			step[D2];
	int			step_increase[D2];
	double		relative_distance[D2];
	double		net_distance[D2];
	int			face;
	t_vector	resultant_vector;
}				t_ray;

/** PURPOSE : Set of dimensions of window. */
typedef struct s_dimensions
{
	double origin[D2];
	double size[D2];
	double unit[D2];
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

/** PURPOSE : Info of the player
 * Where is located, where is it looking at. */
typedef struct s_player
{
	int			position[D2];
	double		position_coor[D2];
	double		ratio;
	t_vector	vis;
	t_beam		beam;
	int			flag_movement; //activates if there is any kind of movement
	int 		flag_trance; //activates if there is turbo
}				t_player;

/** PURPOSE : Map 2D given as an argument. */
typedef struct s_map
{
	int		**layout;
	int		height;
	int		width;
	int		pixel_per_block[D2];
	/* --------------- */
	char		**map;
	int			map_x;
	int			map_y;
	/* --------------- */
}				t_map;

typedef struct s_program
{
    /* ----- SHARED ---- */
	mlx_t		*mlx;
	mlx_image_t	*image[TOTAL_IMAGES + 1];
	
	t_map		map2D;
	/*---- MAP_INFO ----*/
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	int			sky_clr;
	int			floor_clr;
	/* ----- GUILLE ---- */
	t_dim		w1;
	t_dim		w2;
	t_player	pl;
	//t_vector	wind_rose[MOVE_OPTIONS];
	int			minimap_state;
	/* ----- KIRIAM ---- */
	int			file;
	
}               t_prog;




/* LEGACY, OBSOLETO PARA BORRAR PRONTO */
/* PURPOSE : Used as an auxiliar grid to calculate collisions. */
typedef struct s_grid
{
	double	partial[2]; //const
	double	delta[2]; //const

	int		blocks[2];
	double	distance[2];
}				t_grid;
#endif
