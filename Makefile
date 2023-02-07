NAME = push_swap

SRCS = push_swap.c push_swap_outils.c swap.c swap_print.c algo.c algobis.c \
		ft_split.c atoi.c ft_printf.c ft_putchar.c ft_putnbr.c free.c

OBJECT = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g 

$(NAME): $(OBJECT)

		$(CC) -o $(NAME) $(OBJECT) 

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

clean:
		rm -f $(OBJECT)

fclean: clean
		rm -f $(NAME)

re: 	fclean $(NAME)

.PHONY: all clean fclean re bonus 