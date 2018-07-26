#include "list.h"
void add_elem(void* elem, struct s_node** head){
	if(elem != NULL){
		struct s_node* node = new_node(elem);
		add_node(node, head);
	}
	return;
}
