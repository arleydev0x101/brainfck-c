CFLAGS = -Werror -Wall
GEN_DIR = ./brainfk-word-gen/main.c

all:
	g++ main.c $(CFLAGS) -o brainfk

generator:
	g++ $(GEN_DIR) $(CFLAGS) -o brainfk-gen

.PHONY: clean
clean:
	rm brainfk brainfk-gen
