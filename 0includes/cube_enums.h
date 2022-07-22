/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_enums.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:59:28 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/22 17:56:44 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_ENUMS_H
# define CUBE_ENUMS_H

/* ------------------------ ENUMS ------------------------ */
/** PURPOSE : Rectangle size. */
enum player_size
{
	x_size = 3,
	y_size = 3
};
enum player_movement
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
enum player_vision
{
	key_lookright,
	key_lookleft
};

#endif
