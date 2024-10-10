# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)     # All .c files in the current directory
OBJS = $(SRCS:.c=.o)       # Object files generated from .c files
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
