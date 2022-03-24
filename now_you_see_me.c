#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DoublyLinkedListImpl/DoublyLinkedList.h"
#include "DeckUtils/deck.h"
#include "IO_Utils/IO_commands.h"

#define MAX_STRING_SIZE 64

int main(void)
{

	playing_set *my_playing_set = create_playing_set();

	while (1) {
		char command[16];
		int pos;

		scanf("%s", command);
		if (strncmp(command, "ADD_DECK", 8) == 0) {
			add_deck_command(my_playing_set);
		}
		if (strncmp(command, "SHOW_DECK", 9) == 0) {
			scanf("%d", &pos);
			show_deck_at_index(my_playing_set, pos);
		}
		if (strncmp(command, "SHOW_ALL", 8) == 0) {
			show_all(my_playing_set);
		}
		if (strncmp(command, "DEL_DECK", 8) == 0) {
			scanf("%d", &pos);
			
			deck *deleted = (deck *)remove_deck_at(my_playing_set, pos);
			dll_free(&deleted);
		}
		if (strncmp(command, "DEL_CARD", 8) == 0) {
			int card_pos, deck_pos;
			scanf("%d%d", &deck_pos, &card_pos);
			dll_node_t *deleted = delete_card(my_playing_set, deck_pos, card_pos);
			free(deleted->data);
			free(deleted);
		}
		if (strncmp(command, "ADD_CARDS", 9) == 0) {
			scanf("%d", &pos);
			int cards_count;
			scanf("%d", &cards_count);
			add_cards(my_playing_set, pos, cards_count);
		}
		if (strncmp(command, "EXIT", 4) == 0) {
			free_set(&my_playing_set);
			break;
		}

		if (strncmp(command, "DECK_NUMBER", 11) == 0) {
			deck_number_command(my_playing_set);
		}
		if (strncmp(command, "DECK_LEN", 8) == 0) {
			scanf("%d", &pos);
			deck_len_command(my_playing_set, pos);
		}
		if (strncmp(command, "MERGE_DECKS", 11) == 0) {
			int index1, index2;
			scanf("%d%d", &index1, &index2);
			merge_decks(my_playing_set, index1, index2);
		}
		if (strncmp(command, "SHUFFLE_DECK", 12) == 0) {
			scanf("%d", &pos);
			shuffle_deck(my_playing_set, pos);
		}

	}
	return 0;
}