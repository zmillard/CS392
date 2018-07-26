#include "list.h"
/*void* remove_node_at(struct s_node** head, int n){
  struct s_node* temp;
  void* tval;
  if(head == NULL || (*head)== NULL){
    return NULL;
  }
  temp = *head;
  tval = temp->elem;
  if((*head)->next == NULL || n <= 0){
    remove_node(head);
    return tval;
  }
  while(temp->next != NULL && n > 0){
    temp = temp->next;
    n--;
  }
  tval = temp->elem;
  if(temp->next ==  NULL){
    temp->prev->next = NULL;
    free(temp);
    return tval;
  }

  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  free(temp);
  return tval;
}*/

void* remove_node_at(struct s_node** head, int n){
    struct s_node* current;
    void* temp;
    if(head == NULL || (*head) == NULL)
    {
        return NULL;
    }
    current=(*head);
    temp = current->elem;
    if(n <= 0 || (*head)->next == NULL)
    {
        remove_node(head);
        return temp;
    }
    
    while(current->next != NULL && n > 0)
    {
        current = current ->next;
        n--;
    }
    temp = current->elem;
    if(current->next == NULL)
    {
        current->prev->next = NULL;
        free(current);
        return temp;
    }
    
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return temp;
}
