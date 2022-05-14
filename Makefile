# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 07:28:58 by guilmira          #+#    #+#              #
#    Updated: 2022/03/30 11:32:55 by guilmira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------------------------------------COMPILER
NAME		= minishell
CC			= gcc -g
#CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer -g -Ilibreadline/include
CFLAGS		= -Wall -Wextra -Werror -g -Ilibreadline/include
READLINE    = -L${LIB_READLINE}/lib -lreadline_macos_v10_14 -lcurses
#--------------------------------------------------------------------------------------------------------------LIBS
LIB_DIR		= libft_submodule
LIB_READLINE = libreadline
LIB			= $(LIB_DIR)/libft.a
INCLUDES	= -I ./0includes -I ./libft_submodule/0includes -I ./${LIB_READLINE}/include/readline
#--------------------------------------------------------------------------------------------------------------SOURCES
SRCS		=	main.c processes.c builtins.c builtins_2.c ft_str_arr_sort.c \
  				builtin_utils.c utilities.c echo.c cd.c export.c unset.c \
  				exit.c ft_strtok.c \
				execution.c 0files.c 0parser.c \
				0linked_listed.c 0alloc_list.c 1linked_aux.c 2linked_second.c \
				1mid_parent_son.c 1single_process.c 2son.c 3single_son.c 4auxiliar.c 5mgmt.c 6file_creator.c \
				initialization.c reader.c 3error_check.c \
				pre_filter.c pre_filter_simple.c pre_filter_advanced.c pre_filter_aux.c parallel_process.c \
				lexer.c lexer_class.c lexer_list.c  4heredoc_alloc.c \
				quote_mgmt.c quote_split.c quote_auxiliars.c quote_erase.c \
				0command_file.c 1file_aux.c 2file_creator.c \
				0dollar_expansion.c 1expansion_aux.c 2variable.c \
				printstemp.c \
				signals.c ft_multistr_concat.c utilities_2.c heredoc.c builtin_utils_2.c\
				lenvp.c wpipe.c builtin_routine.c memory_mngmt.c forked_processes.c p_process_utilities.c
				
OBJS		=	$(SRCS:.c=.o)
#--------------------------------------------------------------------------------------------------------------RULES
RM = rm -rf
VPATH = include src parser pre_filter file_redirection process parallel_process lexer lexer_quotes lexer_expansion

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(READLINE) $(LIB) -o $(NAME)
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
	norminette ./file_redirection ./include ./lexer ./lexer_expansion ./lexer_quotes \
	 $(LIB_DIR) ./parallel_process ./parser ./pre_filter ./process ./src

.PHONY: all clean fclean re norm
#--------------------------------------------------------------------------------------------------------------FORMAT
NONE='\033[0m'
GREEN='\033[1;32m'