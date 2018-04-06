#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/06 17:01:39 by msarapii          #+#    #+#              #
#    Updated: 2018/04/06 17:01:41 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FLAGS = -c -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

SRC =  ./src/main.c ./src/valid.c ./src/drow.c ./src/search_param.c \
		./src/creat_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ make -C libft/
		@ make -C minilibx_macos/
		@ gcc -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

%.o: %.c
	@ gcc $(FLAGS) -o  $@ $<

clean:
		@ /bin/rm -f $(OBJ)
		@ make -C libft/ clean
		@ make -C minilibx_macos/ clean

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean

re: fclean all
