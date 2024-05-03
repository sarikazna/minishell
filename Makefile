# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srudman <srudman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:54:12 by srudman           #+#    #+#              #
#    Updated: 2024/05/03 17:54:15 by srudman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell
CC 			= cc
CFLAGS    	= -Wall -Wextra -Werror -g
FT_INCLUDE 	= -Ilibft -Llibft -lft

LIBFTP 		= libft/
SRC_DIR		= src/
OBJ_DIR		= objs
PATHB		= src/builtins/
PATHER		= src/error/
PATHEX		= src/executor/
PATHL		= src/lexer/
PATHP		= src/parser/
PATHU		= src/utils/

SRCS 	=  src/main.c

OBJ		=	$(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))

LIBFT = libft/libft.a

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling ${notdir $<}	in	$(SRC_DIR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PATHU)/%.c
	@echo "Compiling ${notdir $<}	in	$(PATHU)"
	@$(CC) $(CFLAGS) -c $< -o $@

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