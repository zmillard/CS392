#ifndef _LIST_H_
 #define _LIST_H_
 
 #include "my.h"
 

 
 struct s_node {
  void* elem;
  struct s_node* next;
  struct s_node* prev;
 };
 
 /*
  Allocates and returns a node with the given element. You may
  create nodes with NULL element.
 */
 struct s_node* new_node(void* elem);
 
 /*
  Inserts a node at the start of the list You can assume that the provided pointer to 
  head is the actual head of the list, and there are no elements before it. 
  ****DO NOT add a node with a NULL elem or with a NULL head.**** 
  Make sure to check that head!= NULL, and that *head !=NULL
  DOES NOT PARSE THE LIST
 */
 void add_node(struct s_node* node, struct s_node** head);
 
 /*
  Creates a new node with elem and adds it to head (again, assume head is actually the head). DO NOT add a NULL elem to the list
  DOES NOT PARSE THE LIST
 */
 void add_elem(void* elem, struct s_node** head);

 /*
  Adds a node to the end of a list. DO NOT add a NULL node pointer or
  a node with a NULL elem.
  Parse the list once
 */
 void append(struct s_node* node, struct s_node** head);
 
 /*
  Adds a node at index n of a list or at the end of the list if n is 
  too large.
  Parse the list once
 */
 void add_node_at(struct s_node* node, struct s_node** head, int n);
 
 /* 
  Removes the given node from the list. Returns elem and frees the 
  node from memory.
  DOES NOT PARSE THE LIST!!!!!!!!!!!!!!!
 */
 void* remove_node(struct s_node** node);
 
 /*
  Removes the last node from the list.
  Parse Once.
 */
 void* remove_last(struct s_node** head);
 
 /*
  Removes the node at index n or the last node.
  Parse once
 */
 void* remove_node_at(struct s_node** head, int n);
 
 /*
  Returns the value the length of the list
  Parse Once.
 */
 int count_s_nodes(struct s_node* head);
 
 /*
  Frees all the nodes in the list.
  CHALLENGE: Write in two lines (allowed and encouraged to use other methods in 
  this assignment)
 */
 void empty_list(struct s_node** head);
 
 /*
  Returns a pointer to the node at index n or the last node.
  Parse once
 */
 struct s_node* node_at(struct s_node* head, int n);
 
 /*
  Returns a pointer to the elem at index n or the last node.
  Parse once.
 */
 void* elem_at(struct s_node* head, int n);
 
 /*
  Prints the elem of node as a int
 */
 void print_int(struct s_node* node);
 
 /*
  Prints the elem of node as a char
 */
 void print_char(struct s_node* node);
 
 /*
  Prints the elem of node as a string
 */
 void print_string(struct s_node* node);

 /*
  Prints all the elems as ints separated by a space in the format
  (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
 */
 void debug_int(struct s_node* head);
 
 /*
  Prints all the elems as chars separated by a space in the format
  (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
 */
 void debug_char(struct s_node* head);

 /*
  Prints all the elems as strings separated by a space in the format
  (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
 */
 void debug_string(struct s_node* head);

 #endif