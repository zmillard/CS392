#include "list.h"
void add_node(struct s_node* node, struct s_node** head){
	if(head != NULL && node != NULL){
 		if((*head) && (node->elem) != NULL) {
			node->next = *head;
			(*head)->prev = node;
			(*head) = node;
		}else if(node->elem != NULL){
			(*head) = node;
		}
	}
}
