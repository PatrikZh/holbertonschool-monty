#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
* global_s - the structure we are getting from abroad
* @data: holds data
* @extract: a file we are extracting
* @token: the splitter for the line we are getting
* @line: the line we are getting
*/
typedef struct global_s
{
	int data;
	FILE *extract;
	char *token, *line;
} global_t;

extern global_t global;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* all prototypes */

/* monty.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
/* montychecker.c */
void checkop(stack_t **stack, unsigned int line_number);
void parse(int argc, char *argv[]);
void read_line(stack_t **stack);
void check_num(stack_t **stack, unsigned int line_number);
void freer_f(stack_t **stack, unsigned int __attribute__ ((unused))line_number);
/* mormonty.c */
void push_q(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
/* freer.c */
void lineclear(stack_t **stack, unsigned int line_number);
#endif
