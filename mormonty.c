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
/**
* swap - does the switcheroo
* @stack: the stack
* line_number: do i even need to explain anymore
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freer_f(stack, line_number);
	}
	num = (*stack)->n;
	tmp = (*stack)->next;

	(*stack)->n = tmp->n;
	tmp->n = num;
}
/**
* nop - literally does nothing
* @line_number: Mason
* @stack: My life
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)**stack;
	(void)line_number;
}
/**
* add - adds the two top elements
* @stack:are youu serious rn
* @line_number: L + Ratio
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't  add, stack too short\n", line_number);
		freer_f(stack, line_number);
	}
	tmp = *stack;
	*stack = (*stack)->next;

	(*stack)->n += tmp->n;
	free(tmp);
	(*stack)->prev = NULL;
}
