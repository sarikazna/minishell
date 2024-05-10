# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:54:12 by srudman           #+#    #+#              #
#    Updated: 2024/05/10 17:58:39 by filipemfbgo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell
CC 			= cc
CFLAGS    	= -Wall -Wextra -Werror -g -fsanitize=address
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
PATHS		= src/signals/

SRCS 	=  src/utils/checker.c \
		   src/utils/struct_init.c \
		   src/signals/signals.c	\
		   src/utils/environment.c \
		   src/utils/prompt.c \
		   src/main.c

OBJ		=	$(addprefix $(OBJ_DIR)/, $(notdir $(patsubst %.c, %.o, $(SRCS))))

LIBFT = libft/libft.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(FT_INCLUDE) -lreadline -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling ${notdir $<}	in	$(SRC_DIR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PATHU)/%.c
	@echo "Compiling ${notdir $<}	in	$(PATHU)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PATHS)/%.c
	@echo "Compiling ${notdir $<}	in	$(PATHS)"
	@$(CC) $(CFLAGS)  -c $< -o $@

# $(OBJ_DIR)/%.o: $(PATHB)/%.c
# 	@echo "Compiling ${notdir $<}	in	$(PATHB)"
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: $(PATHER)/%.c
# 	@echo "Compiling ${notdir $<}	in	$(PATHER)"
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: $(PATHEX)/%.c
# 	@echo "Compiling ${notdir $<}	in	$(PATHEX)"
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: $(PATHL)/%.cs
# 	@echo "Compiling ${notdir $<}	in	$(PATHL)"
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: $(PATHP)/%.c
# 	@echo "Compiling ${notdir $<}	in	$(PATHP)"
# 	@$(CC) $(CFLAGS) -c $< -o $@


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