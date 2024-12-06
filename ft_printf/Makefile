NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Source files
SRCS = ft_printf.c \
       ft_printf_utils.c \
	   ft_printf_utils2.c \
       ft_printf_bonus.c \
       ft_printf_bonus_utils.c \
	   zero_padder.c \
	   mindfield_width.c alter_forma.c \
	   plus_sign.c \
	   left_justificator.c \
	#    precission.c  

# Object files
OBJS = $(SRCS:.c=.o)

# Libft settings
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

# Rule to make libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Main archive
$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

bonus: $(LIBFT) $(NAME)

re: fclean all

.PHONY: all clean fclean re