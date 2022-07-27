/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:18:40 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/05 14:19:02 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : assign rose vector values. */
static void swich_vector(int i, double move_unit, t_vector *aux)
{
	aux->x = 0;
	aux->y = 0;
	if (i == key_up || i == key_NW || i == key_NE)
		aux->y = move_unit;
	if (i == key_down || i == key_SW || i == key_SE)
		aux->y = 0 - move_unit;
	if (i == key_right || i == key_NE || i == key_SE)
		aux->x = move_unit;
	if (i == key_left || i == key_NW || i == key_SW)
		aux->x = 0 - move_unit;
}

/** PURPOSE : just like a wind rose, create vectors in each coordinate. */
static void	movement_vector_init(double move_unit, t_prog *game)
{
	t_vector aux;
	int i;

	i = -1;
	while (++i < 8)
	{
		swich_vector(i, move_unit, &aux);
		game->wind_rose[i] = aux;
	}
}

/** PURPOSE : pointers at images to NULL */
static void init_image(t_prog *game)
{
	int	i;

	i = -1;
	while (++i < TOTAL_IMAGES + 1)
		game->image[i] = NULL;
}

/* provisional */
void	init_map2D(t_prog *game)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < 20)
	{
		while (++i < 60)
		{
			game->provisional_map2D[j][i] = 0;
			if (j == 0 || j == 19)
				game->provisional_map2D[j][i] = 1;
			if (i == 0 || i == 59)
				game->provisional_map2D[j][i] = 1;	
		}
		i = -1;
	}
}

/** PURPOSE : init MLX and set pointers to NULL.
 * 1. mlx_returns a pointer (void *). 
 * The library functions need it in order to work.
 * 2. Inits the rest of the variables within the struct. */
void	init_game(t_prog *game)
{
	game->mlx = mlx_init(OX_WINDOW, OY_WINDOW, TITLE_WINDOW, 1);
	if (!game->mlx)
		ft_shutdown("Error.\nMLX could not be initialized\n", game);
	/* --------------------------------------------------------------- */
	//INIT all pointers to NULL, variables to zero.
	game->map = NULL;
	game->file = 0;
	game->minimap_state = MINIMAP_INTIAL_STATE;
	/* --------------------------------------------------------------- */
	init_image(game);
	movement_vector_init(MOVEMENT_PIXEL_UNIT, game);
	game->pl.flag_movement = 1;
	game->pl.flag_trance = 0;
	init_map2D(game);//provisonal SOLO PARA MIS PRUEBAS
}