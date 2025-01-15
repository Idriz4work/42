NAME = fdf

# Source files
SRCS = sources/FdF.c sources/FdF_utils.c
OBJS = $(SRCS:.c=.o)

# Compiler and flags
CC = cc
CFLAGS =  -g

# Include paths
INCLUDES = -I./includes/Libft -I./includes/ft_printf -I./provided_sources/minilibx-linux

# Libraries paths
LIBFT_DIR = includes/Libft
PRINTF_DIR = includes/ft_printf
MLX_DIR = provided_sources/minilibx-linux

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# Linux-specific flags for MLX
MLX_FLAGS = -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(OBJS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re