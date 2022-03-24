#ifndef ___DOUBLY_LINKED_LIST_H_
#define ___DOUBLY_LINKED_LIST_H_

typedef struct dll_node_t dll_node_t;
struct dll_node_t
{
	void *data;
	dll_node_t *prev, *next;
};

typedef struct doubly_linked_list_t doubly_linked_list_t;
struct doubly_linked_list_t
{
	dll_node_t *head;
	unsigned int data_size;
	unsigned int size;
};

dll_node_t *
node_create(doubly_linked_list_t *list, const void *data);

doubly_linked_list_t *
dll_create(unsigned int data_size);

dll_node_t *
dll_get_nth_node(doubly_linked_list_t *list, unsigned int n);

unsigned int
dll_get_size(doubly_linked_list_t *list);

void
dll_free(doubly_linked_list_t **pp_list);

void
dll_print_int_list(doubly_linked_list_t *list);

void
dll_print_string_list(doubly_linked_list_t *list);

void
dll_add_nth_node(doubly_linked_list_t *list, unsigned int n, const void *new_data);

dll_node_t *
dll_remove_nth_node(doubly_linked_list_t *list, unsigned int n);

void
dll_reverse(doubly_linked_list_t *list);

#endif 