/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:32:07 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 11:48:50 by guilmira         ###   ########.fr       */
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
	if (key.key == MLX_KEY_TAB) //PACE por alguna razon las teclas se pulsan dos veces
		hook_control_minimap(game);
}