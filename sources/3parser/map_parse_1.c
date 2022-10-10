/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/08/11 14:49:15 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	parse_content(char *content)
{
	int	i;

	i = -1;
	while (ft_isspaces(content[++i]) != 0 && content[i])
		;
	if (i == (int)ft_strlen(content))
		return (0);
	else if (content[i] == '1')
		return (1);
	return (-1);
}

int	getcoords(t_prog *game, t_list *aux_lst)
{
	int	x;
	int	l;

	x = 0;
	game->map2D.map_y = get_maxlen(game, aux_lst);
	while (1)
	{
		l = ret_l(aux_lst);
		if (l > x)
			x = l;
		if (!aux_lst->next)
			break ;
		aux_lst = aux_lst->next;
	}
	game->map2D.map_x = x;
	return (0);
}

void	fill_spaces_map(t_prog *game, t_list *aux_lst)
{
	int	c;

	game->map2D.map = ft_calloc(sizeof(char *), game->map2D.map_y + 3);
	game->map2D.map[0] = ft_calloc(sizeof(char), game->map2D.map_x + 3);
	c = -1;
	while (++c <= game->map2D.map_x + 1)
		game->map2D.map[0][c] = ' ';
	map_refill(game, c, aux_lst);
	game->map2D.map[game->map2D.map_y + 1] = ft_calloc(sizeof(char),
			game->map2D.map_x + 3);
	c = -1;
	while (++c <= game->map2D.map_x + 1)
		game->map2D.map[game->map2D.map_y + 1][c] = ' ';
}

int	is_closed(char **map)
{
	int	y;
	int	x;
	int	flag;

	y = -1;
	flag = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'W'
				|| map[y][x] == 'E' || map[y][x] == 'S')
				if (map[y][x - 1] == ' ' || map[y][x + 1] == ' '
					|| map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
					return (-1);
			if (map[y][x] == 'N' || map[y][x] == 'W'
				|| map[y][x] == 'E' || map[y][x] == 'S')
				flag += 1;
			x++;
		}
	}
	if (flag != 1)
		return (-1);
	return (0);
}
