CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = sorting

SRCS = main.c sorting.c ../08_LinkedDeque/linkeddeque.c ../10_Heap/heap.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)
	rm -rf $(NAME)

