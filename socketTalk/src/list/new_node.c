#include <stdlib.h>
#include "list.h"
struct s_node* new_node(void* elem){
	struct s_node* node = malloc(sizeof(struct s_node));
	node->elem = elem;
	node->next = NULL;
	node->prev = NULL;
	return  node;
}
