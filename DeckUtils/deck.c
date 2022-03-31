#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"
#include "../Exceptions/exceptions.h"

playing_set *create_playing_set()
{
	playing_set *set = dll_create(sizeof(deck));
	return set;
}

deck *create_deck()
{
	deck *deck = dll_create(sizeof(playing_card));
	return deck;
}

void add_deck(playing_set *set, deck *new_deck)
{
	dll_add_nth_node(set, set->size, (void *)new_deck);
}

void show_deck(deck *curr_deck)
{
	dll_node_t *curr_node_card = curr_deck->head;
	for (int i = 0; i < (int)curr_deck->size; i++) {
		playing_card *card = (playing_card *)(curr_node_card->data);
		printf("\t%d %s\n", card->value, card->symbol);
		curr_node_card = curr_node_card->next;
	}
}
void show_deck_at_index(playing_set *set, int index)
{

	if (is_deck_out_of_bounds(set, index)) {
		deck_index_out_of_bounds_exception();
		return;
	}

	printf("Deck %d:\n", index);
	deck *curr_deck = (deck *)(dll_get_nth_node(set, index)->data);

	show_deck(curr_deck);
}

void show_all(playing_set *set)
{

	dll_node_t *curr = set->head;
	for (int i = 0; i < (int)set->size; i++) {
		printf("Deck %d:\n", i);
		deck *curr_deck = (deck *)(curr->data);

		show_deck(curr_deck);
		curr = curr->next;
	}
}

dll_node_t *remove_deck_at(playing_set *set, int index)
{

	if (is_deck_out_of_bounds(set, index)) {
		deck_index_out_of_bounds_exception();
		return NULL;
	}

	if (!set->head) {
		printf("Empty List!\n");
		return NULL;
	}

	return dll_remove_nth_node(set, index);
}

dll_node_t *delete_card(playing_set *set, int deck_index, int card_index)
{

	if (is_deck_out_of_bounds(set, deck_index)) {
		deck_index_out_of_bounds_exception();
		return NULL;
	}

	deck *deck_at = (deck *)(dll_get_nth_node(set, deck_index)->data);

	if (is_card_out_of_bounds(deck_at, card_index)) {
		card_index_out_of_bounds_exception(deck_index);
		return NULL;
	}

	dll_node_t *deleted_node = dll_remove_nth_node(deck_at, card_index);

	if (deck_at->size == 0) {
		dll_node_t *deleted_deck = remove_deck_at(set, deck_index);
		dll_free((deck **)(&deleted_deck->data));
		free(deleted_deck);
	}
	return deleted_node;
}

void free_set(playing_set **set)
{
	dll_node_t *curr;
	while ((*set)->head != NULL) {
		curr = (*set)->head;
		deck *curr_deck = (deck *)(curr->data);
		(*set)->head = (*set)->head->next;
		dll_free(&curr_deck);
		free(curr);

	}
	free(*set);
}

int add_cards(playing_set *set, int deck_index, int cards_count)
{

	if (cards_count == 0)
		return 0;

	if (is_deck_out_of_bounds(set, deck_index)) {
		deck_index_out_of_bounds_exception();
		return 0;
	}

	deck *deck_at = (deck *)(dll_get_nth_node(set, deck_index)->data);
	for (int i = 0; i < cards_count; i++) {
		playing_card *new_card = malloc(sizeof(*new_card));
		scanf("%d", &new_card->value);
		scanf("%s", new_card->symbol);
		dll_add_nth_node(deck_at, deck_at->size, (void *)new_card);
		free(new_card);
	}

	return 1;
}

int get_decks_number(playing_set *set)
{
	return set->size;
}
int get_deck_len(playing_set *set, int index)
{
	if (is_deck_out_of_bounds(set, index)) {
		return -1;
	}
	deck *curr_deck = (deck *)(dll_get_nth_node(set, index)->data);
	return curr_deck->size;
}

int merge_decks(playing_set *set, int index1, int index2)
{
	if (is_deck_out_of_bounds(set, index1) || is_deck_out_of_bounds(set, index2)) {
		deck_index_out_of_bounds_exception();
		return 0;
	}

	deck *first_deck = (deck *)(dll_get_nth_node(set, index1)->data);
	deck *second_deck = (deck *)(dll_get_nth_node(set, index2)->data);

	dll_node_t *curr1 = first_deck->head;
	dll_node_t *curr2 = second_deck->head;

	deck *res = create_deck();

	while (curr1 != NULL && curr2 != NULL) {
		dll_add_nth_node(res, res->size, (void *)curr1->data);
		dll_add_nth_node(res, res->size, (void *)curr2->data);
		curr1 = curr1->next;
		curr2 = curr2->next;

	}

	while (curr1 != NULL) {
		dll_add_nth_node(res, res->size, (void *)curr1->data);
		curr1 = curr1->next;
	}

	while (curr2 != NULL) {
		dll_add_nth_node(res, res->size, (void *)curr2->data);
		curr2 = curr2->next;
	}

	if (index1 > index2) {
		int tmp = index1;
		index1 = index2;
		index2 = tmp;
	}
	dll_node_t *deleted1 = remove_deck_at(set, index1);
	dll_node_t *deleted2 = remove_deck_at(set, index2 - 1);
	dll_free((deck **)(&deleted1->data));
	free(deleted1);
	dll_free((deck **)(&deleted2->data));
	free(deleted2);

	add_deck(set, res);
	free(res);
	return 1;
}


int shuffle_deck(playing_set *set, int index)
{
	if (is_deck_out_of_bounds(set, index)) {
		deck_index_out_of_bounds_exception();
		return 0;
	}

	deck *shuffled_deck = (deck *)(dll_get_nth_node(set, index)->data);

	dll_node_t *middle_node = dll_get_nth_node(shuffled_deck, shuffled_deck->size / 2);

	dll_node_t *last_node = dll_get_nth_node(shuffled_deck, shuffled_deck->size - 1);

	last_node->next = shuffled_deck->head;
	shuffled_deck->head->prev = last_node;

	shuffled_deck->head = middle_node;

	middle_node->prev->next = NULL;
	middle_node->prev = NULL;
	return 1;
}

int split_deck(playing_set *set, int index, int index_split)
{


	if (is_deck_out_of_bounds(set, index)) {
		deck_index_out_of_bounds_exception();
		return 0;
	}

	deck *curr_deck = (deck *)(dll_get_nth_node(set, index)->data);

	if (is_card_out_of_bounds(curr_deck, index_split)) {
		card_index_out_of_bounds_exception(index);
		return 0;
	}

	if (index_split == 0 || index_split == (int)curr_deck->size) {
		return 1;
	}

	deck *second_deck = create_deck();

	int count = curr_deck->size - index_split;
	for (int i = 0; i < count; i++) {
		dll_node_t *tmp = dll_remove_nth_node(curr_deck, index_split);
		dll_add_nth_node(second_deck, second_deck->size, (void *)(tmp->data));
		free(tmp->data);
		free(tmp);
	}

	dll_add_nth_node(set, index + 1, (void *)second_deck);
	free(second_deck);
	return 1;
}

int reverse_deck(playing_set *set, int deck_index)
{

	if (is_deck_out_of_bounds(set, deck_index)) {
		deck_index_out_of_bounds_exception();
		return 0;
	}
	deck *curr_deck = (deck *)(dll_get_nth_node(set, deck_index)->data);
	dll_reverse(curr_deck);
	return 1;
}