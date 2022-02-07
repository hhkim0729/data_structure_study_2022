CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = arraylist

SRCS = main.c arraylist.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf $(NAME)

