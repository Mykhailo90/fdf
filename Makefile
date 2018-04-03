NAME = fdf

FLAGS = -c -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

#HEADER = 

LIBFT = libft/libft.a

SRC =  ./src/main.c

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
		@ make -C minilibx_macos/

fclean: clean
		@ /bin/rm -f $(NAME)
		@ make -C libft/ fclean
		@ make -C minilibx_macos/

re: fclean all