/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/08/03 14:17:37 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		parse_content(char *content);
int		getcoords(t_prog *game, t_list *aux_lst);
void	fill_spaces_map(t_prog *game, t_list *aux_lst);
int		is_closed(char **map);

int map_build(int data_len, t_prog *game, t_list *aux_lst)
{
	int k;
	int flag;

	k = -1;
	while(++k <= data_len)
		aux_lst = aux_lst->next;
	while (1)
	{
		flag = parse_content(aux_lst->content);
		if (flag == -1)
			return (-1);
		if (flag == 1)
			break;
		if (aux_lst->next == NULL)
			return (-1);
		aux_lst = aux_lst->next;
	}
	if (getcoords(game, aux_lst) == -1)
		return (-1);
	fill_spaces_map(game, aux_lst);
	if (is_closed(game->map2D.map) == -1)
		return(-1);
	return (0);
}

int	parse_content(char *content)
{
	int i;

	i = -1;
	while (ft_isspaces(content[++i]) != 0 && content[i])
		;
	if (i == (int)ft_strlen(content))
		return (0);
	else if(content[i] == '1')
		return (1);
	return(-1);
}

void	fill_spaces_map(t_prog *game, t_list *aux_lst)
{
	int i;
	int count;

	i = 1;
	game->map2D.map = ft_calloc(sizeof(char *), game->map2D.map_y + 3);
	game->map2D.map[0] = ft_calloc(sizeof(char), game->map2D.map_x + 3);
	count = -1;
	while (++count <= game->map2D.map_x + 1)
		game->map2D.map[0][count] = ' ';
	while (i <= game->map2D.map_y)
	{
		game->map2D.map[i] = ft_calloc(sizeof(char), game->map2D.map_x + 3);
		game->map2D.map[i][0] = ' ';
		count = 1;
		while (count <= game->map2D.map_x + 1)
		{
			if (count <= (int)ft_strlen((char *)aux_lst->content))
				game->map2D.map[i][count] = ((char *)aux_lst->content)[count - 1];
			else
				game->map2D.map[i][count] = ' ';
			count++;
		}
		aux_lst = aux_lst->next;
		i++;
	}
	game->map2D.map[game->map2D.map_y + 1] = ft_calloc(sizeof(char) , game->map2D.map_x + 3);
	count = -1;
	while (++count <= game->map2D.map_x + 1)
		game->map2D.map[game->map2D.map_y + 1][count] = ' ';
}

int		is_closed(char **map)
{
	int y;
	int x;
	int flag;

	y = 0;
	flag = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == 'S')
				if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
					return (-1);
			if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == 'S')
				flag += 1;
			x++;
		}
		y++;
	}
	if (flag != 1)
		return (-1);
	return (0);
}

int	getcoords(t_prog *game, t_list *aux_lst)
{
	int x;
	int l;
	int y;

	x = 0;
	y = 1;
	while (aux_lst->next)
	{
		l = 0;
		while (((char *)aux_lst->content)[l])
		{
			if (((char *)aux_lst->content)[l] != '1' && ((char *)aux_lst->content)[l] != '0' 
				&& ((char *)aux_lst->content)[l] != 'N' && ((char *)aux_lst->content)[l] != 'S' 
				&& ((char *)aux_lst->content)[l] != 'E' && ((char *)aux_lst->content)[l] != 'W'
				&& ((char *)aux_lst->content)[l] != ' ')
				return (-1);
			l++;
		}
		if (l > x)
			x = l;
		y++;
		aux_lst = aux_lst->next;
	}
	game->map2D.map_x = x;
	game->map2D.map_y = y;
	return (0);
}