# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 03:17:19 by jperrama          #+#    #+#              #
#    Updated: 2022/12/18 20:16:14 by jperrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS		=	so_long.c 				\
				utils.c					\
				check_valid.c			\
				move.c					\
				key.c					\
				get_next_line.c			\
				get_next_line_utils.c	\
				parse_creation_maps.c	\
				free.c					\
				display_map.c

SRCS_DIR	=	sources
		
LINUX_FLAG	=	minilibx-linux/libmlx_Linux.a -I /usr/include -L /usr/lib -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz 

CC			=	clang -MMD -MP

RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror -g3

MLX_DIR		=	minilibx-linux

MLX			=	libmlx_Linux.a

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

OBJ_DEP		=	$(OBJ:%.o=%.d)

OBJ_DIR		=	obj

all:	$(NAME)

$(NAME): $(OBJ) $(MLX_DIR)/$(MLX)
	$(CC) $(OBJ) $(CFLAGS) $(LINUX_FLAG) -o $@

-include $(OBJ_DEP)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< 

$(MLX_DIR)/$(MLX):
	make -C $(@D) all

clean:
	make -C $(MLX_DIR) $@
	$(RM) $(OBJ_DIR)

fclean:	clean
	make -C $(MLX_DIR) $<
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
