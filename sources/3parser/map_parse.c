/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/14 17:19:41 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	map_build(int data_len, t_prog *game, t_list *aux_lst)
{
	int	k;
	int	flag;

	k = -1;
	while (++k <= data_len)
		aux_lst = aux_lst->next;
	while (1)
	{
		flag = parse_content(aux_lst->content);
		if (flag == -1)
			return (-1);
		if (flag == 1)
			break ;
		if (aux_lst->next == NULL)
			return (-1);
		aux_lst = aux_lst->next;
	}
	if (getcoords(game, aux_lst) == -1)
		return (-1);
	fill_spaces_map(game, aux_lst);
	if (is_closed(game->map2d.map) == -1)
		return (-1);
	return (0);
}

void	map_refill(t_prog *game, int c, t_list *aux_lst)
{
	int	i;

	i = 1;
	while (i <= game->map2d.map_y)
	{
		game->map2d.map[i] = ft_calloc(sizeof(char), game->map2d.map_x + 3);
		game->map2d.map[i][0] = ' ';
		c = 1;
		while (c <= game->map2d.map_x + 1)
		{
			if (c <= (int)ft_strlen((char *)aux_lst->content))
				game->map2d.map[i][c] = ((char *)aux_lst->content)[c - 1];
			else
				game->map2d.map[i][c] = ' ';
			c++;
		}
		aux_lst = aux_lst->next;
		i++;
	}
}

int	get_maxlen(t_prog *game, t_list *aux_lst)
{
	int	l;
	int	info;

	(void) game;
	l = 0;
	info = 0;
	while (aux_lst)
	{
		l++;
		if (ft_strchr(aux_lst->content, '1'))
			info = l;
		if (aux_lst->next == NULL)
			break ;
		aux_lst = aux_lst->next;
	}
	return (info);
}

int	ret_l(t_list *aux_lst)
{
	int	l;

	l = 0;
	while (((char *)aux_lst->content)[l])
	{
		if (((char *)aux_lst->content)[l] != '1'
			&& ((char *)aux_lst->content)[l] != '0'
			&& ((char *)aux_lst->content)[l] != 'N'
			&& ((char *)aux_lst->content)[l] != 'S'
			&& ((char *)aux_lst->content)[l] != 'E'
			&& ((char *)aux_lst->content)[l] != 'W'
			&& ((char *)aux_lst->content)[l] != ' ')
			return (-1);
		l++;
	}
	return (l);
}
