#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "my.h"
void print_char(struct s_node* node){
	if(node){
		my_char(*(char *)(node->elem));
	}
	return;
}
