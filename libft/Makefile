# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 16:11:42 by clynderl          #+#    #+#              #
#    Updated: 2020/10/23 15:34:13 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

HDRS = ./includes/ft_printf.h ./includes/libft.h ./includes/get_next_line.h
INCLUDES = -I includes

SRC_DIR = ./srcs/
OBJ_DIR = ./objects/

SRCS = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJECTS = *.o


all: ${NAME}

${NAME}: ${SRCS} ${HDRS}
		@gcc -Wall -Wextra -Werror $(INCLUDES) -c ${SRCS}
		@ar rc ${NAME} ${OBJECTS}
		@ranlib ${NAME}

clean:
		@/bin/rm -f ${OBJECTS}

fclean: clean
		@/bin/rm -f ${NAME}

re: fclean all
