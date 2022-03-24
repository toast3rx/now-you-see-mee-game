#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"

playing_set *create_playing_set()
{
	playing_set *set = dll_create(sizeof(deck));
	printf("Playing set created!\n");
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
		printf("\t %d %s\n", card->value, card->symbol);
		curr_node_card = curr_node_card->next;
	}
}
void show_deck_at_index(playing_set *set, int index)
{
	
	printf("Deck %d\n", index);
	deck *curr_deck = (deck *)(dll_get_nth_node(set, index)->data);

	show_deck(curr_deck);
}

void show_all(playing_set *set)
{

	dll_node_t *curr = set->head;
	for (int i = 0; i < (int)set->size; i++) {
		printf("Deck %d\n", i);
		deck *curr_deck = (deck *)(curr->data);

		show_deck(curr_deck);
		curr = curr->next;
		printf("...\n");
	}
}

deck *remove_deck_at(playing_set *set, int index) {
	if (!set->head) {
		printf("Empty List!\n");
		return NULL;
	}
	deck *deleted_deck = (deck *)(dll_remove_nth_node(set, index)->data);
	printf("The deck %d was successfully deleted.\n", index);
	return deleted_deck;
}

dll_node_t *delete_card(playing_set *set, int deck_index, int card_index) {
	deck* deck_at = (deck*)(dll_get_nth_node(set, deck_index)->data);

	dll_node_t *deleted_node = dll_remove_nth_node(deck_at, card_index);
	printf("The card was successfully deleted from deck %d.\n", deck_index);
	return deleted_node;
}

void free_set(playing_set **set) {
	// dll_node_t *curr = (*set)->head;
	// for (int i = 0; i < (int)(*set)->size; i++) {
	// 	dll_node_t *tmp = curr;
	// 	deck *curr_deck = (deck *)(curr->data);
	// 	curr = curr->next;
	// 	dll_free(&curr_deck);
	// 	free(tmp);
	// } 

	dll_node_t *curr;
	while ((*set)->head != NULL) {
		curr = (*set)->head;
		deck *curr_deck = (deck *)(curr->data);
		(*set)->head = (*set)->head->next;
		dll_free(&curr_deck);
		free(curr);

	}
	// dll_node_t *curr1;
	// while ((*set)->head != NULL) {
	// 	curr1 = (*set)->head;
	// 	(*set)->head = (*set)->head->next;
	// 	//free(curr1->data);
	// 	free(curr1);
	// }
	free(*set);
}

void add_cards(playing_set *set, int deck_index, int cards_count) {
	deck* deck_at = (deck *)(dll_get_nth_node(set, deck_index)->data);
	for (int i = 0; i < cards_count; i++) {
		playing_card *new_card = malloc(sizeof(*new_card));
		scanf("%d", &new_card->value);
		scanf("%s", new_card->symbol);
		dll_add_nth_node(deck_at, deck_at->size, (void *)new_card);
		free(new_card);
	}
	printf("The cards were successfully added to deck %d.\n", deck_index);
}

int get_decks_number(playing_set *set) {
	return set->size;
}
int get_deck_len(playing_set *set, int index) {
	deck *curr_deck = (deck *)(dll_get_nth_node(set, index)->data);
	return curr_deck->size;
}