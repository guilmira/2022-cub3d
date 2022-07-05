# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 07:28:58 by guilmira          #+#    #+#              #
#    Updated: 2022/07/05 14:49:33 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= cube
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I ./0includes#-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR			= libft_submodule
LIB				= $(LIB_DIR)/libft.a
MLX_DIR			= minilibx_opengl_20191021
MLX				= $(MLX_DIR)/libmlx.a
INCLUDES		= -I./0includes -I./libft_submodule/0includes -Iminilibx_opengl_20191021
FLAGS_MLX		= -framework OpenGL -framework AppKit -L minilibx_opengl_20191021


ROUTE = ./0sources

FOLDER0		= $(addprefix $(ROUTE)/0initialize_program/, main.c init_variables.c)
FOLDER1		= $(addprefix $(ROUTE)/1window_control/, control_window.c)
FOLDER2v	= $(addprefix $(ROUTE)/2image_managment/, color_mod.c image_mod.c)
FOLDER2		= $(addprefix $(ROUTE)/2vector_control/, vectors.c vector_tools.c)
FOLDER3		= $(addprefix $(ROUTE)/3parser/, parser.c)
FOLDER4		= $(addprefix $(ROUTE)/4utiles/, tools.c)
FOLDER5		= $(addprefix $(ROUTE)/5error_managment/, error_management.c)
FOLDER6		= $(addprefix $(ROUTE)/6hooks/, hooks.c)
FOLDER7		= $(addprefix $(ROUTE)/7draw2D/, character.c)


#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	$(FOLDER0)\
				$(FOLDER1)\
				$(FOLDER2)\
				$(FOLDER2v)\
				$(FOLDER3)\
				$(FOLDER4)\
				$(FOLDER5)\
				$(FOLDER6)\
				$(FOLDER7)
OBJS		=	$(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES

#%.o: %.c
#$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#OBJ_DIR = objs/

#SRC_DIR = srcs/



#OBJS = $(addprefix $(PREFIX_DIR), $(OBJ))


#OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

#$(OBJ_DIR)%.o: $(SRC_DIR)%.c
#$(CC) $(CFLAGS) -c $< -o $@


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
	$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)


fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)
	@make clean -C $(MLX_DIR)

#re: fclean all
re: all

norm:
	norminette $(SRCS)

.PHONY: all clean fclean re norm
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'