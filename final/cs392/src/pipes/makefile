NAME=signals
CFLAGS=-Werror
OBJS=signals.o
CC = gcc

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
	