OBJS=my_alpha.o my_char.o my_revstr.o my_str.o my_strlen.o my_int.o my_strindex.o my_strrindex.o my_strcmp.o my_strncmp.o my_strcpy.o my_strncpy.o my_strcat.o my_strdup.o my_strconcat.o my_strnconcat.o my_strfind.o my_strrfind.o my_num_base.o my_atoi.o my_vect2str.o

CFLAGS=-I../../include -Wall -Werror --pedantic

NAME=libmy.a

CC=gcc

all: $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ../../lib/$(NAME) 

re: fclean all