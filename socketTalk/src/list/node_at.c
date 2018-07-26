 #include "list.h"
struct s_node* node_at(struct s_node* head, int n){
  if(head == NULL){
    return NULL;
  }
  if (n <= 0){
    return head;
  }
	while(head->next != NULL && n > 1){
		head = head->next;
		n--;
	}
	return head;
}
