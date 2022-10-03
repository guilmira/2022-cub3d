/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/01 13:05:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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


void print_map(char **map, t_prog *game, int **s_map)
{

	(void) map;
	printf("empieza\n");
	for (int j = 0; j < game->map2D.height; j++)
	{
		for (int i = 0; i < game->map2D.width; i++)
			printf("%i ", s_map[j][i]);
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

void log_arrays(t_prog *game)
{
	int i;

	i = -1;
			printf("rayos %i \n" , game->rc->number_of_rays);
			printf("rayos /mitad: %i \n" , game->rc->number_of_rays / 2);

	while (++i < game->rc->number_of_rays + 1)
	{
		if (i % 10 == 0)
			printf("\n");
		printf("%.2f ", game->rc->rc_distance[i]);
	}
		printf("\n");
}