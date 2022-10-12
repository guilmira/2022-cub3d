/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:33:17 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/12 13:55:35 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* Senderror message activate: it will show areas of possible
updgrades of the rendering speed.  */

/** PURPOSE : Position corrector.
 * 1. The checker for y == 0, makes sure that we dont print 
 * on the lower limit of the screen. 
 * 2. The checker for size_y - y makes sure we do not go 
 * beyond the upper screen limit. 
 * size_y - y shouldn be repetead several times.*/
double	coor(double y, double size_y)
{
	if (y == 0)
		return (0.001);
	if (size_y - y < 0)
	{
		/* ft_senderror("Invalid 'y' coordinate.\n");
		ft_senderror("If this message appears repetedly, \
		it will slower the rendering.\n");
		printf("Value %f\n", y); */
		return (0);
	}
	return (size_y - y);
}

/** PURPOSE :  Converter.
 * 1. 180 º = π rad */
double	degree_to_radian(double degree)
{
	return (degree * (double) M_PI / 180);
}

int	**copy_double_pointer(int **var, int height, int width)
{
	int		i;
	int		x;
	int		**aux;

	aux = ft_calloc(sizeof(int *), height);
	i = 0;
	while (i < height)
	{
		x = 0;
		aux[i] = ft_calloc(sizeof(int), width);
		while (x < width)
		{
			aux[i][x] = var[i][x];
			x++;
		}
		i++;
	}
	return (aux);
}

void	print_smap(int **s_map, int height, int width)
{
	int		i;
	int		x;

	i = 0;
	printf("height:%d || width:%d\n", height, width);
	while (i < height)
	{
		x = 0;
		printf("| ");
		while (x < width)
		{
			printf("%d ", s_map[i][x]);
			x++;
		}
		printf("|\n");
		i++;
	}
}
