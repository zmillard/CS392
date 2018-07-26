NAME=libmy.a
CFLAGS=-I../../include -Wall -Werror --pedantic 
#EXEC = newname
CC=gcc
OBJS=my_char.o my_alpha.o my_str.o my_revstr.o my_strlen.o my_int.o my_num_base.o my_strindex.o my_strcmp.o my_strncmp.o my_strcpy.o my_strncpy.o my_strcat.o my_strdup.o my_strconcat.o my_strnconcat.o my_atoi.o my_strrindex.o my_strfind.o my_strrfind.o
#SRC= Lab5.c testMalloc.c 
#LFLAGS =-Llib -lmy

all: $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	mv $(NAME) ../../lib 	
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f ../../lib/$(NAME)
	
re: fclean all
	