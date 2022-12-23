#include "monty.h"

global_t global;

/**
* main - the heart of monty
* @argc: number of args
* @argv: the arguments held in an array
* Return: success!
*/
int main(int argc, char *argv[])
{
	stack_t *stack;

	stack = NULL;
	parse(argc, argv);
	read_line(&stack);

	free(global.line);
	free_stack(stack);
	fclose(global.extract);
	return (EXIT_SUCCESS);
}

