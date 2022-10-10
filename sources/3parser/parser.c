/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/03 12:27:23 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		ext_err(t_prog *game, char *av);
int		map_prep(t_prog *game);
int		check_data(t_prog *game);

void	parser(t_prog *game, int ac, char **av)
{
	if (ac != 2 || ext_err(game, av[1]) != 0)
		ft_shutdown("Error.\nFailed to aprove data of file\n", game);
	if (map_prep(game))
		ft_shutdown("Error.\nMap parse fail\n", game);
	if (check_data(game))
		ft_shutdown("Error.\nGame data is incorrect\n", game);
}

int	ext_err(t_prog *game, char *av)
{
	int		i;
	char	*aux;

	i = ft_strlen(av) - 1;
	while (av[i] != '.' && av[i])
		i--;
	if (av[i] != '.')
		return (1);
	aux = ft_substr(av, i, ft_strlen(av));
	i = ft_strcmp(aux, ".cub\0");
	free(aux);
	game->file = open(av, O_RDONLY, 0666);
	if (i == 0 && game->file != -1)
		return (0);
	else
		return (1);
}

int	map_prep(t_prog *game)
{
	int		data_len;
	t_list	*aux_lst;

	aux_lst = NULL;
	fill_lst(game, &aux_lst);
	data_len = parselst(game, aux_lst);
	show_info(game);
	if (data_len == -1 || map_build(data_len, game, aux_lst) == -1)
	{
		if (data_len != -1 && game->map2D.map)
			show_map(game);
		ft_lstclear(&aux_lst, free);
		return (1);
	}
	show_map(game);
	ft_lstclear(&aux_lst, free);
	return (0);
}

int	check_data(t_prog *game)
{
	if (access(game->NO, R_OK) != 0)
		return (-1);
	if (access(game->SO, R_OK) != 0)
		return (-1);
	if (access(game->EA, R_OK) != 0)
		return (-1);
	if (access(game->WE, R_OK) != 0)
		return (-1);
	return (0);
}
