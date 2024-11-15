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
       ft_tolower.c ft_toupper.c ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
       ft_lstiter.c ft_strnstr.c 

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstmap.c \
       ft_lstclear.c ft_lstiter.c 

OBJS = $(SRCS:.c=.o) $(BONUS_SRC:.c=.o)

# Default target, builds the library
all: $(NAME)

# Archive object files to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# bonus files
bonus: all $(BONUS_SRC)

# Clean only object files
clean:
	rm -f $(OBJS)

# Full clean, removes object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: fclean all