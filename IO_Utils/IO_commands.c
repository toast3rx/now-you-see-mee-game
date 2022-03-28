#include <stdio.h>
#include <stdlib.h>
#include "../DeckUtils/deck.h"
#include "../Exceptions/exceptions.h"

void add_deck_command(playing_set *set) {

	deck *deck = create_deck();
	int card_number;
	scanf("%d", &card_number);
	for (int i = 0; i < card_number; i++) {

		playing_card *new_card = malloc(sizeof(*new_card));

		scanf("%d", &new_card->value);
		scanf("%s", new_card->symbol);

		while (!is_card_valid(new_card->value, new_card->symbol)) {
			invalid_card_exception();
			scanf("%d", &new_card->value);
			scanf("%s", new_card->symbol);
		}

		dll_add_nth_node(deck, deck->size, (void *) new_card);
		
		free(new_card);
	}
		add_deck(set, deck);
		printf("The deck was successfully created with %d cards.\n", deck->size);
	free(deck);
}

void deck_number_command(playing_set* set) {
	printf("The number of decks is %d.\n", get_decks_number(set));
}

void deck_len_command(playing_set *set, int index) {
	int deck_len = get_deck_len(set, index);

	if (deck_len == -1) {
		deck_index_out_of_bounds_exception();
		return;
	}

	printf("The length of deck %d is %d.\n", index, deck_len);
}