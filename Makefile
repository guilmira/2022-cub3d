# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 07:28:58 by guilmira          #+#    #+#              #
#    Updated: 2022/06/29 18:51:08 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= cube
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-g -fsanitize=address
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR		= libft_submodule
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes
INCLUDES_LIBX	= -lmlx -framework OpenGL -framework AppKit
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	main.c color_mod.c image_mod.c \
				1control_window.c			
OBJ		=		$(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -Imlx -c $< -o $@

OBJ_DIR = objs/

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

VPATH = 0srcs
all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIB) $(INCLUDES_LIBX) -o $(NAME)
	@echo $(GREEN) "$(NAME) compiled" $(NONE)

exe: $(NAME)
	./$(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIB_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_DIR)

re: fclean all

norm:
	norminette $(SRCS)
#pasar solo a carpetas correspondientes

.PHONY: all clean fclean re norm
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'