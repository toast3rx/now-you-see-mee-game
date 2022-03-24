build:
	gcc -ggdb3 -Wall -Wextra  DeckUtils/deck.c DoublyLinkedListImpl/DoublyLinkedList.c IO_Utils/IO_commands.c now_you_see_me.c -o a.out

#pack:
#	zip -r  311CA_LateaMihaiAlexandru_Tema3.zip \
#		image_editor.c utils.c utils.h image_utils.c image_utils.h command_check.c \
#		command_check.h commands.c commands.h constants.h structs.h exceptions.h exceptions.c \
#	       	image_example Makefile README README.md
run:
	./a.out
clean:
	rm -f a.out
