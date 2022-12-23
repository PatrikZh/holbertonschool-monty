#include "monty.h"

/**
* checkop - checks op compatibility
* @stack: the stack struct
* @line_number: where it is
*/
void checkop(stack_t **stack, unsigned int line_number)
{
	instruction_t codes[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; codes[i].opcode; ++i)
	{
		if (!strcmp(global.token, codes[i].opcode))
		{
			global.token = strtok(NULL, " \n");
			codes[i].f(stack, line_number);
			break;
		}
	}
	if (!codes[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, global.token);
		freer_f(stack, line_number);
	}
}
/**
* freer_f - frees everything
* @stack: the stack carrying
* @line_number: Where we grab the line from
*/
void freer_f(stack_t **stack, unsigned int __attribute__ ((unused))line_number)
{
	free(global.line);
	free_stack(*stack);
	fclose(global.extract);
	exit(EXIT_FAILURE);
}

/**
* parse - analizes the arguments
* @argc: number of arguments
* @argv: pointer to an array containing the arguments
*/
void parse(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.extract = fopen(argv[1], "r");
	if (!global.extract)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
* read_line - reads line and accordingly acts
* @stack: stack struct
*/
void read_line(stack_t **stack)
{
	int len = 0, type = 0; 
	size_t n = 0;
	unsigned int line_number = 0;

	global.line = NULL;
	while ((len = getline(&global.line, &n, global.extract)) != EOF)
	{
		line_number++;
		global.token = strtok(global.line, " \n");
		if (!global.token || global.token[0] == '#')
			continue;
		if (!strcmp(global.token, "stack"))
		{
			type = 0;
			continue;
		}
		else if (!strcmp(global.token, "queue"))
		{
			type = 1;
			continue;
		}
		if (!strcmp(global.token, "push"))
		{
			global.token = strtok(NULL, " \n");
			if (global.token)
			{
				check_num(stack, line_number);
				global.data = atoi(global.token);
				if (!type)
					push(stack, line_number);
				else
					push_q(stack, line_number);
				continue;
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				freer_f(stack, line_number);
			}
		}
		checkop(stack, line_number);
	}
}
/**
* check_num - checks if there are numbers in str
* @stack: start of the stack
* @line_number: where we get the argument in file
*/
void check_num(stack_t **stack, unsigned int line_number)
{
	int i;

	for (i = 0; global.token[i]; i++)
	{
		if (i == 0 && global.token[0] == '-')
			i++;
		if (global.token[i] < '0' || global.token[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			freer_f(stack, line_number);
		}
	}
}
