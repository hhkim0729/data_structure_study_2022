CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = arraystack

SRCS = main.c arraystack.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

