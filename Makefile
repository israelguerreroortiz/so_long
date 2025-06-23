
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

LIBFT = ./libft
LIBFT_LIB = $(LIBFT)/libft.a

PRINTF = ./ft_printf
PRINTF_LIB = $(PRINTF)/libftprintf.a

SRC_DIR = ./src
INC_DIR = ./includes

SRC = $(SRC_DIR)/main.c \
		$(SRC_DIR)/flood_fill.c \
		$(SRC_DIR)/map_elements.c \
		$(SRC_DIR)/move_player.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/parse_map.c \
		$(SRC_DIR)/parse_map_aux.c
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF)

$(NAME): $(MLX_LIB) $(OBJ) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_LIB) $(PRINTF_LIB) -I$(INC_DIR) -lm -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(PRINTF) clean
	make -C $(LIBFT) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(PRINTF) fclean
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
