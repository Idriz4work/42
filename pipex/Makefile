NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

# Source files
SRCS = sources/pipex.c sources/pipex_path.c 
BONUS = sources_bonus/pipex_bonus.c sources_bonus/pipex_path_bonus.c sources_bonus/pipex_heredoc.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

# ft_printf settings (contains its own Libft)
FTPRINT_DIR = includes/ft_printf/
FT_PRINTF = $(FTPRINT_DIR)libftprintf.a

# Libft settings
LIBFT_DIR = includes/Libft/
LIBFT = $(LIBFT_DIR)libft.a

# Main archive
all: $(NAME)

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
	$(CC) $(CFLAGS) -c $< -o $@ -Iincludes -I$(LIBFT_DIR) -I$(FTPRINT_DIR)

# Bonus rule
bonus: $(LIBFT) $(FT_PRINTF) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME)_bonus $(BONUS_OBJS) $(FT_PRINTF) $(LIBFT)

# Cleaning rules
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(FTPRINT_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME)_bonus
	$(MAKE) -C $(FTPRINT_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
