CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror -I../scrabble/libcs50/build/include

caesar: caesar.c ../scrabble/libcs50/build/lib/libcs50.a
	$(CC) $(CFLAGS) caesar.c ../scrabble/libcs50/build/lib/libcs50.a -o caesar

clean:
	rm -f caesar
