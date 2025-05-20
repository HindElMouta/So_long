# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hind <hinel-mo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 11:07:27 by hinel-mo          #+#    #+#              #
#    Updated: 2025/04/07 11:07:27 by hinel-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -IGet_Next_Line -ILibft -Imlx

SRC = \
	src/main.c \
	src/parser.c \
	src/map_utils.c \
	src/map_parser.c \
	src/path_checker.c \
	src/render.c \
	src/images.c \
	src/player.c \
	src/utils.c \
	Get_Next_Line/get_next_line.c \
	Get_Next_Line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

MLX_DIR = mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
