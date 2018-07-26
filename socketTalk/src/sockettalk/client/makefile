NAME= client
OBJS= client.o
CFLAGS=-I../../../include -Wall -Werror --pedantic -L../../../lib
LFLAGS= -lmy -llist -lmy -lcurses
CC=gcc

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o  $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
