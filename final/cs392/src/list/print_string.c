#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "my.h"
void print_string(struct s_node* node){
	if(node){
		if(node->elem){
			my_str((char *)(node->elem));
		}
	}
	return;
}
