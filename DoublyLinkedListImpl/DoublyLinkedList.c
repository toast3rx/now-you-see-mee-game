#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

#define MAX_STRING_SIZE 64

/**
 * @brief Creates a node with specified value
 *
 * @param list current doubly linked list
 * @param data value
 * @return dll_node_t* created node
 */
dll_node_t *
node_create(doubly_linked_list_t *list, const void *data)
{
	dll_node_t *node_res = malloc(sizeof(dll_node_t));
	node_res->data = malloc(list->data_size);
	memcpy(node_res->data, data, list->data_size);
	node_res->next = NULL;
	node_res->prev = NULL;

	return node_res;
}

/**
 * @brief Initialize empty doubly linked list
 *
 * @param data_size of the values
 * @return doubly_linked_list_t* allocated list
 */
doubly_linked_list_t *
dll_create(unsigned int data_size)
{
	doubly_linked_list_t *res = malloc(sizeof(doubly_linked_list_t));
	res->data_size = data_size;
	res->head = NULL;
	res->size = 0;
	return res;
}

/**
 * @brief Return the node at nth position
 *
 * @param list doubly linked list
 * @param n position
 * @return dll_node_t*
 */
dll_node_t *
dll_get_nth_node(doubly_linked_list_t *list, unsigned int n)
{
	dll_node_t *curr = list->head;
	while (curr->next != NULL && n-- > 0)
		curr = curr->next;

	return curr;
}

void
dll_add_nth_node(doubly_linked_list_t *list, unsigned int n, const void *new_data)
{
	dll_node_t *new_node = node_create(list, new_data);

	if (list->size == 0) {
		list->head = new_node;
	} else {
		dll_node_t *curr = list->head;
		dll_node_t *prev = NULL;

		while (curr != NULL && n > 0) {
			prev = curr;
			curr = curr->next;
			n--;
		}

		if (prev == NULL) {
			new_node->next = list->head;
			list->head->prev = new_node;
			list->head = new_node;
		} else if (curr == NULL) {
			prev->next = new_node;
			new_node->next = curr;
			new_node->prev = prev;
		} else {
			prev->next = new_node;
			new_node->prev = prev;

			curr->prev = new_node;
			new_node->next = curr;
		}
	}
	list->size++;
}


dll_node_t *
dll_remove_nth_node(doubly_linked_list_t *list, unsigned int n)
{
	dll_node_t *deleted_node;

	if (list->size == 1) {
		deleted_node = list->head;
		list->head = NULL;
	} else if (n == 0) {
		deleted_node = list->head;
		list->head->next->prev = NULL;
		list->head = list->head->next;
	}

	else {
		dll_node_t *curr = list->head;

		while (curr->next != NULL && n-- > 0)
			curr = curr->next;

		deleted_node = curr;

		curr->prev->next = curr->next;
		if (curr->next != NULL)
			curr->next->prev = curr->prev;
	}

	list->size--;
	return deleted_node;

}


unsigned int
dll_get_size(doubly_linked_list_t *list)
{
	return list->size;
}

void
dll_free(doubly_linked_list_t **pp_list)
{
	dll_node_t *curr;
	while((*pp_list)->head != NULL) {
		curr = (*pp_list)->head;
		(*pp_list)->head = (*pp_list)->head->next;
		free(curr->data);
		free(curr);
	}

	free(*pp_list);
}


void
dll_print_int_list(doubly_linked_list_t *list)
{

	if (list->size == 0)
		return;

	dll_node_t *curr = list->head;

	while (curr != NULL) {
		printf("%d ", *(int *)curr->data);
		curr = curr->next;
	}
	printf("\n");
}

void
dll_print_string_list(doubly_linked_list_t *list)
{
	if (list->size == 0)
		return;

	if (list->data_size != MAX_STRING_SIZE)
		return;

	dll_node_t *curr = list->head;
	while (curr != NULL) {
		printf("%s ", (char *)curr->data);
		curr = curr->next;
	}

	printf("\n");

}

void
dll_reverse(doubly_linked_list_t *list)
{
	dll_node_t *curr = list->head;
	dll_node_t *prev = curr->prev;
	for (int i = 0; i < (int)list->size; i++) {
		dll_node_t *tmp = curr->next;
		curr->prev = curr->next;
		curr->next = prev;

		prev = curr;
		curr = tmp;
	}

	list->head = prev;
}

// int main()
// {
// 	doubly_linked_list_t *doublyLinkedList;
// 	int is_int = 0;
// 	int is_string = 0;
// 	while (1) {
// 		char command[16], added_elem[MAX_STRING_SIZE], *end_ptr;
// 		long nr, pos;
// 		scanf("%s", command);
// 		if (strncmp(command, "create_str", 10) == 0) {
// 			doublyLinkedList = dll_create(MAX_STRING_SIZE);
// 			is_string = 1;
// 		}
// 		if (strncmp(command, "create_int", 10) == 0) {
// 			doublyLinkedList = dll_create(sizeof(int));
// 			is_int = 1;
// 		}
// 		if (strncmp(command, "add", 3) == 0) {
// 			scanf("%ld", &pos);

// 			if (is_int) {
// 				scanf("%ld", &nr);
// 				dll_add_nth_node(doublyLinkedList, pos, &nr);
// 			} else if (is_string) {
// 				scanf("%s", added_elem);
// 				dll_add_nth_node(doublyLinkedList, pos, added_elem);
// 			} else {
// 				printf("Create a list before adding elements!\n");
// 				exit(0);
// 			}
// 		}
// 		if (strncmp(command, "remove", 6) == 0) {
// 			if (!is_int && !is_string) {
// 				printf("Create a list before removing elements!\n");
// 				exit(0);
// 			}

// 			scanf("%ld", &pos);
// 			dll_node_t *removed = dll_remove_nth_node(doublyLinkedList, pos);
// 			free(removed->data);
// 			free(removed);
// 		}
// 		if (strncmp(command, "print", 5) == 0) {
// 			if (!is_int && !is_string) {
// 				printf("Create a list before printing!\n");
// 				exit(0);
// 			}

// 			if (is_int == 1) {
// 				//dll_print_ints_right_circular(doublyLinkedList->head);
// 				dll_print_int_list(doublyLinkedList);
// 			}
// 			if (is_string == 1) {
// 				dll_print_string_list(doublyLinkedList);
// 			}
// 		}
// 		if (strncmp(command, "free", 4) == 0) {
// 			if (!is_int && !is_string) {
// 				printf("Create a list before freeing!\n");
// 				exit(0);
// 			}
// 			dll_free(&doublyLinkedList);
// 			break;
// 		}
// 	}
// 	return 0;
// }
