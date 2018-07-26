
OBJS = testlist.o
CFLAGS = -I../include -Wall -Werror -g --pedantic -L../lib
LFLAGS = -lmy -llist -lmy
EXE = test

CC = gcc

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXE) $(LFLAGS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(EXE)
re: fclean all
