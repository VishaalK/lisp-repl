#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include "mpc.h"

int main(int argc, char** argv) {
	printf("Lisp Version 0.1 - Press Ctrl+C to Exit\n");

	while (1) {

		/* Create Some Parsers */
		mpc_parser_t* Number   = mpc_new("number");
		mpc_parser_t* Operator = mpc_new("operator");
		mpc_parser_t* Expr     = mpc_new("expr");
		mpc_parser_t* Lispy    = mpc_new("lispy");

		/* Define them with the following Language */
		mpca_lang(MPCA_LANG_DEFAULT,
		  "                                                     \
		    number   : /-?[0-9]+/ ;                             \
		    operator : '+' | '-' | '*' | '/' ;                  \
		    expr     : <number> | '(' <operator> <expr>+ ')' ;  \
		    lispy    : /^/ <operator> <expr>+ /$/ ;             \
		  ",
		  Number, Operator, Expr, Lispy);

		
		char* input = readline("lisp> "); // pointer to character array

		add_history(input);
	
		if (!strcmp("quit",input)) {
			printf("Exiting!\n");
			return 0;
		}	
		printf("You input %s\n", input);

		free(input);
	}
	return 0;
}
