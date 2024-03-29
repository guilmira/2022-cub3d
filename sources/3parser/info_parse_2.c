/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/01 12:51:40 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*cacht_info_str(char *info)
{
	char	*basic_aux;
	int		i;
	int		k;

	i = 0;
	while (info[i] == ' ' && info[i])
		i++;
	while (info[i] != ' ' && info[i])
		i++;
	while (info[++i] == ' ' && info[i])
		;
	k = i;
	while (info[++k] != ' ' && info[k])
		;
	basic_aux = ft_substr(info, i, i - k);
	return (basic_aux);
}

int	color_check(char	**data_colour)
{
	int	colour;

	if (!check_num(ft_atoi(data_colour[0]))
		|| !check_num(ft_atoi(data_colour[1]))
		|| !check_num(ft_atoi(data_colour[2])))
	{
		freemat(data_colour);
		return (-1);
	}
	colour = rgb_t_translate(ft_atoi(data_colour[0]), ft_atoi(data_colour[1]),
			ft_atoi(data_colour[2]), 255);
	freemat(data_colour);
	return (colour);
}

char	**colour_code_fill(char *aux)
{
	char	**data_colour;
	int		colour;
	int		int_aux;
	int		i;

	data_colour = ft_calloc(4, sizeof(char *));
	colour = 0;
	i = 0;
	int_aux = 0;
	while (i < 3)
	{
		while (aux[colour++] != ',' && aux[colour])
			;
		if (i < 2)
			data_colour[i] = ft_substr(aux, int_aux, (colour - int_aux) - 1);
		else
			data_colour[i] = ft_substr(aux, int_aux, (colour - int_aux));
		i++;
		int_aux = colour;
	}
	free(aux);
	return (data_colour);
}

int	catch_number(char *info)
{
	char	*aux;
	char	**data_colour;

	aux = cacht_info_str(info);
	if (check_comas(aux) == -1)
	{
		free (aux);
		return (-1);
	}
	data_colour = colour_code_fill(aux);
	return (color_check(data_colour));
}
