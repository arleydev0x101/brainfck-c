#include <stdio.h>
#include <string.h>

void multiply(int, char);

int main(int argc, char** argv) {
	char input[9999];

	if (argc == 1) {
		printf("Enter an input: ");
		fgets(input, 9999, stdin);
		input[strlen(input) - 1] = 0;
	}

	if (strlen(input))
		for (int i = 1; i < argc; ++i){
			for (int y = 0; y < strlen(argv[i]); ++y){
				multiply(argv[i][y] % 10, '+');
				if (y - 1 > 0){
					if (argv[i][y - 1] != argv[i][y])
						multiply(argv[i][y] % 10, '+');
					else if (argv[i][y - 1] % argv[i][y] <= 9)
						multiply(argv[i][y - 1] % argv[i][y], '+');
				}
				else if (argv[i][y] % 10 != 0){
					printf(">");
					multiply(argv[i][y] / 10, '+');
					printf("[<");
					multiply(10, '+');
					printf(">-]<");
				}
				printf(".");
			}
			printf("\n");
		}

	else printf("%s [words]", argv[0]);
}
// ++>+++++++[<++++++++++>-]<.

void multiply(int n, char c){
	for (int i = 0; i < n; ++i) {
		printf("%c", c);
	}
}
