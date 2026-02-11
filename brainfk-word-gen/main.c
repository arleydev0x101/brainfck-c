#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiply(int, char);

#define MAX_LIMIT 1000

int main(int argc, char** argv) {
	size_t i_limit = MAX_LIMIT;
	char* input = (char*) malloc(MAX_LIMIT * sizeof(char));

	if (argc == 1) {
		printf("Enter an input: ");
		fgets(input, MAX_LIMIT, stdin);
		input[strlen(input) - 1] = 0;
	}

	for (int i = 1; i < argc; ++i) {
		strcat(input, argv[i]);
		input[strlen(input)] = ' ';
		if (strlen(input) + strlen(argv[i]) >= i_limit){
			i_limit += 1000;
			char* tmp = (char*)realloc(input, i_limit);
			input = tmp;
		}
	}

	input[strlen(input) - 1] = 0;

	int tmp, t;

	for (int i = 0; input[i]; ++i){
		if (i){
			tmp = abs(input[i] - input[i - 1]);
			t = input[i] > input[i - 1];
			if (tmp <= 10){
				multiply(tmp, t ? '+' : '-');
			}
			else {
				multiply(tmp % 10, t ? '+' : '-');
				putchar('>');
				multiply(tmp / 10, t ? '+': '-');
				putchar('[');	putchar('<');
				multiply(10,  '+');
				putchar('>');	putchar('-');
				putchar(']');	putchar('<');
			}
		}
		else {
			multiply(input[i] % 10, '+');
			putchar('>');
			multiply(input[i] / 10, '+');
			putchar('[');	putchar('<');
			multiply(10,  '+');
			putchar('>');	putchar('-');
			putchar(']');	putchar('<');
		}
		putchar('.');	putchar('\n');
	}
	free(input);
	return 0;
}

void multiply(int n, char c){
	for (int i = 0; i < n; ++i) {
		putchar(c);
	}
}
