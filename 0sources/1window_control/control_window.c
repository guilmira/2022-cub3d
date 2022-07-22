/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 14:23:27 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/22 15:26:48 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Delete image tool. */
void wash_screen(t_prog *game, mlx_image_t *image, t_dim window, int colour)
{
	int i;
	int j;

	i = -1;
	j = 0;
	(void) game;
	while (++j <= window.limit[1])
	{
		i = -1;
		while (++i <= window.limit[0] - 1)
			solid_pixel(image, i, coor(j, window.limit[1]), colour);
	}
}

/** PURPOSE : Create image manager. */
void create_image(t_prog *game, int array_position, double size[])
{
	mlx_image_t	*image;

	image = mlx_new_image(game->mlx, (int) size[0], (int) size[1]);
	if (!image)
		ft_shutdown(EX3, game);
	if (game->image[array_position])
		ft_mlx_delete_image_safe(array_position, game);
	game->image[array_position] = image; 
}