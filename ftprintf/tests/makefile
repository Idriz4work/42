# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -g

# Object files
OBJECTS = chartest.o combi.o hexatest.o inttest.o percenttest.o pointertest.o stringtest.o unsigned_test.o

# Static library
LIBFT = ../libftprintf.a

# Output executable name
EXEC = my_program

# Default rule to build the executable
$(EXEC): main.o $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) main.o $(OBJECTS) $(LIBFT) -o $(EXEC)

# Rule to compile main.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJECTS) main.o $(EXEC)

# Phony targets (make doesn't look for files named 'clean' or 'all')
.PHONY: clean
