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

enum e_X_ENEMY_VALUES{
	X_HEALTH = 100,
	X_DAMAGE = 15,
	X_FLAG_MOVEMENT = 1,
	X_MOVEMENT_ANIMATIONS = 0
};

enum e_R_OBSTACLE_VALUES{
	R_HITS = 0,
};

enum e_C_COLLECTIONABLE_VALUES{
	C_HEALTH_UPGRADE = 0,
	C_DAMAGE_UPGRADE = 0,
	C_SPEED_UPGRADE = 0,
	C_STABLE = 0
};


#endif