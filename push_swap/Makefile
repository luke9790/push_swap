# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmasetti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 11:34:47 by lmasetti          #+#    #+#              #
#    Updated: 2023/02/07 11:34:51 by lmasetti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON = 	./src/common/actions/actions_1.c \
				./src/common/actions/actions_2.c \
				./src/common/actions/actions_3.c \
				./src/common/args.c \
				./src/common/clean.c \
				./src/common/stack.c \
				./src/common/utils/ft_utils_1.c \
				./src/common/utils/ft_utils_2.c \
				./src/common/utils/ft_utils_3.c

SRC_SORTER =	./src/sorter/looper.c \
				./src/sorter/main.c \
				./src/sorter/sorter.c \
				./src/sorter/utils/five_optimize.c \
				./src/sorter/utils/indicizza.c \
				./src/sorter/utils/rotator.c \
				./src/sorter/utils/sorter_utils.c


OBJS_COMMON	= ${SRC_COMMON:.c=.o}
OBJS_SORTER		= ${SRC_SORTER:.c=.o}

INCLUDE = ./src/include

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_COMMON) $(OBJS_SORTER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS_COMMON) $(OBJS_SORTER)

clean:
			${RM} ${OBJS_COMMON} ${OBJS_SORTER}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY:		bonus all clean fclean re
