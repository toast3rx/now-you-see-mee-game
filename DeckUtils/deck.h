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

/**
 * @brief Add a new deck to a playing set list
 * 	Wrapping function for dll_add_nth_node
 * @param set dll list to add to
 * @param new_deck list to be added
 */
void add_deck(playing_set* set, deck *new_deck);

/**
 * @brief Delete a deck at a given index
 *	Wrapper function for dll_delete_nth_node 
 * @param set list from which to delete
 * @param index where to delete
 * @return dll_node_t* delted node
 */
dll_node_t* remove_deck_at(playing_set* set, int index);

/**
 * @brief Delete a card from a deck at a given index
 * 
 * @param set list with all decks
 * @param deck_index index of the deck to delete from
 * @param card_index index of the card to delete
 * @return dll_node_t* deleteed node with playing_card as value
 */
dll_node_t* delete_card(playing_set *set, int deck_index, int card_index);

/**
 * @brief Add cards to an existing deck
 * 
 * @param set list of decks
 * @param deck_index index of the deck to add to
 * @param cards_count number of cards to add
 * @return int 1 if successful, 0 if not
 */
int add_cards(playing_set *set, int deck_index, int cards_count);

/**
 * @brief Get the number of decks in a set
 * 	Wrapper function for dll_get_size
 * @param set list of decks
 * @return int number of decks
 */
int get_decks_number(playing_set *set);

/**
 * @brief Get the number of cards in a deck
 * 
 * @param set list of decks
 * @param index deck index
 * @return int number of cards
 */
int get_deck_len(playing_set *set, int index);

/**
 * @brief Reverse first and second half of a deck
 * 
 * @param set list of decks
 * @param index deck index
 * @return int 1 if successful, 0 if not
 */
int shuffle_deck(playing_set *set, int index);	

/**
 * @brief Merge to decks into a new deck
 * 	and delete the two decks
 * adding the new deck to the set
 * @param set list of decks
 * @param index1 first deck index
 * @param index2 second deck index
 * @return int 1 if successful, 0 if not
 */
int merge_decks(playing_set *set, int index1, int index2);

/**
 * @brief Split a deck into two decks at a given index
 * 
 * @param set list of decks
 * @param index deck index
 * @param index_split card index to split at
 * @return int  1 if successful, 0 if not
 */
int split_deck(playing_set *set, int index, int index_split);

/**
 * @brief Reverse cards order in a deck
 * 
 * @param set list of decks
 * @param deck_index deck index
 * @return int 1 if successful, 0 if not
 */
int reverse_deck(playing_set *set, int deck_index);

/**
 * @brief Print cards from a given deck
 * 
 * @param curr_deck deck to print
 */
void show_deck(deck *curr_deck);

/**
 * @brief Print cards from a deck
 * 	at a given index
 * 
 * @param set list of decks
 * @param index deck index
 */
void show_deck_at_index(playing_set *set, int index);

/**
 * @brief Print all decks in a set
 * 
 * @param set list of decks
 */
void show_all(playing_set *set);

/**
 * @brief free all decks in a set
 * 	all cards in the decks are freed
 * 	and the set itself
 * 
 * @param set list of decks
 */
void free_set(playing_set **set);

/**
 * @brief Convert a card symbol to a value
 * 	based on card's priority:
 * 	1. Hearts, 2. Diamonds, 3. Spades, 4. Clubs
 * 
 * @param symbol card symbol
 * @return int 
 */
int symbol_to_value(char *symbol);

/**
 * @brief Function that compares two cards
 * 	If the value is the same, the symbol is compared
 *  Priority of the symbol is:
 * 		1. Hearts, 2. Diamonds, 3. Spades, 4. Clubs
 * 
 * @param card1 first card
 * @param card2 second card
 * @return int 1 if card1 > card2, 1 if card1 < card2, 0 if equal
 */
int compare_cards(void *card1, void *card2);

/**
 * @brief Sort a deck using bubble sort at a given index
 * 
 * @param set list of decks
 * @param deck_index 
 * @return int 1 if successful, 0 if not
 */
int sort_deck(playing_set *set, int deck_index);
#endif