# Library name
NAME = libft.a

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
       ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
       ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
       ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
       ft_strmapi.c ft_strncmp.c ft_strrchr.c ft_strtrim.c ft_substr.c \
       ft_tolower.c ft_toupper.c ft_strnstr.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
       ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

# Default target, builds the library
all: $(NAME)

# Archive object files to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Add bonus functionality to the library
bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

# Clean only object files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Full clean, removes object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: fclean all
