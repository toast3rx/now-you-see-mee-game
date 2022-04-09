/* Copyright 2022 Mihai Latea copyright */

#include "stdio.h"
#include "../DeckUtils/deck.h"
#include "../Utils/constants.h"
#include <string.h>

void deck_index_out_of_bounds_exception()
{
	printf("The provided index is out of bounds for the deck list.\n");
}

void card_index_out_of_bounds_exception(int index)
{
	printf("The provided index is out of bounds for deck %d.\n", index);
}

void invalid_card_exception()
{
	printf("The provided card is not a valid one.\n");
}

void invalid_command_exception()
{
	printf("Invalid command. Please try again.\n");
}

void memory_allocation_exception()
{
	printf("Memory allocation failed.\n");
}

int is_deck_out_of_bounds(playing_set *set, int index) {
	if (index >= (int)set->size || index < 0)
		return 1;
	return 0;
}

int is_card_out_of_bounds(deck *curr_deck, int index) {
	if (index >= (int)curr_deck->size || index < 0)
		return 1;
	return 0;
}

int is_card_valid(int value, char  symbol[]) {
	if (value > CARD_MAX_VALUE || value < CARD_MIN_VALUE)
		return 0;
	if (strcmp(symbol, DIAMOND_SYMBOl) == 0)
		return 1;
	else if(strcmp(symbol, HEART_SYMBOl) == 0)
		return 1;
	else if(strcmp(symbol, CLUB_SYMBOl) == 0)
		return 1;
	else if (strcmp(symbol, SPADE_SYMBOl) == 0)
		return 1;
	else return 0;
}
