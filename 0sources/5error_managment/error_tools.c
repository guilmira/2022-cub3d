/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:54:59 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/22 15:23:25 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Tool to safely clear an image and set pointer to null. */
void	ft_mlx_delete_image_safe(int image_position, t_prog *game)
{
	mlx_delete_image(game->mlx, game->image[image_position]);
	game->image[image_position] = NULL;
}