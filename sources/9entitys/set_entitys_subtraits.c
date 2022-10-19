/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/13 15:13:05 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int build_entitys_default(int letter, t_prog *game, int number)
{
	int type;

	type = 0;
	if (letter == 'X')
	{
		game->entity[number].type = T_ENEMY;
		type = game->entity[number].type;
		game->entity[number].visual_ratio = game->pl.ratio;
		game->entity[number].collitions = 1;
		game->entity[number].collition_space = game->pl.ratio;
	}
	if (letter == 'R')
	{
		game->entity[number].type = T_OBSTACLE;
		type = game->entity[number].type;
		game->entity[number].visual_ratio = game->pl.ratio;
		game->entity[number].collitions = 1;
		game->entity[number].collition_space = game->pl.ratio;
	}
	if (letter == 'C')
	{
		game->entity[number].type = T_COLLECTIONABLE;
		type = game->entity[number].type;
		game->entity[number].visual_ratio = game->pl.ratio;
		game->entity[number].collitions = 1;
		game->entity[number].collition_space = game->pl.ratio;
	}
	return (type);
}

int get_value_ENEMY(int type, int letter)
{
	if (letter == 'X')
	{
		if (type == 'H')
			return (X_HEALTH);
		if (type == 'D')
			return (X_DAMAGE);
		if (type == 'M')
			return (X_FLAG_MOVEMENT);
		if (type == 'A')
			return (X_MOVEMENT_ANIMATIONS);
	}
}

int get_value_OBSTACLE(int type, int letter)
{
	if (letter == 'R')
	{
		if (type == 'H')
			return (R_HITS);
	}
}

int get_value_COLLECTIONABLE(int type, int letter)
{
	if (letter == 'C')
	{
		if (type == 'H')
			return (C_HEALTH_UPGRADE);
		if (type == 'D')
			return (C_DAMAGE_UPGRADE);
		if (type == 'S')
			return (C_SPEED_UPGRADE);
		if (type == 'L')
			return (C_STABLE);
	}
}