#include <stdio.h>
#include "constants.h"
#include <string.h>
#include <stdlib.h>
#include "../Exceptions/exceptions.h"

void split_string(char *str, char **words_array)
{
	int j = 0;
	int count = 0;
	for (int i = 0; i <= (int)(strlen(str)); i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			words_array[count][j] = '\0';
			count++;
			j = 0;
		} else {
			words_array[count][j] = str[i];
			j++;
		}
	}
}

char **read_command(char *command, int *args)
{
	fgets(command, MAX_WORD, stdin);

	// Count number of words and longest word for memory allocation
	int count_words = 0;
	int max_length = 0;
	int length = 0;

	for (int i = 0; i < (int)strlen(command); i++) {
		if (command[i] != ' ') {
			length++;
		} else {
			count_words++;
			if (max_length < length)
				max_length = length;
			length = 0;
		}
	}
	count_words++;
	if (length > max_length)
		max_length = length;

	char **words = (char **)calloc(count_words, sizeof(char *));
	if (!words) {
		memory_allocation_exception();
		return NULL;
	}
	for (int i = 0; i < count_words; i++) {
		words[i] = (char *)calloc((max_length + 1), sizeof(char));
		if (!words[i]) {
			memory_allocation_exception();
			return NULL;
		}
	}

	split_string(command, words);

	*args = count_words;
	return words;
}