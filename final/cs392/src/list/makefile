OBJS=new_node.o add_node.o add_elem.o append.o add_node_at.o remove_node.o remove_last.o remove_node_at.o count_s_nodes.o empty_list.o node_at.o elem_at.o print_int.o print_char.o print_string.o debug_int.o debug_char.o debug_string.o

CFLAGS=-I../../include -Wall -Werror --pedantic

NAME=liblist.a

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
