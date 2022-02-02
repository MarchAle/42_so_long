# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:28:09 by amarchal          #+#    #+#              #
#    Updated: 2022/02/02 12:00:52 by amarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB = ./libft/libft.a

LIBMLX = ./mlx/libmlx.a

SRCS =	./SRCS/so_long.c				\
		./SRCS/get_next_line.c			\
		./SRCS/get_next_line_utils.c	\
		./SRCS/create_map.c				\
		./SRCS/check_map.c				\
		./SRCS/control_map_data.c		\
		./SRCS/map_info.c				\
		./SRCS/init_img.c				\
		./SRCS/game.c					\
		./SRCS/moves.c					\
		./SRCS/change_anim.c			\
		./SRCS/print_map.c				\
		./SRCS/enemies.c

HDRS = 	./so_long.h

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
all: libft minilibx $(NAME)

libft:
	make -C ./libft

minilibx:
	make -C ./mlx

$(NAME): $(OBJS) $(LIBMLX) $(LIB)
		$(CC) $(OBJS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C ./libft
		make clean -C ./mlx

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(LIB)
		rm -rf $(LIBMLX)

re:		fclean all

.PHONY:	all clean fclean re minilibx libft
