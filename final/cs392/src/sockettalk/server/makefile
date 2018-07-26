NAME= server
OBJS= server.o
CFLAGS=-I../../../include -Wall -Werror --pedantic -L../../../lib -std=c99
LFLAGS= -lmy -llist -lmy -lcurses
CC=gcc 

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o  $(NAME) $(LFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
