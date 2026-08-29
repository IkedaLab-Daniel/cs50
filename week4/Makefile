CC = cc
CFLAGS = -std=c11 -Wall -Wextra -Werror -I../scrabble/libcs50/build/include

all: code

code: code.c ../scrabble/libcs50/build/lib/libcs50.a
	$(CC) $(CFLAGS) code.c ../scrabble/libcs50/build/lib/libcs50.a -o code

clean:
	rm -f code
