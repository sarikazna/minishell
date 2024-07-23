# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 16:38:32 by fde-mour          #+#    #+#              #
#    Updated: 2024/07/23 17:33:55 by fde-mour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell
CC 			= cc
CFLAGS    	= -Wall -Wextra -Werror -g
FT_INCLUDE 	= -Ilibft -Llibft -lft -Iinc

LIBFT 		= libft/libft.a
LIBFTP 		= libft/
SRC_DIR		= src/
OBJ_DIR		= obj

UTILS 		= src/utils/checker.c 		\
			  	src/utils/environment.c \
			  	src/utils/prompt.c 		\
			  	src/utils/struct_init.c

MAIN 		= src/main_test.c

SIGNALS		= src/signals/signals.c

BUILTINS 	= src/builtins/pwd/pwd.c \
				src/builtins/env/env.c \
				src/builtins/cd/cd_options.c \
				src/builtins/cd/cd.c \
				src/builtins/export/export.c \
				src/builtins/export/export_utils.c \
				src/builtins/unset/unset.c \
				src/builtins/unset/unset_utils.c \
				src/builtins/echo/echo.c \
				src/builtins/echo/echo_utils.c

SOURCE = $(UTILS) $(SIGNALS) $(BUILTINS) $(MAIN)
		  
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(UTILS) $(SIGNALS) $(BUILTINS) $(MAIN))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(FT_INCLUDE) -lreadline -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re run