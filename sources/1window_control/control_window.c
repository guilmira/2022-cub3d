/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/01 09:43:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Tool to safely clear an image and set pointer to null. */
void	ft_mlx_delete_image_safe(int image_position, t_prog *game)
{
	mlx_delete_image(game->mlx, game->image[image_position]);
	game->image[image_position] = NULL;
}

/** PURPOSE : Create image manager. */
void	create_image(t_prog *game, int array_position, double size[])
{
	mlx_image_t	*image;

	image = mlx_new_image(game->mlx, (int) size[0], (int) size[1]);
	if (!image)
		ft_shutdown(EX3, game);
	if (game->image[array_position])
		ft_mlx_delete_image_safe(array_position, game);
	game->image[array_position] = image;
}
