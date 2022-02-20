CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = bintree

SRCS = main.c bintree.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

