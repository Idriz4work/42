NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
