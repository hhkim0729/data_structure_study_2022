CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = linkedlist

SRCS = main.c linkedlist.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

