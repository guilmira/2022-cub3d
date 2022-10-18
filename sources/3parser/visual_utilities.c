/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:20:46 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	show_info(t_prog *game)
{	
	if (game->north)
		printf("North texture: %s\n", game->north);
	else
		printf("North texture: Not Parsed\n");
	if (game->south)
		printf("South texture: %s\n", game->south);
	else
		printf("South texture: Not Parsed\n");
	if (game->east)
		printf("East texture: %s\n", game->east);
	else
		printf("East texture: Not Parsed\n");
	if (game->west)
		printf("West texture: %s\n", game->west);
	else
		printf("West texture: Not Parsed\n");
	if (game->sky_clr != -1)
		printf("Sky colour: %d\n", game->sky_clr);
	else
		printf("Sky colour: ERROR\n");
	if (game->floor_clr != -1)
		printf("Floor colour: %d\n", game->floor_clr);
	else
		printf("Floor colour: ERROR\n");
	printf("\n");
}

void	show_map(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < game->map2d.map_x + 4)
		write(0, "-", 1);
	write(0, "\n", 1);
	i = -1;
	while (++i < game->map2d.map_y + 1)
		printf("(%s)\n", game->map2d.map[i]);
	i = -1;
	while (++i < game->map2d.map_x + 4)
		write(0, "-", 1);
	write(0, "\n", 1);
}
