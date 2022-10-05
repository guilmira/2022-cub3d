/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_enums.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/01 13:29:36 by guilmira         ###   ########.fr       */
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
	TOP_COLLISION ,
	BOTTOM_COLLISION, 
};

#endif