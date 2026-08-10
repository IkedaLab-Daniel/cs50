CC = cc
LIBCS50_DIR = ../scrabble/libcs50/build
CFLAGS = -std=c11 -Wall -Wextra -Werror -I$(LIBCS50_DIR)/include

readability: readability.c $(LIBCS50_DIR)/lib/libcs50.a
	$(CC) $(CFLAGS) readability.c $(LIBCS50_DIR)/lib/libcs50.a -o readability

clean:
	rm -f readability
