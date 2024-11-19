NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
BONUS_SRC = ft_printf_bonus_utils.c ft_printf_bonus_fhalf.c ft_printf_bonus_shalf.c
OBJ = $(SRC:.c=.o)
BON_OBJ = $(BONUS_SRC:.c=.o)
LIBFT_DIR = Libft
INCLUDES = -I$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(LIBFT) $(NAME) $(BON_OBJ)
	ar rcs $(NAME) $(BON_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(BON_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re