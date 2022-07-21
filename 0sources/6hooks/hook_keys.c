/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:32:07 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 10:32:27 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : manage keys. */
void	hk_keys(mlx_key_data_t key, void *g)
{
	t_prog *game;

	game = (t_prog *)g;
	if (key.key == MLX_KEY_ESCAPE)
		clean_exit(game);
	if (key.key == MLX_KEY_TAB)
	{
		game->minimap_state++;
		if (game->minimap_state == 6)
		{
			game->minimap_state = 0;
		}
		if (game->minimap_state == 2 || game->minimap_state == 4)
		{

			minimap_dimensions(game);
			if (game->minimap_state)
				create_image(game, 1, game->w2.size);
		}
	}

}