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

int map_prep(t_prog *game)
{
	int		data_len;
	t_list	*aux_lst;

	aux_lst = NULL;
	fill_lst(game, &aux_lst);
	printlist(aux_lst);
	data_len = parselst(game, aux_lst);
	if (data_len == -1 || map_build(data_len, game, aux_lst) == -1)
	{
		ft_lstclear(&aux_lst, free);
		return (1);
	}
 	ft_lstclear(&aux_lst, free);
	return (0);
}

