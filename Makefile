#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 12:50:18 by rvolberg          #+#    #+#              #
#    Updated: 2018/04/11 13:21:47 by rvolberg         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

CC = clang

FlAGS = -Wall -Werror -Wextra -g

SRC = 	\
main.c\
check.c\
check_bis.c\
map.c\
image.c\
bonus.c\
geometry_grid.c\
free.c segment.c\
geometry_point.c\
coord.c\
bonus_bis.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./include/

LIBFT_PATH = ./libft/

LIBFT_LINK = -L $(LIBFT_PATH) -lft

LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = /usr/local/

MLX = -I $(MLX_PATH)includes -L $(MLX_PATH)lib/ -lmlx

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

libft_make :
	make -C $(LIBFT_PATH)

$(NAME) : libft_make $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LINK) $(MLX) $(FRAMEWORK)

%.c.o :
	$(CC) $(FLAGS) $(INCLUDE) -o $(SRC) -c $<

.PHONY : clean fclean

clean :
	/bin/rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	/bin/rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all
	make -C $(LIBFT_PATH) re