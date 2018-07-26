#include <list.h>
void* remove_last(struct s_node** head){
	struct s_node* temp;
	void* tval;
	if(head == NULL || (*head) == NULL){
		return NULL;
	}
	temp = *head;
	tval = (*head)->elem;
	if(count_s_nodes(*head) == 1){
		remove_node(head);
		return tval;
	}
	tval = temp->elem;
	if(temp->next){
		remove_node(head);
		return tval;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	tval = temp->elem;
	temp->prev->next = NULL;
	free(temp->next);
	return tval;
}
