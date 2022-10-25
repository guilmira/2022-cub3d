/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:40:37 by guilmira          #+#    #+#             */
/*   Updated: 2022/07/04 06:30:39 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static inline void	movement_ctrl(t_prog *game)
{
	if (game->pl.key[MLX_KEY_W] == 1)
		update_player_position(key_up, game);
	if (game->pl.key[MLX_KEY_S] == 1)
		update_player_position(key_down, game);
	if (game->pl.key[MLX_KEY_A] == 1)
		update_player_position(2, game);
	if (game->pl.key[MLX_KEY_D] == 1)
		update_player_position(3, game);
	if (game->pl.key[MLX_KEY_LEFT] == 1)
		update_player_vision(key_lookleft, game);
	if (game->pl.key[MLX_KEY_RIGHT] == 1)
		update_player_vision(key_lookright, game);
	if (game->pl.key[MLX_KEY_C] == 1)
		game->pl.fov++;
	if (game->pl.key[MLX_KEY_V] == 1)
		game->pl.fov--;
	if (game->pl.key[MLX_KEY_Z] == 1)
		game->pl.speed += 0.001;
	if (game->pl.key[MLX_KEY_X] == 1 && game->pl.speed > 0)
		game->pl.speed -= 0.001;
	if (game->pl.key[MLX_KEY_UP] == 1)
		game->pl.fast_r = 1;
}



static inline void	send_message(char *colour, char *msg)
{
	printf("%s", colour);
	printf("%s", msg);
	printf("%s", C_NONE);
}

void	welcome_message(t_prog *game)
{
	int		flag;
	char	*line;

	flag = open(READ, O_RDONLY, 0666);
	if (flag == -1)
		ft_shutdown("U cant break our cube. Try again kid\n", game);
	while (get_next_line(flag, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	send_message(C_WHITE, EXECUTION);
	send_message(C_WHITE, INSTR);
	send_message(C_YELLOW, MOVE);
	send_message(C_BLUE, VISION);
	send_message(C_YELLOW, MINI);
	send_message(C_BLUE, FOV);
	send_message(C_RED, WIND);
	send_message(C_WHITE, ESC);
	send_message(C_WHITE, CLOSE);
}

/** PURPOSE : Convert pointer of program and execute frames.
 * 60 FPS. */
void	next_frame(void *g)
{
	t_prog		*game;

	game = (t_prog *) g;
	reset_and_wash_frame(game);
	movement_ctrl(game);
	main_raycast_calculation(FOV_DEGREE + game->pl.fov, game);
	if (game->minimap_state != FULL_MINIMAP)
		put_frame_three_dim(game);
	if (game->minimap_state)
		put_frame_two_dim(game);
	mlx_image_to_window(game->mlx, game->image[CUB_3D], \
	game->w1.origin[0], game->w1.origin[1]);
}

/** PURPOSE : execute main routine of program.
 * mlx_loop and mlx_loop_hook will tried to be executed a total
 * of 60 times pers second. Therefore 60 fps. */
void	hooks_and_loops(t_prog *game)
{
	welcome_message(game);
	mlx_close_hook(game->mlx, &hk_close, (void *) game);
	mlx_key_hook(game->mlx, &hk_keys, game);
	mlx_loop_hook(game->mlx, &next_frame, game);
	mlx_loop(game->mlx);
}
