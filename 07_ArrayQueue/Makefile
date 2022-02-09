CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = arrayqueue

SRCS = main.c arrayqueue.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

