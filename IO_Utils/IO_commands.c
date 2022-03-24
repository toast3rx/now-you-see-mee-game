#include <stdio.h>
#include <stdlib.h>
#include "../DeckUtils/deck.h"

void add_deck_command(playing_set *set) {

	deck *deck = create_deck();
	int card_number;
	scanf("%d", &card_number);
	for (int i = 0; i < card_number; i++) {

		playing_card *new_card = malloc(sizeof(*new_card));
		scanf("%d", &new_card->value);
		scanf("%s", new_card->symbol);
		dll_add_nth_node(deck, deck->size, (void *) new_card);
		free(new_card);
	}
		add_deck(set, deck);
		printf("The deck was successfully created with %d cards.\n", deck->size);
}

void deck_number_command(playing_set* set) {
	printf("The number of decks is %d.\n", get_decks_number(set));
}

void deck_len_command(playing_set *set, int index) {
	printf("The length of deck %d is %d.\n", index, get_deck_len(set, index));
}