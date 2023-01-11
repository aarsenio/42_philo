SRCS	= main.c \
		  utils/data_init.c \
		  utils/structs_call.c \
		  utils/lib.c \
		  utils/threads.c \
		  utils/exit.c \
		  utils/death.c \
		  utils/eat.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread #-g -fsanitize=thread

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

r:
	make re && make clean && clear && ./philo 200 410 200 200

.PHONY: all clean fclean re