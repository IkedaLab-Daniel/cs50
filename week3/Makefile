CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror -I../scrabble/libcs50/build/include

recursion: recursion.c ../scrabble/libcs50/build/lib/libcs50.a
	$(CC) $(CFLAGS) recursion.c ../scrabble/libcs50/build/lib/libcs50.a -o recursion

clean:
	rm -f recursion
