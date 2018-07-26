#include <stdlib.h>

struct s_node{
	int data;
	s_node * next;
	s_node * prev;
}

struct s_node * head = malloc(sizeof (struct s_node));

void add_node(s_node* newNode){
	if(head == NULL){
		return 1;
	}
	add_element(s_node, &newNode);
}
void add_elem(struct element, s_node* &h){
	head->prev = &newNode; /*adds to the front of the list*/
	newNode->next = &head;
}