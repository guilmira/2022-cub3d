/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/25 10:38:22 by guilmira         ###   ########.fr       */
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

/**PORPOUSE*
 ENTITY BUILDER:
 Allows to set entity parameters and build diferent structures of traits
 -----------------------------------------------------------------------------------------------------------------------------------------------------
	
	-Letter: Letter witch is referenced in the map;
 	-Type: Allows to filter between usable stuctures;
 			- '0' ENTITY ALONE NO TRAITS;
 			- '1' ENEMY ALONE;
 			- '2' OBSTACLE ALONE;
 			- '3' COLLECTIONABLE ALONE;
 			- '4' ENEMY AND OBSTACLE;
 			- '6' OBSTACLE AND COLLECTIONABLE;
 			- '5' COLLECTIONABLE AND ENEMY;
 			- '7' ALL TRAITS;
 	-Position: position relative to pixel in screen;
 	-Coord: Coordinates on map;
 	-Visual_ratio: radio of 2d sphere where the raycast collisions, allows to renderize big textures or small;
 	-Collitions: Flag wich allows to deactivate player collitions with texture;
 	-Collition_space: radio of 2d sphere where the player will collide with entity;
 	-Sprite: Structure with the desired base texture coud be a pointer to an other strucure info;
 	-Type_enemy: "game->entity[i].type_enemy" Defautl setted to NULL, if type correspond would be allocated and used traits of ENEMY structure;
 	-Type_obstacle: "game->entity[i].type_obstacle" Defautl setted to NULL, if type correspond would be allocated and used traits of OBSTACLE structure;
 	-Type_collectionable: "game->entity[i].type_collectionable" Defautl setted to NULL, if type correspond would be allocated and used traits of COLLECTIONABLE structure;
 
 	-Enemy_Structure:
		-Health: number of points of health. Default player damage set to 15 points;
		-Damage: number of damage point that enemy does. Default player health set to 100;
		-Speed: movement speed;
		-Flag_movement: 0 = centry_mode; 1 = Tracker;
		-Movement_animations: 0 = NO sprite update; 1 = Sprite updates while moving;

	-Collectionable_Stucture:
		-Pickeable: 0 = player gets effect on contact but collectionable remains; 1 = on contact vanishes;
		-Health_upgrade: number of health points that collectionable restores or reduce;
		-Damage_upgrade: number of damage points that collectionable increases or reduce;
		-Speed_upgrade: number of speed points that collectionable increases or reduce;
		-Stable: 0 = does NOT stay after picking; 1 = stays after picking;

	-Obstacle_Structure:
		-Hits: number of hits witch tackes to make it disappear. If 0 object is indestuctible;
		-Second_sprite: after a number of hits the texture will change to this texture;

-------------------------------------------------------------------------------------------------------------------------------------------------------
*/

typedef struct s_enemy
{
	int 			health;
	int 			damage;
	double 			speed;
	int 			flag_movement;
	int 			movement_animations;
}					t_enemy;

typedef struct s_collectionable
{
	int 			pickeable;
	int 			health_upgrade;
	int				damage_upgrade;
	int				speed_upgrade;
	int 			stable;
}					t_collectionable;

typedef struct s_obstacle
{
	int				hits;
	mlx_texture_t	*second_sprite;
}					t_obstacle;

typedef struct s_entity
{
	int				letter;
	int 			type; 
	double			position[D2];
	int				coord[D2];
	double			visual_ratio;
	int 			collitions;
	int 			collition_space;
	mlx_texture_t	*sprite;
	t_enemy			*type_enemy;
	t_obstacle		*type_obstacle;
	t_collectionable *type_collectionable;
}					t_entity;

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
	int 			damage; /*NEXT do sistem damage and hits 15 points default*/
	int 			health;
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
	t_entity		*entity;
	int				n_entitys;
	t_dim			w1;
	t_dim			w2;
	t_player		pl;
	t_raycast		*rc;
	int				minimap_state;
	int				file;
	int				flag_engine_report;

	//PROVISIONAl ---------------------
	mlx_texture_t *spr;

}					t_prog;

#endif