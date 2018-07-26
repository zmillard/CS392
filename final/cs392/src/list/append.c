#include "list.h"
void append(struct s_node* node, struct s_node** head){
	struct s_node* temp;
	if(head != NULL && node != NULL && node->elem != NULL){
		if(*head == NULL){
			node->next = NULL;
			node->prev = NULL;
			*head=node;
		}else{
			temp = *head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = node;
			node->prev = temp;
		}

	}
}
