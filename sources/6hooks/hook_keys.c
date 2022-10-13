/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:32:07 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/13 15:10:43 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Is there os is there not a minimap. */
static inline int	is_minimap(t_prog *game)
{
	if (!game->minimap_state)
		return (0);
	else if (game->minimap_state == 4)
		return (1);
	else if (game->minimap_state == 2)
		return (2);
	else
		return (0);
}

/** PURPOSE : Correct minimap status and reset screen. */
void	update_player_location(t_prog *game)
{
	double	coor_base[D2];
	double	coor_fraccion[D2];
	double	coor_base_old[D2];
	double	coor_factor[D2];

	coor_base[0] = (double)(game->pl.position[0]) \
	* game->map2D.pixel_per_block[0];
	coor_base[1] = (double) game->pl.position[1] * \
	game->map2D.pixel_per_block[1];
	coor_base_old[0] = (double)(game->pl.position[0]) * \
	game->map2D.v_pixel_per_block[0];
	coor_base_old[1] = (double) game->pl.position[1] * \
	game->map2D.v_pixel_per_block[1];
	coor_factor[0] = (game->pl.v_position_coor[0] - coor_base_old[0]) \
	/ (double) game->map2D.v_pixel_per_block[0];
	coor_factor[1] = (game->pl.v_position_coor[1] - coor_base_old[1]) \
	/ (double) game->map2D.v_pixel_per_block[1];
	coor_fraccion[0] = coor_factor[0] * game->map2D.pixel_per_block[0];
	coor_fraccion[1] = coor_factor[1] * game->map2D.pixel_per_block[1];
	game->pl.position_coor[0] = coor_base[0] + coor_fraccion[0];
	game->pl.position_coor[1] = coor_base[1] + coor_fraccion[1];
}

/** PURPOSE : Evaluate minimap variables */
void	reconstruct_minimap_variables(t_prog *game)
{
	game->w1.size[1] = OY_WINDOW;
	game->w1.size[0] = game->w1.size[1];
	mlx_set_window_size(game->mlx, game->w1.size[0], game->w1.size[1]);
	minimap_dimensions(game);
	game->map2D.pixel_per_block[0] = game->map2D.v_pixel_per_block[0];
	game->map2D.pixel_per_block[1] = game->map2D.v_pixel_per_block[1];
	update_pixel_per_block(game);
	game->pl.position_coor[0] = game->pl.v_position_coor[0];
	game->pl.position_coor[1] = game->pl.v_position_coor[1];
}

/** PURPOSE : Executed when hitting tab. It executes twice */
static inline void	hook_control_minimap(t_prog *game)
{
	correct_minimap_value(game);
	game->map2D.v_pixel_per_block[0] = 0;
	game->map2D.v_pixel_per_block[1] = 0;
	game->w1.size[1] = OY_WINDOW;
	game->w1.size[0] = OX_WINDOW;
	if (is_minimap(game) == 1)
		reconstruct_minimap_variables(game);
	else
	{
		game->w1.size[1] = OY_WINDOW;
		game->w1.size[0] = game->w1.size[1];
		minimap_dimensions(game);
		game->w1.size[1] = OY_WINDOW;
		game->w1.size[0] = OX_WINDOW;
		mlx_set_window_size(game->mlx, game->w1.size[0], game->w1.size[1]);
		game->map2D.v_pixel_per_block[0] = game->map2D.pixel_per_block[0];
		game->map2D.v_pixel_per_block[1] = game->map2D.pixel_per_block[1];
		update_pixel_per_block(game);
		update_player_location(game);
	}
}

/** PURPOSE : manage keys. */
void	hk_keys(mlx_key_data_t key, void *g)
{
	t_prog	*game;

	game = (t_prog *)g;
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(game);
	else if (key.key == MLX_KEY_TAB)
		hook_control_minimap(game);
	else if (key.key == MLX_KEY_F)
	{
		ft_putstr_fd("Wind mode activated. Speed boosted.\n", 1);
		game->pl.flag_trance++;
	}
	else if (key.key == MLX_KEY_G)
	{
		if (game->pl.flag_trance)
		{
			ft_putstr_fd("Exhausted. Speed back to normal.\n", 1);
			game->pl.flag_trance--;
		}
	}
	else
		movement_control(key, game);
}
