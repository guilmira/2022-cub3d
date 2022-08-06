/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/06 09:21:21 by guilmira         ###   ########.fr       */
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

void log_coor_int(int i[])
{
		printf("INT:						OX %i y  OY %i\n", i[0], i[1]);

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


void print_map(char **map, t_prog *game)
{

	(void) map;
	printf("empieza\n");
	for (int j = 0; j < game->map2D.height; j++)
	{
		for (int i = 0; i < game->map2D.width; i++)
			printf("%i ", game->map2D.layout[j][i]);
		
		printf("\n");
	}
	printf("altura %i\n", game->map2D.height);
	printf("anchura %i\n", game->map2D.width);
}


/* Just for testing */
void insta_player_vision(t_prog *game)
{
	t_vector	plane_perpendicular;
	t_vector	new_vision;
	double		speed_multiplier;

	speed_multiplier = 30;
	if (game->pl.flag_trance)
		speed_multiplier = TRANCE_BOOST * 5;
	plane_perpendicular = get_unit_vector(get_perpendicular(game->pl.vis));
	plane_perpendicular = mul_vec(plane_perpendicular, speed_multiplier);
	
	new_vision = get_unit_vector(sum_vec(game->pl.beam.vis, invert_sense_vector(plane_perpendicular)));

	game->pl.vis = new_vision;
}