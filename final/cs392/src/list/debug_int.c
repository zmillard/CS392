  #include <list.h>

  void debug_int(struct s_node *head)
{
    if (head)
    {
        my_str("(");
        if (head->prev && (head->prev)->elem){
          my_int(*((int *)((head->prev)->elem)));
        }else{
          my_str("NULL");
        }
        my_str(" <- ");
        if (head->elem){
          my_int(*((int *)(head->elem)));
        }else{
          my_str("NULL");
        }
        my_str(" -> ");

        if (head->next){
          my_int(*((int *)((head->next)->elem)));
          my_str("), ");
        }else{
          my_str("NULL)");
        }
        debug_int(head->next);
    }
}


 /*void debug_int(struct s_node* head){
	 int i;
	 int size = count_s_nodes(head);
	 struct s_node* temp = malloc(sizeof(struct s_node));
	 temp = head;
	 for(i = 0; i < size; i++){
		 my_str("(");
		 if(temp->prev != NULL){
			print_int(temp->prev);
		 }else{
			my_str("NULL");
		 }
		 my_str(" <- ");
		 print_int(temp);
		 my_str(" -> ");
		 if(temp->next != NULL){
			print_int(temp->next);
		 }else{
			my_str("NULL");
		 }
		 if(i == size - 1){
			 my_str(")");
		 }else{
			 my_str("), ");
		 }
		 temp = temp->next;
	 }
 }*/
