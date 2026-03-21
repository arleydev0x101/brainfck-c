#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiply(int, char);

#define MAX_LIMIT 30000
#define MEM_ERROR_MSG "Memory allocation error!\nPlease, free your memory to use this program, properly."

int main(int argc, char **argv)
{
	size_t i_limit = MAX_LIMIT;
	char *input = (char *)malloc(MAX_LIMIT * sizeof(char));

	if (input == NULL)
	{
		puts(MEM_ERROR_MSG);
		return 1;
	}

	input[0] = '\0';

	if (argc == 1)
	{
		printf("Enter an input: ");
		int c;
		size_t i = 0;

		while ((c = getchar()) != '\n' && c != EOF)
		{
			if (i + 1 >= i_limit)
			{
				i_limit += MAX_LIMIT;
				char *tmp = (char *)realloc(input, i_limit);
				if (tmp == NULL)
				{
					puts(MEM_ERROR_MSG);
					free(input);
					return 1;
				}
				input = tmp;
			}
			input[i++] = (char)c;
		}
		input[i] = '\0';
	}

	for (int i = 1; i < argc; ++i)
	{

		size_t n_mem = strlen(input) + strlen(argv[i]) + 2;

		if (n_mem >= i_limit)
		{
			i_limit = n_mem + MAX_LIMIT;
			char *tmp = (char *)realloc(input, i_limit);
			if (tmp == NULL)
			{
				puts(MEM_ERROR_MSG);
				free(input);
				return 1;
			}
			input = tmp;
		}

		strcat(input, argv[i]);
		strcat(input, " ");
	}

	if (strlen(input) > 0)
	{
		input[strlen(input) - 1] = '\0';
	}

    int tape[5] = {0, 30, 70, 100, 110};
    int pointer = 0; 

    multiply(10, '+');
    putchar('[');
    putchar('>'); multiply(3, '+');
    putchar('>'); multiply(7, '+');
    putchar('>'); multiply(10, '+');
    putchar('>'); multiply(11, '+');
    multiply(4, '<'); putchar('-');
    putchar(']');
    putchar('\n');

    for (int i = 0; input[i]; ++i) {
        int target = input[i];
        int best_cell = 0;
        int min_cost = 9999;

        for (int c = 0; c < 5; c++) {
            int pointer_moves = abs(pointer - c);
            int value_changes = abs(tape[c] - target);
            int total_cost = pointer_moves + value_changes;

            if (total_cost < min_cost) {
                min_cost = total_cost;
                best_cell = c;
            }
        }

        if (pointer < best_cell) {
            multiply(best_cell - pointer, '>');
        } else if (pointer > best_cell) {
            multiply(pointer - best_cell, '<');
        }
        pointer = best_cell;

        int diff = target - tape[pointer];
        if (diff > 0) {
            multiply(diff, '+');
        } else if (diff < 0) {
            multiply(-diff, '-');
        }

        putchar('.');
        putchar('\n');
        tape[pointer] = target;
    }
	free(input);
	return 0;
}

void multiply(int n, char c)
{
	for (int i = 0; i < n; ++i)
	{
		putchar(c);
	}
}
