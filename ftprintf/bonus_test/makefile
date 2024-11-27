CC = cc
CFLAGS = -Wall -g

# List of source files
SRC = alter_forma.c left_justificator.c minfield_width.c precission.c signplus.c zero.c

# List of object files
OBJ = $(SRC:.c=.o)

# Static library
LIBFT = ../libftprintf.a

# Output executable name
EXEC = output

# Default rule to build the executable
$(EXEC): $(OBJ) $(LIBFT) main.o
	$(CC) $(CFLAGS) $(OBJ) main.o $(LIBFT) -o $(EXEC)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJ) main.o $(EXEC)

# Phony targets (make doesn't look for files named 'clean' or 'all')
.PHONY: clean
