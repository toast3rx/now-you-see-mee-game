#ifndef _deck_H_
#define _deck_H_
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"

typedef doubly_linked_list_t playing_set;
typedef doubly_linked_list_t deck;

typedef struct {
	int value;
	char symbol[10];
} playing_card;

// deck
// node* head
// 

playing_set* create_playing_set();

deck* create_deck();


// Methods //


void add_deck(playing_set* set, deck *new_deck);

deck* remove_deck_at(playing_set* set, int index);
dll_node_t* delete_card(playing_set *set, int deck_index, int card_index);
void add_cards(playing_set *set, int deck_index, int cards_count);
int get_decks_number(playing_set *set);
int get_deck_len(playing_set *set, int index);
// shuffle deck
// merge decks
void merge_decks(playing_set *set, int index1, int index2);
// split deck
// reverse deck
void show_deck(deck *curr_deck);
void show_deck_at_index(playing_set *set, int index);
void show_all(playing_set *set);
void free_set(playing_set **set);

#endif