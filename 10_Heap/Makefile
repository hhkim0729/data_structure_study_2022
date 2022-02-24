CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = heap

SRCS = main.c heap.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

