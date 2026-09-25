# Builds mgba-harness against the system libmgba (Debian/Ubuntu: apt install libmgba-dev libpng-dev).
CC ?= cc
CFLAGS ?= -O2 -Wall -Wextra
LDLIBS = -lmgba -lpng

.PHONY: all clean

all: mgba-harness

mgba-harness: harness.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

clean:
	$(RM) mgba-harness
