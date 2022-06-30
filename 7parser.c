/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7parser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/06/30 12:07:07 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "0includes/cube.h"

bool	ext_err(t_prog *game, char *av);
bool	map_prep(t_prog *game, char *av);;

void	parser(t_prog *game, int ac, char **av)
{
	// Basic parse (ac > 1, .cub, perms)
	if (ac != 2 || ext_err(game, av[1]))
		ft_shutdown("Error:\nFailed to aprove data of file");
	// Parse map (check char, filter identificators, map creator)
	if (map_prep(game, av[1]))
		ft_shutdown("Error:\nMap parse fail");
}

bool	ext_err(t_prog *game, char *av)
{
	int i;
	char *aux;

	i = ft_strlen(av)
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

t_list *fill_lst(t_prog *game, char *av);

bool map_prep(t_prog *game, char *av)
{
	t_list *aux_lst;

	aux_lst = fill_lst(game, av);
}

t_list *fill_lst(t_prog *game, char *av)
{
	t_list	*tmp;
	char	*aux;

	while (1)
	{
		if (get_next_line(game->file, &aux))
			break;
		ft_lstadd_back(&tmp, aux);
	}
}