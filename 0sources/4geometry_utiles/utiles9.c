/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/21 13:47:01 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*To DELETE */

/** PURPOSE : Write coordinates. ONLY WORKS AT FULL WINDOW.
 * EXPECT SEGFAULTS IF USED AT REDUCED MINIMAP SIZE.
*/
void	coor_identifier(mlx_image_t *image, t_prog *game, double coor_x, double coor_y, double window_size)
{
	char *str;
	char *aux;
	int x = (int) coor_x;
	int y = (int) coor(coor_y, window_size);
	char *xs = ft_itoa(x);
	char *ys = ft_itoa(coor_y);

	str = ft_strjoin(xs, ", ");
	aux = ft_strjoin(str, ys);
	free(str);
	free(xs);
	free(ys);
	str = ft_strjoin("(", aux);
	free(aux);
	aux =  ft_strjoin(str, ")");
	free(str);

	mlx_put_string(game->mlx, aux, x, y); //sin offset funciona solo para la ventana general.
	

		solid_pixel(image, x, y, BLACK);
		put_horizontal(coor_y, x - 3, GREEN, game); //esta printeando en la imagen 1, daria seeg fault
	
	free(aux);
}

void log_vector(t_vector v)
{
	printf("VECTOR:			OX %f y  OY %f\n", v.x, v.y);
}

void log_coor(double array[])
{
	printf("Coordinates:						OX %f y  OY %f\n", array[0], array[1]);
}

void log_d(double d)
{
	printf("DOUBLE %f\n", d);
}




void log_beam(t_beam *beam)
{
	printf("BEAM:\n");
	printf("Position, low bound and high bound \n");
	log_coor(beam->position);
	log_coor(beam->position);
	log_coor(beam->position);
	printf("Vision direction, vision ray\n");
	log_vector(beam->vis_dir);
	log_vector(beam->vis);
	printf("Plane left, plane right, plane segment (each unit to divide)\n");
	log_vector(beam->plane_left);
	log_vector(beam->plane_right);
	log_vector(beam->plane_segment);
}



/* 	double time_spent = 0.0;	
	clock_t begin = clock(); */

/* clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("The elapsed time is %f seconds\n", time_spent); */
