CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = linkedgraph

SRCS = main.c linkedgraph.c ../02_LinkedList/linkedlist.c ../08_LinkedDeque/linkeddeque.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)
	rm -rf $(NAME)

