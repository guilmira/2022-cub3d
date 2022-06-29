/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:39:56 by guilmira          #+#    #+#             */
/*   Updated: 2022/06/29 17:39:34 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

void ft_leaks(void)
{
	system("leaks -quiet cube");
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure of program. */
int main(void)
{
	atexit(ft_leaks);

	
	void *mlx;
	void *mlx_window;
	t_data image;

	mlx = mlx_init(); //genera 3 root leaks at exit. Hay que actualizar a la nueba MLX
	
	mlx_window = mlx_new_window(mlx, OX_WINDOW, OX_WINDOW, TITLE_WINDOW);
	
	image.img = mlx_new_image(mlx, OX_WINDOW, OX_WINDOW);

	image.addr = mlx_get_data_addr\
	(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	for (int i = 500; i < 1915; i++)
		my_mlx_pixel_put(&image, i, 501, get_opposite( trgb_translate(0, 150, 150, 0)));

	mlx_put_image_to_window(mlx, mlx_window, image.img, 0, 0);
	
	mlx_loop(mlx);
	return (0);
}