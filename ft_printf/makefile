
cc = gcc
FLAGS = -Wall -Wextra -Werror
srcs = $(wildcard *.c)
objs = $(SRCS:.c=.o)
TARGET = output

all: $(TARGET)
$(TARGET): $(objs)
	$(cc) $(FLAGS) $(objs) -o $(TARGET)

clean:
	rm -f $(objs)

fclean:
	rm -f $(TARGET)