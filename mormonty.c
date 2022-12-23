#include "monty.h"

/**
 * push_q - Adds a new element at the end of a list
 * @stack: first node
 * @line_number: where we got it
 */
void push_q(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *current;

	current = *stack;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freer_f(stack, line_number);
	}
	new->n = global.data;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}
