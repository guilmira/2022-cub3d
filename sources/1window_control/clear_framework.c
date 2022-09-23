/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_framework.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:29:48 by guilmira          #+#    #+#             */
/*   Updated: 2022/09/23 07:46:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : manage window closing or 
 * exiting with other widgets/tools. */
void	hk_close(void *game)
{
	clean_exit(game);
}

/** PURPOSE : Delete image tool. */
void	wash_screen(t_prog *game, mlx_image_t *image, \
t_dim window, int colour)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	(void) game;
	while (++j <= window.size[1])
	{
		i = -1;
		while (++i <= window.size[0] - WASH_SIZE_OFFSET)
			solid_pixel(image, i, coor(j, window.size[1]), colour);
	}
}

/** PURPOSE : Clear framework and create a new image to write pixels into. 
 * Window_number is either 0 for the 3D or 1 for the 2D. */
static inline void	frame_reset(int window_number, t_prog *game)
{
	if (window_number == 0)
	{
		ft_mlx_delete_image_safe(0, game);
		create_image(game, 0, game->w1.size);
	}
	else if (window_number == 1 && TOTAL_IMAGES > 1)
	{
		ft_mlx_delete_image_safe(1, game);
		create_image(game, 1, game->w2.size);
	}
}

/** PURPOSE : Deleete image, create a new one, and wash it in black. */
void	reset_and_wash_frame(t_prog *game)
{
	static int	frame;

	//printf("												FRAME: 	 %i\n", frame);
	frame++;
	frame_reset(0, game);
	wash_screen(game, game->image[CUB_3D], game->w1, RED);
	wash_screen(game, game->image[CUB_3D], game->w1, BLACK);
}
