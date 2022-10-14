/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanfeli <jsanfeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:37:22 by jsanfeli          #+#    #+#             */
/*   Updated: 2022/10/03 12:50:05 by jsanfeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline mlx_texture_t	*load_png_solid(const char *path, t_prog *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_shutdown("Error. PNG file invalid\n", game);
	return (texture);
}

void	prep_textures(t_prog *game)
{
	mlx_texture_t	*aux;

	game->t_NO = load_png_solid(game->NO, game);
	game->t_SO = load_png_solid(game->SO, game);
	game->t_WE = load_png_solid(game->WE, game);
	game->t_EA = load_png_solid(game->EA, game);
	aux = load_png_solid("wolf/1.png", game);
	game->hands = reescale_texture(aux, 520, 1860);
	mlx_delete_texture(aux);
}

void	destroy_texture(t_prog *game)
{
	if (game->t_NO)
		mlx_delete_texture(game->t_NO);
	if (game->t_SO)
		mlx_delete_texture(game->t_SO);
	if (game->t_WE)
		mlx_delete_texture(game->t_WE);
	if (game->t_EA)
		mlx_delete_texture(game->t_EA);
	if (game->hands)
		mlx_delete_texture(game->hands);
}

mlx_texture_t	*reescale_texture(mlx_texture_t *tex, \
	uint32_t stripeheight, uint32_t stripewitdh)
{
	uint32_t		s[3];
	double			y;
	int				x;
	double 			aux;
	double 			con;
	double			hw[2];
	mlx_texture_t	*ret;

	y = 0;
	x = 0;
	s[0] = 0;
	s[1] = 0;
	aux = 0;
	con = 0.5;
	hw[0] = (double)tex->width / (double)stripewitdh;
	hw[1] = (double)tex->height / (double)stripeheight;
	ret = malloc(sizeof(mlx_texture_t));
	ret->width = stripewitdh;
	ret->height = stripeheight;
	ret->bytes_per_pixel = 4;
	ret->pixels = malloc(sizeof(uint8_t) * (stripewitdh * stripeheight * 4));
	while (s[1] < stripeheight - 1)
	{
		s[2] = 0;
		while (s[2] < stripewitdh - 1)
		{
			ret->pixels[s[0]] = tex->pixels[x * 4 + ((int)y * (tex->width * 4))];
			ret->pixels[s[0] + 1] = tex->pixels[x + 1 + ((int)y * (tex->width * 4))];
			ret->pixels[s[0] + 2] = tex->pixels[x + 2 + ((int)y * (tex->width * 4))];
			ret->pixels[s[0] + 3] = tex->pixels[x + 3 + ((int)y * (tex->width * 4))];
			s[0] += 4;
			s[2] += 1;
			printf("total:%d , X:%d, Y:%f FILLED:%d\n", x + (int)y * (tex->width * 4), x , y , s[0]);
			if (aux >= con)
			{
				con += 1;
				x += 1;
			}
			aux += hw[0];
		}
		y += hw[1];
		s[1] += 1;
	}
	return (ret);
}