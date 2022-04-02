#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_
#include "../DeckUtils/deck.h"
/**
 * @brief Print error message if deck index is out of bounds
 */
void deck_index_out_of_bounds_exception();

/**
 * @brief Print error message if card index is out of bounds
 * 
 * @param index used to print the deck index
 */
void card_index_out_of_bounds_exception(int index);

/**
 * @brief Print error messafe if the card inserted is invalid
 */
void invalid_card_exception();

/**
 * @brief Print error message if the command is invalid
 */
void invalid_command_exception();

/** 
 * @brief Print error message if memory allocation failed
 */
void memory_allocation_exception();

/**
 * @brief Check if the deck at given index is out of bounds
 * 
 * @param set list with deck of cards
 * @param index deck index
 * @return int 1 for true, 0 for false
 */
int is_deck_out_of_bounds(playing_set *set, int index);

/**
 * @brief Check if the card at given index is out of bounds
 * 
 * @param curr_deck list with cards
 * @param index card index
 * @return int 1 for true, 0 for false
 */
int is_card_out_of_bounds(deck *curr_deck, int index);

/**
 * @brief Check if the card inserted is valid
 * 		  Valid cards are: value from 1 to 14, and symbol:
 * 		  1. Diamond, 2. Heart, 3. Club, 4. Spade
 * @param value of the card
 * @param symbol of the card
 * @return int 1 for true, 0 for false
 */
int is_card_valid(int value, char  symbol[]);

#endif