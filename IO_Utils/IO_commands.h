#ifndef _IO_commands_h_
#define _IO_commands_h_
#include "../DoublyLinkedListImpl/DoublyLinkedList.h"

void add_deck_command(playing_set *set);

void deck_number_command(playing_set *set);

void deck_len_command(playing_set *set, int index);
#endif