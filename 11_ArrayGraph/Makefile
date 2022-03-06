CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = arraygraph

SRCS = main.c arraygraph.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

