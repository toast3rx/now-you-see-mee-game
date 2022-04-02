#ifndef _deck_H_
#define _deck_H_
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"

/**
 * @brief Renamed doubly linked list in playing_set and deck
 * 	to make code more readable
 */
typedef doubly_linked_list_t playing_set;
typedef doubly_linked_list_t deck;

/**
 * @brief Structure for a playing card
 * 	that stored a value and a symbol
 */
typedef struct {
	int value;
	char symbol[10];
} playing_card;

/**
 * @brief Create a playing set
 * 	Wrapper function for dll_create
 * 	that creates a doubly linked list with doubly linked lists as a node value
 * @return playing_set* doubly linked list
 */
playing_set* create_playing_set();

/**
 * @brief Create a deck
 * 	Wrapper function for dll_create
 * 	that creates a doubly linked list with playing_card as a node value
 * @return deck* doubly linked list
 */
deck* create_deck();

void add_deck(playing_set* set, deck *new_deck);

dll_node_t* remove_deck_at(playing_set* set, int index);

dll_node_t* delete_card(playing_set *set, int deck_index, int card_index);

int add_cards(playing_set *set, int deck_index, int cards_count);

int get_decks_number(playing_set *set);

int get_deck_len(playing_set *set, int index);

int shuffle_deck(playing_set *set, int index);	

int merge_decks(playing_set *set, int index1, int index2);

int split_deck(playing_set *set, int index, int index_split);

int reverse_deck(playing_set *set, int deck_index);

void show_deck(deck *curr_deck);

void show_deck_at_index(playing_set *set, int index);

void show_all(playing_set *set);

void free_set(playing_set **set);

//TODO: sort_deck

#endif