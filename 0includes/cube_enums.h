/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_enums.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 17:24:47 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_ENUMS_H
# define CUBE_ENUMS_H

/* ------------------------ ENUMS ------------------------ */
/** PURPOSE : Rectangle size. */
enum e_player_size
{
	x_size = 3,
	y_size = 3
};

enum e_player_movement
{
	key_up,
	key_down,
	key_left,
	key_right,
	key_NE,
	key_NW,
	key_SE,
	key_SW,
};
enum e_player_vision
{
	key_lookright,
	key_lookleft
};

enum e_WALL_COLLISION_TYPE{
	RIGHT_COLLISION = 1,
	LEFT_COLLISION,
	TOP_COLLISION,
	BOTTOM_COLLISION,
};

enum e_ENTITY_TYPE{
	T_ENTITY = 0,
 	T_ENEMY,
 	T_OBSTACLE,
 	T_COLLECTIONABLE,
 	T_EN_OB,
 	T_OB_CO,
 	T_CO_EN,
 	T_ALL,
};

/*------------------------- ENTITY BUILDER ---------------------------*/
/*
- TYPES
- '0' ENTITY ALONE NO TRAITS;
- '1' ENEMY ALONE;
- '2' OBSTACLE ALONE;
- '3' COLLECTIONABLE ALONE;
- '4' ENEMY AND OBSTACLE;
- '6' OBSTACLE AND COLLECTIONABLE;
- '5' COLLECTIONABLE AND ENEMY;
- '7' ALL TRAITS;
*/

enum e_X_VALUES{
	X_TYPE = 1,
	X_VISUAL_RATIO = 0,
	X_COLLITION = 1,
	X_COLLITION_SPACE = 0,
	/*ENEMY*/
	X_HEALTH = 100,
	X_DAMAGE = 15,
	X_FLAG_MOVEMENT = 1,
	X_MOVEMENT_ANIMATIONS = 0,
	/*OBSTACLE*/
	X_HITS = 0,
	/*COLLECTIONABLE*/
	X_HEALTH_UPGRADE = 0,
	X_DAMAGE_UPGRADE = 0,
	X_SPEED_UPGRADE = 0,
	X_STABLE = 0
};

enum e_R_VALUES{
	R_TYPE = 2,
	R_VISUAL_RATIO = 0,
	R_COLLITION = 1,
	R_COLLITION_SPACE = 0,
	/*ENEMY*/
	R_HEALTH = 0,
	R_DAMAGE = 0,
	R_FLAG_MOVEMENT = 0,
	R_MOVEMENT_ANIMATIONS = 0,
	/*OBSTACLE*/
	R_HITS = 0,
	/*COLLECTIONABLE*/
	R_HEALTH_UPGRADE = 0,
	R_DAMAGE_UPGRADE = 0,
	R_SPEED_UPGRADE = 0,
	R_STABLE = 0
};

enum e_C_VALUES{
	C_TYPE = 3,
	C_VISUAL_RATIO = 0,
	C_COLLITION = 1,
	C_COLLITION_SPACE = 0,
	/*ENEMY*/
	C_HEALTH = 0,
	C_DAMAGE = 0,
	C_FLAG_MOVEMENT = 0,
	C_MOVEMENT_ANIMATIONS = 0,
	/*OBSTACLE*/
	C_HITS = 0,
	/*COLLECTIONABLE*/
	C_HEALTH_UPGRADE = 0,
	C_DAMAGE_UPGRADE = 0,
	C_SPEED_UPGRADE = 0,
	C_STABLE = 0
};


#endif