/* Copyright 2022 Mihai Latea copyright */

#ifndef _IO_COMMANDS_h_
#define _IO_COMMANDS_h_
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"

/**
 * @brief Wrapper function for adding a new deck to the playing set
 * 	Reads from stdin cards_number cards and add them to a new deck
 * @param set list where the new deck will be added
 * @param cards_number number of cards to be added
 */
void add_deck_command(playing_set *set, int cards_number);

/**
 * @brief Prints number of decks
 * 
 * @param set list with decks
 */
void deck_number_command(playing_set *set);

/**
 * @brief Print length of a deck of cards at index
 * 
 * @param set list with decks
 * @param index given deck index
 */
void deck_len_command(playing_set *set, int index);

#endif