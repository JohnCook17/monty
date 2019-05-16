#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globvar - global var
 * @cmd: command
 * @line_number: the line number
 * @stack: the stack
 * @file: file to open
 */
typedef struct globvar
{
	char *cmd[128];
	int line_number;
	stack_t *stack;
	FILE *file;
} gv;

extern gv global;

void _strtok(char *line);
void print_cmd(void);
void (*op())();
void _push();
void _pall();
void _pint();
void _pop();
void _swap();
void _add();
void _nop();
void _free();

#endif
