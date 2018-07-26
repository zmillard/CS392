#include "list.h"
void add_node_at(struct s_node* node, struct s_node** head, int n){
  struct s_node* temp;
  if(head == NULL || node == NULL || node->elem == NULL){
    return;
  }
  temp = *head;
  if(n <= 0 || *head == NULL){
    add_node(node, head);
  } else {
    while(n >= 0){
      if(temp->next == NULL){
        append(node, head);
        return;
      }else{
        if(n == 0){
          temp -> prev -> next = node;
					node -> prev = temp -> prev;
					temp -> prev = node;
					node -> next = temp;
        }
      }
      temp = temp->next;
      n = n-1;
    }
  }
}
