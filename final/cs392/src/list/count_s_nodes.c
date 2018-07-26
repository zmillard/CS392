 #include <list.h>
int count_s_nodes(struct s_node* head){
	int n = 1;
	struct s_node* temp = malloc(sizeof(struct s_node));
	temp = head;
  if(temp == NULL){
    return 0;
  }
	while(temp->next != NULL){
		temp = temp->next;
		n++;
	}
	return n;
}
