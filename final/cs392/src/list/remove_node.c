#include "list.h"
void* remove_node(struct s_node** node){
	struct s_node* temp;
	/*my_str("check 1 ");*/
	if(node == NULL || (*node) == NULL){
		return NULL;
	}
	/*my_str("check 2 ");*/
	temp = (*node)->elem;
	if((*node)->next == NULL){
		free((*node));
		(*node) = NULL;
		return temp;
	}
	(*node) = (*node)->next;
	free((*node)->prev);
	(*node)->prev = NULL;
	return temp;
}
