CFLAGS = -Werror -Wall -O3
GEN_DIR = ./brainfk-word-gen/main.c
COMPILER = g++

all:
	@echo "Compiling both the main and the generator..."
	@$(COMPILER) main.c $(CFLAGS) -o brainfk
	@$(COMPILER) $(GEN_DIR) $(CFLAGS) -o brainfk-gen
	@echo "Compilation is complete!"

main:
	@echo "Compiling both the main and the generator..."
	@$(COMPILER) main.c $(CFLAGS) -o brainfk
	@echo "Compilation is complete!"

generator:
	@echo "Compiling brainkfk generator..."
	@$(COMPILER) $(GEN_DIR) $(CFLAGS) -o brainfk-gen
	@echo "Compilation is complete!"

.PHONY: clean
clean:
	@rm brainfk brainfk-gen
	@echo "Temporary files has been removed!"
