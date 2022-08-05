# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 07:28:58 by guilmira          #+#    #+#              #
#    Updated: 2022/08/05 12:05:58 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= cube
CC			= gcc
CFLAGS		= -Wall -Wextra  -Werror   -O3 #-fsanitize=address   #-g
ARG			= easy_map2.cub
#ARG			= default.cub

#time ./cube default.cub
# 8.64 real         7.62 user         0.93 sys   reseteando each frame
#--------------------------------------------------------------------------------------------------------------LIBS
HEADER			= -I ./0includes
LIB_DIR			= libft_submodule
LIB				= $(LIB_DIR)/libft.a
MLX_DIR			= ./MLX42
MLX				= $(MLX_DIR)/libmlx42.a
INCLUDES		= -I ./libft_submodule/0includes -I ./MLX42/include/MLX42
FLAGS_MLX		= -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
#--------------------------------------------------------------------------------------------------------------FILES
ROUTE 		= ./0sources
FOLDER0		= $(addprefix $(ROUTE)/0initialize_program/,	main.c init_map2D.c init_variables.c init_dimensions.c)
FOLDER1		= $(addprefix $(ROUTE)/1window_control/,		control_window.c)
FOLDER2v	= $(addprefix $(ROUTE)/2frameworks/,			color_mod.c main_framework.c minimap_framework.c)
FOLDER2		= $(addprefix $(ROUTE)/2vector_control/,		vectors.c  vector_tools.c vector_arithmetic.c vector_arith_advanced.c ray_cast.c ray_collision.c ray_collision2.c)
FOLDER3		= $(addprefix $(ROUTE)/3parser/,				parser.c info_parse.c map_parse.c)
FOLDER4		= $(addprefix $(ROUTE)/4utiles/,				tools.c )
FOLDER4v	= $(addprefix $(ROUTE)/4geometry_utiles/,		utiles.c utiles_line.c utiles9.c )
FOLDER5		= $(addprefix $(ROUTE)/5error_managment/,		error_tools.c error_management.c)
FOLDER6		= $(addprefix $(ROUTE)/6hooks/,					movement.c vison_control.c hook_keys.c hooks.c)
FOLDER7		= $(addprefix $(ROUTE)/7draw2D/,				2D_frame_exe.c 2D_vision_beam.c 2D_vision_planes.c frame_player_position.c character_intital.c init_beam.c)
FOLDER8		= $(addprefix $(ROUTE)/8draw3D/,				3D_frame_exe.c)
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	$(FOLDER0)\
				$(FOLDER1)\
				$(FOLDER2)\
				$(FOLDER2v)\
				$(FOLDER3)\
				$(FOLDER4)\
				$(FOLDER4v)\
				$(FOLDER5)\
				$(FOLDER6)\
				$(FOLDER7)\
				$(FOLDER8)
OBJS		=	$(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
all: $(LIB) $(MLX) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./MLX42/include/MLX42 $(HEADER) -c $< -o $@

#Create a main.c file, include MLX42/MLX42.h, compile with -ldl -lglfw , make sure to also do -I <include_path>.

linux: $(OBJS) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -ldl -lglfw $(LIB) $(MLX) -o $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(FLAGS_MLX) $(LIB) $(MLX) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

exe: $(NAME)
	time ./$(NAME) $(ARG)

fus:
	$(RM) $(OBJS)
redo: fus exe
#----------------------------------------------------------------------------------------------------CLEANING RULES
RM = rm -rf

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)


fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(MLX_DIR)

re: fclean all

norm:
	norminette $(SRCS)

.PHONY: all clean fclean re norm
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'