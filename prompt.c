#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

int main(int argc, char** argv) {
	printf("Lisp Version 0.1 - Press Ctrl+C to Exit\n");

	while (1) {
		//fputs("lisp> ", stdout);
		//fgets(input, MAX_LINE_SIZE, stdin);
		char* input = readline("lispy> "); // pointer to character array

		add_history(input);
		
		printf("You input %s\n", input);

		free(input);
	}
	return 0;
}
