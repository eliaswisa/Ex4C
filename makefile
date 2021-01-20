
all: frequency

frequency: trie2.o main.o
		gcc -Wall -Werror -g -o frequency trie2.o main.o
trie2.o: trie2.c trie.h
		gcc -Wall -Werror -g -fPIC -c trie2.c
main.o: main.c trie.h
		gcc -Wall -Werror -g -fPIC -c main.c

.PHONY: clean all

clean:	
		rm -f *.o frequency