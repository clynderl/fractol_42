# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 12:56:20 by clynderl          #+#    #+#              #
#    Updated: 2020/11/05 12:59:06 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		=	burningship.c \
			fractol.c \
			hook.c \
			julia.c \
			mandelbrot.c \
			tools.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MLX		= ./minilibx_macos/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./minilibx_macos
MLX_LNK	= -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/
H_FILE 	= $(addprefix $(INCDIR), fractol.h)

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@echo "\033[32m✅$(NAME): $(OBJECTS_DIR)directory was created✅\033[0m"

$(OBJDIR)%.o:$(SRCDIR)%.c $(H_FILE)
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo "\033[32m🍏\c \033[0m"

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@echo "\033[32m\n✅$(NAME): was created✅\033[0m"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@make -C $(MLX) clean

re: fclean all
