CFLAGS = -Werror -Wall -O3
GEN_DIR = brainfk-word-gen/main.c
CC = g++

all:
	@echo "Compiling both main and the generator..."
	@$(CC) main.c $(CFLAGS) -o bin/brainfk
	@$(CC) $(GEN_DIR) $(CFLAGS) -o bin/brainfk-gen
	@echo "Compilation is complete!"

main:
	@echo "Compiling brainfuck interpreter..."
	@$(CC) main.c $(CFLAGS) -o bin/brainfk
	@echo "Compilation is complete!"

generator:
	@echo "Compiling brainfuck generator..."
	@$(CC) $(GEN_DIR) $(CFLAGS) -o bin/brainfk-gen
	@echo "Compilation is complete!"

.PHONY: clean
clean:
	@rm bin/brainfk bin/brainfk-gen
	@echo "Temporary files has been removed!"
