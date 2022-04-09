/* Copyright 2022 Mihai Latea copyright */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DoublyLinkedListImpl/DoublyLinkedList.h"
#include "DeckUtils/deck.h"
#include "IO_Utils/IO_commands.h"
#include "Exceptions/exceptions.h"
#include "Utils/utils.h"
#include "Utils/constants.h"

int main(void)
{
	playing_set *my_playing_set = create_playing_set();
	char *command = (char *)malloc((MAX_STRING_SIZE + 1) * sizeof(char));
	char **args;
	int command_length = 0;

	while (1) {
		if (command_length > 0) {
			for (int i = 0; i < command_length; i++) {
				free(args[i]);
			}
			free(args);
		}
		args = read_command(command, &command_length);
		if (args[0][strlen(args[0]) - 1] == '\n') {
			args[0][strlen(args[0]) - 1] = '\0';
		}

		if (!strcmp(args[0], EXIT_CMD) && command_length == 1) {
			free_set(&my_playing_set);
			break;

		} else if (!strcmp(args[0], ADD_DECK_CMD) && command_length == 2) {
			add_deck_command(my_playing_set, atoi(args[1]));

		} else if (!strcmp(args[0], SHOW_DECK_CMD) && command_length == 2) {
			show_deck_at_index(my_playing_set, atoi(args[1]));

		} else if (!strcmp(args[0], SHOW_ALL_CMD) && command_length == 1) {
			show_all(my_playing_set);

		} else if (!strcmp(args[0], DEL_DECK_CMD) && command_length == 2) {
			int pos = atoi(args[1]);
			dll_node_t *deleted = remove_deck_at(my_playing_set, pos);
			if (deleted) {
				dll_free((deck **)(&deleted->data));
				free(deleted);
				printf("The deck %d was successfully deleted.\n", pos);
			}

		} else if (!strcmp(args[0], DEL_CARD_CMD) && command_length == 3) {
			int deck_pos = atoi(args[1]);
			int card_pos = atoi(args[2]);

			dll_node_t *deleted = delete_card(my_playing_set,
				deck_pos,
				card_pos);
			if (deleted) {
				free(deleted->data);
				free(deleted);
				printf("The card was successfully deleted from deck %d.\n",
					deck_pos);
			}

		} else if (!strcmp(args[0], ADD_CARDS_CMD) && command_length == 3) {
			int deck_pos = atoi(args[1]);
			int cards_count = atoi(args[2]);
			if (add_cards(my_playing_set, deck_pos, cards_count)) {
				printf("The cards were successfully added to deck %d.\n", deck_pos);
			}

		} else if (!strcmp(args[0], DECK_NUMBER_CMD) && command_length == 1) {
			deck_number_command(my_playing_set);

		} else if (!strcmp(args[0], DECK_LEN_CMD) && command_length == 2) {
			int deck_pos = atoi(args[1]);
			deck_len_command(my_playing_set, deck_pos);

		} else if (!strcmp(args[0], MERGE_CMD) && command_length == 3) {
			int index1 = atoi(args[1]);
			int index2 = atoi(args[2]);
			if (merge_decks(my_playing_set, index1, index2)) {
				printf("The deck %d and the deck %d were successfully merged.\n",
					index1, index2);
			}

		} else if (!strcmp(args[0], SHUFFLE_CMD) && command_length == 2) {
			int deck_pos = atoi(args[1]);
			if (shuffle_deck(my_playing_set, deck_pos))
				printf("The deck %d was successfully shuffled.\n", deck_pos);

		} else if (!strcmp(args[0], SPLIT_CMD) && command_length == 3) {
			int deck_pos = atoi(args[1]);
			int index_split = atoi(args[2]);
			if (split_deck(my_playing_set, deck_pos, index_split))
				printf("The deck %d was successfully split by index %d.\n",
					deck_pos, index_split);

		} else if (!strcmp(args[0], REVERSE_CMD) && command_length == 2) {
			int deck_pos = atoi(args[1]);
			if (reverse_deck(my_playing_set, deck_pos))
				printf("The deck %d was successfully reversed.\n", deck_pos);

		} else if (!strcmp(args[0], SORT_CMD) && command_length == 2) {
			int deck_pos = atoi(args[1]);
			if (sort_deck(my_playing_set, deck_pos)) {
				printf("The deck %d was successfully sorted.\n", deck_pos);
			}
		} else {
			invalid_command_exception();
		}
	}

	if (command_length > 0) {
		for (int i = 0; i < command_length; i++) {
			free(args[i]);
		}
	}
	free(args);
	free(command);
	return 0;
}
