# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 07:28:58 by guilmira          #+#    #+#              #
#    Updated: 2022/07/01 15:36:42 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= cube
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR			= libft_submodule
LIB				= $(LIB_DIR)/libft.a
MLX_DIR			= minilibx_opengl_20191021
MLX				= $(MLX_DIR)/libmlx.a
INCLUDES		= -I ./0includes -I ./libft_submodule/0includes -I minilibx_opengl_20191021
FLAGS_MLX	= -framework OpenGL -framework AppKit -L minilibx_opengl_20191021
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	main.c						\
				1init_variables.c			\
				2control_window.c			\
				3color_mod.c 4image_mod.c 	\
				5error_management.c			\
				6hooks.c	\
				8character.c 9tools.c
OBJ		=		$(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

OBJ_DIR = objs/

//SRC_DIR = srcs/

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

//VPATH = 0srcs
all: $(LIB) $(MLX) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(MLX):
	@make -C $(MLX_DIR)

#minilibx_opengl_20191021/libmlx.a -lm -lz  //if having problems, insert this line before the -o
$(NAME): $(OBJS) $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(FLAGS_MLX) $(LIB) $(MLX) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

exe: $(NAME)
	./$(NAME)

#----------------------------------------------------------------------------------------------------CLEANING RULES
RM = rm -rf

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)


fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)

re: fclean all

norm:
	norminette $(SRCS)

.PHONY: all clean fclean re norm
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'