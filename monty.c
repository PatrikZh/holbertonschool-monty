#include "monty.h"
/**
 * push - makes a new element of the stack
 * @stack: the stack struct
 * @line_number: where we grab
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new->n = global.data;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
	{

		(*stack)->prev = new;
		(*stack)->next = NULL;
	}
	*stack = new;
}

/**
 * pall - prints all values
 * @stack: stack struct
 * @line_number: where we grab 2
*/
void pall(stack_t **stack, unsigned int __attribute__ ((unused))line_number)
{
	stack_t *current;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
* free_stack - frees a stack
* @stack: the starting point of the stack
*/
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
/**
* pint - prints the value at the top of the stack
* @stack: start of stack
* @line_number: where we got it from
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freer_f(stack, line_number);
	}
	printf("%d\n", (*stack)->n);
}
/**
* pop - removes top element of the stack
* @stack: top of the stack ptr
* @line_number: where we got it from
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		freer_f(stack, line_number);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	if (*stack)
		(*stack)->prev = NULL;
}	
