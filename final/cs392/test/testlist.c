#include "my.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	/*Driver code to test the implementation*/
	/*head = NULL; empty list. set head as NULL. */
	struct s_node* head = NULL;
	struct s_node* middle = NULL;
	char* a = "1";
	char* b = "2";
	char* c = "3";
	char* d = "4";
	char* e = "5";
	char* f = "6";

	append(new_node(c), &head);
	debug_string(head);
	my_str("\n");

	remove_node_at(&head, 42);
	debug_string(head);
	my_str("\n");



	add_elem(a, &head);
	add_node(new_node(b), &head);
	add_node_at(new_node(d), &head, 2);
	add_elem(e, &middle);
	debug_string(head);
	my_str("\n");
	add_node_at(middle, &head, 2);
	debug_string(head);
	my_str((char*)elem_at(head, 0));
	my_str("\n");
	append(new_node(f), &head);
	debug_string(head);
	my_str("\n");
	remove_node(&head);
	debug_string(head);
	my_str("\n");
	my_str("remove_node_at\n");
	remove_node_at(&head, 42);
	debug_string(head);
	my_str("\n");
	remove_last(&head);
	debug_string(head);
	my_str("\n");
	my_int(count_s_nodes(head));
	empty_list(NULL);
	debug_string(head);

	return 0;
}
