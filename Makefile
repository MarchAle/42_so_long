# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:28:09 by amarchal          #+#    #+#              #
#    Updated: 2022/02/02 15:25:58 by amarchal         ###   ########.fr        #
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
		./SRCS/print_map.c				

SRCS_BONUS = 	./SRCS_BONUS/so_long_bonus.c					\
				./SRCS_BONUS/get_next_line_bonus.c				\
				./SRCS_BONUS/get_next_line_utils_bonus.c		\
				./SRCS_BONUS/create_map_bonus.c					\
				./SRCS_BONUS/check_map_bonus.c					\
				./SRCS_BONUS/control_map_data_bonus.c			\
				./SRCS_BONUS/map_info_bonus.c					\
				./SRCS_BONUS/init_img_bonus.c					\
				./SRCS_BONUS/game_bonus.c						\
				./SRCS_BONUS/moves_bonus.c						\
				./SRCS_BONUS/change_anim_bonus.c				\
				./SRCS_BONUS/print_map_bonus.c					\
				./SRCS_BONUS/enemies_bonus.c

HDRS = 	./so_long.h

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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

bonus: libft minilibx $(OBJS_BONUS)
		$(CC) $(OBJS_BONUS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)
		make clean -C ./libft
		make clean -C ./mlx

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(LIB)
		rm -rf $(LIBMLX)

re:		fclean all

.PHONY:	all clean fclean re minilibx libft
