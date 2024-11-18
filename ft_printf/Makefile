NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
BONUS_SRC = ft_printf_bonus_utils.c ft_printf_bonus.c
OBJ = $(SRC:.c=.o)
BON_OBJ = $(BONUS_SRC=.c=.0)

# The directory where libft is located
LIBFT_DIR = libft

# Include the libft header files (optional but recommended for convenience)
INCLUDES = -I$(LIBFT_DIR)

# Compile the libft static library
LIBFT = libft/libft.a

# The final executable depends on libft and the main program
$(NAME): $(LIBFT) $(OBJ)
    $(CC) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

# Rule to compile the object files
$(OBJ): $(SRC)
    $(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)

# Rule to create the libft.a library
$(LIBFT):
    $(MAKE) -C $(LIBFT_DIR)

# Clean object files
clean:
    rm -f $(OBJ)
    $(MAKE) -C $(LIBFT_DIR) clean

# Clean everything (including libft)
fclean: clean
    rm -f $(NAME)
    $(MAKE) -C $(LIBFT_DIR) fclean

bonus: $(NAME): $(OBJ) $(BONUS_SRC)
	ar rcs $(NAME) $(INCLUDES) $(OBJ) $(BONUS_SRC)

re: fclean $(NAME)
