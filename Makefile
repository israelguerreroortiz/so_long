
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

SRC_DIR = ./src
INC_DIR = ./includes

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -I$(INC_DIR) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
