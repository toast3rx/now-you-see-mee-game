#ifndef ___DOUBLY_LINKED_LIST_H_
#define ___DOUBLY_LINKED_LIST_H_

typedef struct dll_node_t dll_node_t;
/**
 * @brief Represents a node in the doubly linked list
 */
struct dll_node_t
{
	void *data;
	dll_node_t *prev, *next;
};

/**
 * @brief doubly linked list
 * 	with a pointer to the head of the list
 * 	size of the list
 * 	and data_size of the values that will be stored in a node
 */
typedef struct doubly_linked_list_t doubly_linked_list_t;
struct doubly_linked_list_t
{
	dll_node_t *head;
	unsigned int data_size;
	unsigned int size;
};

/**
 * @brief Creates a node with specified value
 *
 * @param list current doubly linked list
 * @param data value
 * @return dll_node_t* created node
 */
dll_node_t *
node_create(doubly_linked_list_t *list, const void *data);

/**
 * @brief Initialize empty doubly linked list
 *
 * @param data_size of the values
 * @return doubly_linked_list_t* allocated list
 */
doubly_linked_list_t *
dll_create(unsigned int data_size);

/**
 * @brief Return the node at nth position
 *	If n is greater or equal than list size, last node will be returned
 * @param list doubly linked list
 * @param n position
 * @return dll_node_t*
 */
dll_node_t *
dll_get_nth_node(doubly_linked_list_t *list, unsigned int n);

/**
 * @brief Return the total nodes in the list
 *
 * @param list
 * @return unsigned int
 */
unsigned int
dll_get_size(doubly_linked_list_t *list);

/**
 * @brief Free all nodes and the list
 *
 * @param pp_list freed list
 */
void
dll_free(doubly_linked_list_t **pp_list);

/**
 * @brief Add a node to specified index
 *
 * @param list where the node will be added
 * @param n index where the node will be added in the list
 * @param new_data value that will be stored in node
 */
void
dll_add_nth_node(doubly_linked_list_t *list, unsigned int n, const void *new_data);

/**
 * @brief Remove node at specified index
 *
 * @param list from where the node will be removed
 * @param n index of the node that will be removed
 * 	 If n is greater or equal than list size, last node will be removed
 * @return dll_node_t* deleted node or NULL if list is empty
 */
dll_node_t *
dll_remove_nth_node(doubly_linked_list_t *list, unsigned int n);

/**
 * @brief Reverse the list
 *
 * @param list to be reversed
 */
void
dll_reverse(doubly_linked_list_t *list);

/**
 * @brief Sort list using bubble sort algorithm
 * 
 * @param list to be sorted
 * @param cmp function to compare values from two nodes
 */
void
dll_sort(doubly_linked_list_t *list, int (*cmp)(void *, void *));

#endif 