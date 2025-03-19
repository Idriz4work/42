NAME = philosophers
CC = cc
CFLAGS = -g -pthread 
# -fsanitize=thread
# valgrind --tool=drd

SRC = philo/exit_programm.c philo/input_parser.c philo/utils_active.c philo/init_structs.c philo/time.c philo/activities.c philo/philosophers.c philo/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

helgrind: $(NAME)
	valgrind --tool=helgrind --history-level=full ./$(NAME) $(ARGS)

.PHONY: all clean fclean re valgrind helgrind
