/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2D_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:59:34 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/13 15:13:05 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline t_enemy *set_enemy_structure(int letter)
{
	t_enemy *fill;

	fill = malloc(sizeof(t_enemy));
	fill->health = get_value_ENEMY('H', letter);
	fill->damage = get_value_ENEMY('D', letter);
	fill->speed = 0.001;
	fill->flag_movement = get_value_ENEMY('M', letter);
	fill->movement_animations = get_value_ENEMY('A', letter);
	return (fill);
}

static inline t_obstacle *set_obstacle_structure(int letter)
{
	t_obstacle *fill;

	fill = malloc(sizeof(t_obstacle));
	fill->hits = get_value_OBSTACLE('H', letter);
	fill->second_sprite = NULL;
	return (fill);
}

static inline t_collectionable *set_collectionable_structure(int letter)
{
	t_collectionable *fill;

	fill = malloc(sizeof(t_collectionable));
	fill->health_upgrade = get_value_OBSTACLE('H', letter);
	fill->damage_upgrade = get_value_OBSTACLE('D', letter);
	fill->speed_upgrade  = get_value_OBSTACLE('S', letter);
	fill->stable  = get_value_OBSTACLE('L', letter);
	return (fill);
}


void set_entitys_structure(int letter, t_prog *game, int number, int coord[])
{
	int type;

	game->entity[number].type_enemy = NULL;
	game->entity[number].type_obstacle = NULL;
	game->entity[number].type_collectionable = NULL;
	game->entity[number].position[0] = coord[0] * \
		(double) game->map2d.pixel_per_block[0] + \
		((double) game->map2d.pixel_per_block[0] / 2);
	game->entity[number].position[1] = coord[1] * \
		(double) game->map2d.pixel_per_block[1] + \
		((double) game->map2d.pixel_per_block[1] / 2);
	type = build_entitys_default(letter, game, number);
	if (type == T_ENEMY || type == T_EN_OB || type == T_CO_EN || type == T_ALL)
		game->entity[number].type_enemy = set_enemy_structure(letter);
	if (type == T_OBSTACLE || type == T_EN_OB || type == T_OB_CO || type == T_ALL)
		game->entity[number].type_obstacle = set_obstacle_structure(letter);
	if (type == T_COLLECTIONABLE || type == T_OB_CO || type == T_CO_EN || type == T_ALL)
		game->entity[number].type_collectionable = set_collectionable_structure(letter);
}
