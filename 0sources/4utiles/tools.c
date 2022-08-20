/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:33:17 by guilmira          #+#    #+#             */
/*   Updated: 2022/08/20 13:16:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/** PURPOSE : Position corrector.
 * 1. The checker for y == 0, makes sure that we dont print on the lower limit of the screen. 
 * 2. The checker for size_y - y makes sure we do not go beyond the upper screen limit. 
 * size_y - y shouldn be repetead several times.*/
double	coor(double y, double size_y)
{
	if (y == 0)
		return (SAFE_OFFSET);
	if (size_y - y < 0)
	{
		ft_senderror("Invalid 'y' coordinate.\n");
		ft_senderror("If this message appears repetedly, will slower the rendering.\n");
		printf("Value %f\n", y);
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







