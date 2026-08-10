CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror -Ilibcs50/build/include

scrabble: scrabble.c libcs50/build/lib/libcs50.a
	$(CC) $(CFLAGS) scrabble.c libcs50/build/lib/libcs50.a -o scrabble

clean:
	rm -f scrabble
