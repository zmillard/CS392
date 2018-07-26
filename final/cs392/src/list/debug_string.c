  #include "list.h"
 #include <stdio.h>
 #include "my.h"

 void debug_string(struct s_node *head)
 {
     /*struct s_node* current;*/
     if(head == NULL){
       return;
     }
     /*if(count_s_nodes(head) == 1){
        current = head;
        my_str("(NULL <- ");
        my_str((char*)elem_at(current,0));
        my_str(" -> NULL)");
        return;
     }else */if (head){
         my_str("(");
         if (head->prev && (head->prev)->elem){
           my_str((char *)((head->prev)->elem));
         }else{
           my_str("NULL");
         }
         my_str(" <- ");
         if (head->elem){
           my_str(((char *)(head->elem)));
         }else{
           my_str("NULL");
         }
         my_str(" -> ");

         if (head->next){
             my_str(((char *)((head->next)->elem)));
             my_str("), ");
         }else{
           my_str("NULL)");
         }
         debug_string(head->next);
     }
 }

/* void debug_string(struct s_node* head){
	 int i;
	 int size;
	 struct s_node* temp;
   if(head == NULL){
     return;
   }
	 temp = head;
   size = count_s_nodes(head);
	 for(i = 0; i <= size; i++){
		 my_str("(");
		 if(temp->prev->elem != NULL){
			print_string(temp->prev->elem);
		 }else{
			my_str("NULL");
		 }
		 my_str(" <- ");
		 print_string(temp);
		 my_str(" -> ");
		 if(temp->next->elem != NULL){
			print_string(temp->next->elem);
		 }else{
			my_str("NULL");
		 }
		 if(i == size - 1 ){
			 my_str(")");
		 }else{
			 my_str("), ");
		 }
		 temp = temp->next;
	 }
 }*/
