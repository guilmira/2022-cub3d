/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/01 12:51:40 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	fill_lst(t_prog *game, t_list **aux_lst)
{
	char	*aux;

	while (get_next_line(game->file, &aux) == 1)
	{
		ft_lstadd_back(aux_lst, ft_lstnew(ft_strdup(aux)));
		free(aux);
	}
	ft_lstadd_back(aux_lst, ft_lstnew(ft_strdup(aux)));
	if (aux)
		free(aux);
}

int	parselst(t_prog *game, t_list *aux_lst)
{
	int	data_len;
	int	parsered_data;
	int	flag;

	parsered_data = 0;
	data_len = 0;
	while (parsered_data < 6)
	{
		flag = getinfovisual((char *)aux_lst->content, game);
		if (flag == -1)
		{
			data_len = -1;
			break ;
		}
		else if (flag == 1)
			parsered_data += 1;
		data_len += 1;
		if (aux_lst->next == NULL)
			break ;
		aux_lst = aux_lst->next;
	}
	if (parsered_data != 6)
		data_len = -1;
	return (data_len);
}

int	check_comas(char *data)
{
	int	i;
	int	coma;

	i = -1;
	coma = 0;
	while (data[++i])
	{
		if (ft_isdigit(data[i]) != 1 && data[i] != ',')
			return (-1);
		if (data[i] == ',')
			coma++;
	}
	if (coma != 2)
		return (-1);
	return (0);
}

int	check_num(int num)
{
	if (num == -1 || num > 255 || num < 0)
		return (0);
	return (-1);
}

void	printlist(t_list *list)
{
	int	i;
	int	j;

	i = 0;
	j = ft_lstsize(list);
	if (j == 0)
		return ;
	while (i < j)
	{
		ft_putstr_fd((char *)list->content, 0);
		ft_putchar_fd('\n', 0);
		list = list->next;
		i++;
	}
}
