
cc = cc
FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)     
OBJS = $(SRCS:.c=.o)       
TARGET = pipex 

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
