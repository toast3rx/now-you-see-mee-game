/* Copyright 2022 Mihai Latea copyright */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyLinkedList.h"

dll_node_t *
node_create(doubly_linked_list_t *list, const void *data)
{
	dll_node_t *node_res = malloc(sizeof(dll_node_t));
	if (!node_res) {
		return NULL;
	}
	node_res->data = malloc(list->data_size);
	if(!node_res->data) {
		free(node_res);
		return NULL;
	}
	memcpy(node_res->data, data, list->data_size);
	node_res->next = NULL;
	node_res->prev = NULL;

	return node_res;
}

doubly_linked_list_t *
dll_create(unsigned int data_size)
{
	doubly_linked_list_t *res = malloc(sizeof(doubly_linked_list_t));
	if (!res) {
		return NULL;
	}
	res->data_size = data_size;
	res->head = NULL;
	res->size = 0;
	return res;
}

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

void dll_sort(doubly_linked_list_t *list, int(*compare)(void *, void *)) {
	int swapped;
	for (unsigned int i = 0; i < list->size - 1; i++) {
		swapped = 0;
		for (unsigned int j = 0; j < list->size - i - 1; j++) {
			dll_node_t *first = dll_get_nth_node(list, j);
			if (compare((void *)first->data, (void *)first->next->data) > 0) {
				void *tmp = first->data;
				first->data = first->next->data;
				first->next->data = tmp;
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
