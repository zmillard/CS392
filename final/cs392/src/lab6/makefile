NAME=Lab6
CFLAGS=-Werror -std=c99
OBJS=Lab6.o
CC = gcc

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all
	