#include "monty.h"
/**
 * push - makes a new element of the stack
 * @stack: the stack struct
 * @line_number: where we grab
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!new)
	{
		fprintf(stderr, "L%lu: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));

	new->n = global.data;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
	{

		(*stack)->prev = *new;
		(*stack)->new = NULL;
	}
	*stack = new;
}

/**
 * pall - prints all values
 * @stack: stack struct
 * @line_number: where we grab 2
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

