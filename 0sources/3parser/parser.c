/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/07/05 14:43:31 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ext_err(t_prog *game, char *av);
int	map_prep(t_prog *game);;

void	parser(t_prog *game, int ac, char **av)
{
	// Basic parse (ac > 1, .cub, perms)
	if (ac != 2 || ext_err(game, av[1]) != 0)
		ft_shutdown("Error: Failed to aprove data of file\n", game);
	// Parse map (check char, filter identificators, map creator)
	if (map_prep(game))
		ft_shutdown("Error: Map parse fail\n", game);
	printf("%s\n", game->NO);
	printf("%s\n", game->SO);
	printf("%s\n", game->WE);
	printf("%s\n", game->EA);
	printf("%d\n", game->floor_clr);
	printf("%d\n", game->sky_clr);
}

int	ext_err(t_prog *game, char *av)
{
	int		i;
	char	*aux;

	i = ft_strlen(av) - 1;
	while(av[i] != '.' && av[i])
		i--;
	if (av[i] != '.')
		return (1);
	aux = ft_substr(av, i, ft_strlen(av));
	i = ft_strcmp(aux, ".cub\0");
	free(aux);
	game->file = open(av, O_RDONLY , 0666);
	if (i == 0 && game->file != -1)
		return (0);
	else
		return (1);
}




void	fill_lst(t_prog *game, t_list **aux_lst);
int		parselst(t_prog *game, t_list *aux_lst);
void	printlist(t_list *list);

int map_prep(t_prog *game)
{
	int		data_len;
	t_list	*aux_lst;

	aux_lst = NULL;
	fill_lst(game, &aux_lst);
	printlist(aux_lst);
	data_len = parselst(game, aux_lst);
	if (data_len == -1)
	{
		ft_lstclear(&aux_lst, free);
		return (1);
	}
 	ft_lstclear(&aux_lst, free);
	return (0);
}

void	fill_lst(t_prog *game, t_list **aux_lst)
{
	char	*aux;

	while (get_next_line(game->file, &aux) == 1)
	{
		ft_lstadd_back(aux_lst, ft_lstnew(ft_strdup(aux)));
		free(aux);
	}
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

	i = 0;
	while (info[i] == ' ' && info[i])
		i++;
	while(info[i] != ' ' && info[i])
		i++;
	while(info[++i] == ' ' && info[i])
		;
	basic_aux = ft_substr(info, i, i - ft_strlen(info));
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
	colour = trgb_translate(0, ft_atoi(data_colour[0]), ft_atoi(data_colour[1]), ft_atoi(data_colour[2]));
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