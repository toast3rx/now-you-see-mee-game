CC=gcc
CFLAGS=-std=c99 -ggdb3 -Wall -Wextra

build:
	$(CC)  $(CFLAGS)  DeckUtils/deck.c DoublyLinkedListImpl/DoublyLinkedList.c IO_Utils/IO_commands.c Utils/utils.c Exceptions/exceptions.c now_you_see_me.c -o tema1

pack:
	zip -r 311CA_LateaMihaiAlexandru_Tema1.zip \
		DeckUtils/ DoublyLinkedListImpl/ Exceptions/ IO_Utils/ Utils/ now_you_see_me.c \
		README.md Makefile
run:
	./tema1
clean:
	rm -f tema1
