NAME = pipex
CC = cc
CFLAGS = -g #-Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Source files
SRCS = sources/pipex.c sources/pipex_path.c
OBJS = $(SRCS:.c=.o)

# ft_printf settings (contains its own Libft)
FTPRINT_DIR = ft_printf/
FT_PRINTF = $(FTPRINT_DIR)libftprintf.a

# Libft settings
LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)libft.a

# Main archive
$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT)

# Rule to build ft_printf
$(FT_PRINTF):
	$(MAKE) -C $(FTPRINT_DIR)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR) -I$(FTPRINT_DIR) 

# Cleaning rules
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(FTPRINT_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(FTPRINT_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
