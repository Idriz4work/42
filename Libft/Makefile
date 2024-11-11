NAME = libft.a

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
    	ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
       ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c \
       ft_strcmp.c ft_strcpy.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
       ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strtrim.c ft_substr.c \
       ft_tolower.c ft_toupper.c ft_lstclear.c ft_lstdelone.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
	   ft_lstiter.c
OBJS = $(SRCS:.c=.o)       

TARGET = my_program        # Name of the output binary

# Default target, builds the program
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean only object files
clean:
	rm -f $(OBJS)

# Full clean, removes object files and the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project from scratch
re: fclean all
