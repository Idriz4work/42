NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Directories
SRC_DIR = sources
LIBFT_DIR = $(SRC_DIR)/Libft

# Source files
SRC = $(SRC_DIR)/pushswap.c \
      $(SRC_DIR)/rotate_ops.c \
      $(SRC_DIR)/swapy.c

# Object files
OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Include directories
INCLUDES = -I$(LIBFT_DIR)

# Main target
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libraries
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Cleaning rules
clean:
	$(RM) $(OBJ)
	@cd $(LIBFT_DIR) && make clean

fclean:
	$(RM) $(OBJ) $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
