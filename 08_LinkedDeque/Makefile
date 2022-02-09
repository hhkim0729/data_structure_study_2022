CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = linkeddeque

SRCS = main.c linkeddeque.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

