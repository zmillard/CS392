OBJS = main.open
#CFLAGS = -I../../include
#LFLAGS = -L../../lib -lname

#EXEC = newname

#CC = gcc
#CFLAGS = -Wall -Werror --pedantic
NAME = libmy.a
OBJS = my_char.o, my_alpha.o, my_str.o, my_revstr.o, my_strlen.o, my_int.o
#SRC= Lab5.c testMalloc.c 
#LFLAGS =-Llib -lmy

all: $(OBJS)
	#cc -o $(EXEC) $(OBJS) $(LFLAGS)
	#cc *.c $(CFLAGS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	mv $(NAME) ../../lib 	
	
clean:
	rm -f $(OBJS)
	
fclean:
	rm -f ../../lib/$(NAME)
	
re:
	fclean all
	