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
	int		type;
	double	ratio;

	type = 0;
	ratio = (PLAYER_RATIO * game->map2d.pixel_per_block[0]);
	if (letter == 'X')
	{
		game->entity[number].letter = X_LETTER;
		game->entity[number].type = X_TYPE;
		type = game->entity[number].type;
		game->entity[number].visual_ratio = ratio;
		game->entity[number].collitions = X_COLLITION;
		game->entity[number].collition_space = ratio;
	}
	if (letter == 'R')
	{
		game->entity[number].letter = R_LETTER;
		game->entity[number].type = R_TYPE;
		type = game->entity[number].type;
		game->entity[number].visual_ratio = ratio;
		game->entity[number].collitions = R_COLLITION;
		game->entity[number].collition_space = ratio;
	}
	if (letter == 'C')
	{
		game->entity[number].letter = C_LETTER;
		game->entity[number].type = C_TYPE;
		type = game->entity[number].type;
		game->entity[number].visual_ratio = ratio;
		game->entity[number].collitions = C_COLLITION;
		game->entity[number].collition_space = ratio;
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
	if (letter == 'R')
	{
		if (type == 'H')
			return (R_HEALTH);
		if (type == 'D')
			return (R_DAMAGE);
		if (type == 'M')
			return (R_FLAG_MOVEMENT);
		if (type == 'A')
			return (R_MOVEMENT_ANIMATIONS);
	}
	if (letter == 'C')
	{
		if (type == 'H')
			return (C_HEALTH);
		if (type == 'D')
			return (C_DAMAGE);
		if (type == 'M')
			return (C_FLAG_MOVEMENT);
		if (type == 'A')
			return (C_MOVEMENT_ANIMATIONS);
	}
	return(0);
}

int get_value_OBSTACLE(int type, int letter)
{
	if (letter == 'X')
	{
		if (type == 'H')
			return (X_HITS);
	}
	if (letter == 'R')
	{
		if (type == 'H')
			return (R_HITS);
	}
	if (letter == 'C')
	{
		if (type == 'H')
			return (C_HITS);
	}
	return(0);
}

int get_value_COLLECTIONABLE(int type, int letter)
{
	if (letter == 'X')
	{
		if (type == 'H')
			return (X_HEALTH_UPGRADE);
		if (type == 'D')
			return (X_DAMAGE_UPGRADE);
		if (type == 'S')
			return (X_SPEED_UPGRADE);
		if (type == 'L')
			return (X_STABLE);
	}
	if (letter == 'R')
	{
		if (type == 'H')
			return (R_HEALTH_UPGRADE);
		if (type == 'D')
			return (R_DAMAGE_UPGRADE);
		if (type == 'S')
			return (R_SPEED_UPGRADE);
		if (type == 'L')
			return (R_STABLE);
	}
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
	return(0);
}