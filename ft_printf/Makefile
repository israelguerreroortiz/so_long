CC = cc
FLAGS = -Wall -Wextra -Werror
LIBFTPRINTF = ar -rcs
NAME = libftprintf.a
SRCS = ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_str.c ft_print_unsig.c ft_print_ptr.c ft_printf.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(LIBFTPRINTF) $(NAME) $(OBJS)

%o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re