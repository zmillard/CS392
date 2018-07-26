#include <list.h>
/*void* elem_at(struct s_node* head, int n){
	struct s_node* temp;
	int j = 0;

	if(head == NULL){
		return NULL;
	}
	temp = head;
	while(temp->next != NULL && n != j){
		temp = temp->next;
		j++;
	}
	return temp->elem;
}*/
void* elem_at(struct s_node* head, int n){
    if(head == NULL){
      return NULL;
    }
    if(n <= 0){
      return head->elem;
    }
    while(n){
    	if(head->next != NULL){
	    	head = head->next;
      	n--;
      }else{
				return head->elem;
			}
    }
    return head->elem;
}
