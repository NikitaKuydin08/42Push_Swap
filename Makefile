# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuydin <nkuydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 23:21:57 by nkuydin           #+#    #+#              #
#    Updated: 2025/11/25 10:18:59 by nkuydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = 42Libft/
OBJ_DIR = objects

HEADERS = -I ${LIBFT_DIR}
SRCS = srcs/operations/push.c \
		srcs/operations/rev_rotate.c \
		srcs/operations/rotate.c \
		srcs/operations/swap.c \
		srcs/main.c \
		srcs/parsing.c \
		srcs/small_sort.c \
		srcs/sort_utils.c \
		srcs/validation.c \
		srcs/large_sort.c

OBJS = $(patsubst srcs/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: libft ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_DIR}/libft.a -o $@

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	@make -C ${LIBFT_DIR}

clean:
	rm -rf ${OBJ_DIR}
	@make -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	@make -C ${LIBFT_DIR} fclean

re: fclean all

test: leaks

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re mlx libft
