# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 14:58:11 by rmeriau           #+#    #+#              #
#    Updated: 2023/07/03 16:05:48 by rmeriau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

CC := cc -Wall -Wextra -Werror #-g -fsanitize=address
CFLAGS := -I./include
MLX_PATH := ./minilibx_linux

SRCS := src/main.c src/ft_read.c src/ft_utils.c src/ft_draw.c src/ft_colors.c src/ft_projection.c src/ft_free.c

OBJS := $(SRCS:.c=.o)
LIBFT_PATH := ./libft
LIBFT_FLAGS := -L$(LIBFT_PATH) -lft
MLX_FLAGS := -L$(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

DEPS := include/fdf.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re