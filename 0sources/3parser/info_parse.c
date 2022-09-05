/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/09/05 15:55:51 by guilmira         ###   ########.fr       */
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




int	getinfovisual(char *content, t_prog *game);

int	parselst(t_prog *game, t_list *aux_lst)
{
	int	data_len;
	int	parsered_data;
	int flag;

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

char	*getlimiter(char *limiter);
int		parse_limit(char *limiter);
int		parse_and_storage(char *limiter, t_prog *game, char *content);


int	getinfovisual(char *content, t_prog *game)
{
	char *limiter;

	limiter = getlimiter(content);
	if (ft_strlen(limiter) == 0 || parse_limit(limiter) == 1)
	{
		free(limiter);
		return (0);
	}
	if (parse_and_storage(limiter, game, content) == -1)
	{
		free(limiter);
		return(-1);
	}
	free(limiter);
	return(1);
}

char	*getlimiter(char *limiter)
{
	int i;
	int k;

	i = -1;
	while (ft_isspaces(limiter[++i]) != 0 && limiter[i])
		;
	k = i;
	while (ft_isspaces(limiter[k]) == 0 && limiter[k])
		k++;
	return (ft_substr(limiter, i, k - i));
}

int	parse_limit(char *limiter)
{
	int i;

	i = -1;
	while (limiter[++i])
		if (ft_isspaces(limiter[i]))
			return (1);
	return (0);
}



int	storage_info(char *limiter, t_prog *game, char *content);

int	parse_and_storage(char *limiter, t_prog *game, char *content)
{
	if (!ft_strcmp(limiter, "NO") || !ft_strcmp(limiter, "SO") || !ft_strcmp(limiter, "WE")
		|| !ft_strcmp(limiter, "EA") || !ft_strcmp(limiter, "F") || !ft_strcmp(limiter, "C"))
	{
		if (storage_info(limiter, game, content) != 0)
			return (-1);
	}
	else
	{
		printf("%s\n", limiter);
		return(-1);
	}
	game = (void *)game;
	return(0);
}

char	*cacht_info_str(char *info);
int		catch_number(char *info);

int		storage_info(char *limiter, t_prog *game, char *content)
{
	if (ft_strcmp(limiter, "NO") == 0)
		game->NO = cacht_info_str(content);
	else if (ft_strcmp(limiter, "SO") == 0)
		game->SO = cacht_info_str(content);
	else if (ft_strcmp(limiter, "WE") == 0)
		game->WE = cacht_info_str(content);
	else if (ft_strcmp(limiter, "EA") == 0)
		game->EA = cacht_info_str(content);
	else if (ft_strcmp(limiter, "F") == 0)
		game->floor_clr = catch_number(content);
	else if (ft_strcmp(limiter, "C") == 0)
		game->sky_clr = catch_number(content);
	if (game->floor_clr == -1 || game->sky_clr == -1)
		return (-1);
	return (0);
}

char	*cacht_info_str(char *info)
{
	char *basic_aux;
	int i;
	int k;

	i = 0;
	while (info[i] == ' ' && info[i])
		i++;
	while(info[i] != ' ' && info[i])
		i++;
	while(info[++i] == ' ' && info[i])
		;
	k = i;
	while(info[++k] != ' ' && info[k])
		;
	basic_aux = ft_substr(info, i, i - k);
	return(basic_aux);
}

int check_comas(char *data);
int	check_num(int num);

int		catch_number(char *info)
{
	char *aux;
	char **data_colour;
	int colour;
	int int_aux;
	int i;

	aux = cacht_info_str(info);
	if (check_comas(aux) == -1)
	{
		free (aux);
		return (-1);
	}
	data_colour = ft_calloc(4,  sizeof(char*));
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
	if (!check_num(ft_atoi(data_colour[0])) || !check_num(ft_atoi(data_colour[1])) || !check_num(ft_atoi(data_colour[2])))
	{
		free(aux);
		freemat(data_colour);
		return(-1);
	}
	colour = rgb_t_translate(0, ft_atoi(data_colour[0]), ft_atoi(data_colour[1]), ft_atoi(data_colour[2]));
	freemat(data_colour);
	free(aux);
	return(colour);
}

int check_comas(char *data)
{
	int i;
	int coma;

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

int check_num(int num)
{
	if (num == -1 || num > 255 || num < 0)
		return(0);
	return(-1);
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