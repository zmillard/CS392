 #include <list.h>
 #include <my.h>
 void debug_char(struct s_node *head)
{
    if (head)
    {
        my_str("(");
        if (head->prev && (head->prev)->elem){
          my_char(*((char *)((head->prev)->elem)));
        }else{
          my_str("NULL");
        }
        my_str(" <- ");
        if (head->elem){
          my_char(*((char *)(head->elem)));
        }else{
          my_str("NULL");
        }
        my_str(" -> ");

        if (head->next){
            my_char(*((char *)((head->next)->elem)));
            my_str("), ");
        }else{
          my_str("NULL)");
        }
        debug_char(head->next);
    }
}
 /*void debug_char(struct s_node* head){
	 int i;
	 int size = count_s_nodes(head);
	 struct s_node* temp = malloc(sizeof(struct s_node));
	 temp = head;
	 for(i = 0; i < size; i++){
		 my_str("(");
		 if(temp->prev != NULL){
			print_char(temp->prev);
		 }else{
			my_str("NULL");
		 }
		 my_str(" <- ");
		 print_char(temp);
		 my_str(" -> ");
		 if(temp->next != NULL){
			print_char(temp->next);
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
