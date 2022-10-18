/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:27:29 by guilmira          #+#    #+#             */
/*   Updated: 2022/10/14 17:17:19 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	log_coor(double array[])
{
	printf("Coordinates:						\
	OX %f y  OY %f\n", array[0], array[1]);
}

void	log_coor_int(int i[])
{
	printf("INT:						\
	OX %i y  OY %i\n", i[0], i[1]);
}
