SRCS	= main.c \
		  utils/data_init.c \
		  utils/structs_call.c \
		  utils/time.c \
		  utils/ft_atoi.c \
		  utils/threads.c \

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread #-g -fsanitize=address

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re