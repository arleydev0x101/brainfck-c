#include <linux/limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiply(int, char);

#define MAX_LIMIT 1000

int main(int argc, char** argv) {
	char input[MAX_LIMIT] = {0};

	if (argc == 1) {
		printf("Enter an input: ");
		fgets(input, MAX_LIMIT, stdin);
		input[strlen(input) - 1] = 0;
	}

	for (int i = 1; i < argc; ++i) {
		strcat(input, argv[i]);
		input[strlen(input)] = ' ';
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
				putchar('[');
				putchar('<');
				multiply(10,  '+');
				putchar('>');
				putchar('-');
				putchar(']');
				putchar('<');
			}
		}
		else {
			multiply(input[i] % 10, '+');
			putchar('>');
			multiply(input[i] / 10, '+');
			putchar('[');
			putchar('<');
			multiply(10,  '+');
			putchar('>');
			putchar('-');
			putchar(']');
			putchar('<');
		}
		putchar('.');
		putchar('\n');
	}
}
// ++>+++++++[<++++++++++>-]<.

void multiply(int n, char c){
	for (int i = 0; i < n; ++i) {
		putchar(c);
	}
}
