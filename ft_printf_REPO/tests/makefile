CC = gcc

# Paths to include headers and libraries
INCLUDES = -I. -I../libft -I../ft_printf

# Source files
SRCS = main.c chartest.c combi.c hexatest.c inttest.c percenttest.c pointertest.c stringtest.c unsigned_test.c

# Object files
OBJ = $(SRCS:.c=.o)

# Library files
LIBFT = ../Libft/libft.a
FT_PRINTF = ../libftprintf.a

# Output program name
NAME = test_program

# Rule to compile the program
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# Clean object files
clean:
	rm -f $(OBJ)

# Remove everything (executable and object files)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean $(NAME)
