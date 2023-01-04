#include "monty.h"

/**
* lineclear - frees linefinder if not found
* @stack: origin of stack
* @line_number: where we found it
*/
void lineclear(stack_t **stack, unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	freer_f(stack, line_number);
}

