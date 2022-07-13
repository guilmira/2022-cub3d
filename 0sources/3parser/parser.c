/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:47:56 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/07/08 13:39:57 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int		ext_err(t_prog *game, char *av);
int		map_prep(t_prog *game);
void	show_map(t_prog *game);
void	show_info(t_prog *game);
int		check_data(t_prog *game);

void	parser(t_prog *game, int ac, char **av)
{
	// Basic parse (ac > 1, .cub, perms)
	if (ac != 2 || ext_err(game, av[1]) != 0)
		ft_shutdown("Error: Failed to aprove data of file\n", game);
	// Parse map (check char, filter identificators, map creator)
	if (map_prep(game))
		ft_shutdown("Error: Map parse fail\n", game);
	/*if (check_data(game))
		ft_shutdown("Error: Game data is incorrect\n", game);*/
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
	data_len = parselst(game, aux_lst);
	show_info(game);
	if (data_len == -1 || map_build(data_len, game, aux_lst) == -1)
	{
		if (data_len != -1)
			show_map(game);
		ft_lstclear(&aux_lst, free);
		return (1);
	}
	show_map(game);
 	ft_lstclear(&aux_lst, free);
	return (0);
}

void	show_info(t_prog *game)
{	
	if(game->NO)
		printf("North texture: %s\n", game->NO);
	else
		printf("North texture: Not Parsed\n");
	if(game->SO)
		printf("South texture: %s\n", game->SO);
	else
		printf("South texture: Not Parsed\n");
	if(game->EA)
		printf("East texture: %s\n", game->EA);
	else
		printf("East texture: Not Parsed\n");
	if(game->WE)
		printf("West texture: %s\n", game->WE);
	else
		printf("West texture: Not Parsed\n");
	if(game->sky_clr != -1)
		printf("Sky colour: %d\n", game->sky_clr);
	else
		printf("Sky colour: ERROR\n");
	if(game->floor_clr != -1)
		printf("Floor colour: %d\n", game->floor_clr);
	else
		printf("Floor colour: ERROR\n");
	printf("\n");
}

void	show_map(t_prog *game)
{
	int i;

	i = -1;
	while(++i < game->map_x + 4)
		write(0, "-", 1);
	write(0, "\n", 1);
	i = -1;
	while (++i < game->map_y + 1)
		printf("(%s)\n", game->map[i]);
	i = -1;
	while(++i < game->map_x + 4)
		write(0, "-", 1);
	write(0, "\n", 1);
}

int		check_data(t_prog *game)
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

