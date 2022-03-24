#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

void deck_index_out_of_bounds_exception();

void card_index_out_of_bounds_exception(int index);

void invalid_card_exception();

void invalid_command_exception();

int is_deck_out_of_bounds(playing_set *set, int index);
int is_card_out_of_bounds(deck *curr_deck, int index);

int is_card_valid(int value, char  symbol[]);

#endif