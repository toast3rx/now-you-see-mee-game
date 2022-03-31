#ifndef _IO_commands_h_
#define _IO_commands_h_
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"

void add_deck_command(playing_set *set);

void deck_number_command(playing_set *set);

void deck_len_command(playing_set *set, int index);

void shuffle_deck_command(playing_set *set, int index);

void merge_decks_command(playing_set *set, int index1, int index2);

void split_deck_command(playing_set *set, int index, int index_split);

void reverse_deck_command(playing_set *set, int deck_index);

void show_deck_command(playing_set *set, int index);

void show_all_command(playing_set *set);

#endif