#include "monty.h"
/**
 * isnum - checks if var is num
 * @var: a variable
 * Return: 0 if is digit, 1 if not
 */
int isnum(char *var)
{
	if (*var == '-')
		var++;
	while (*var)
	{
		if (!isdigit(*var++))
		{
			return (0);
		}
	}
	return (1);
}
/**
 * _push - pushes to the stack
 * @stack1: the stack to push to
 * @line_number: not really used
 */
void _push(stack_t **stack1, int line_number)
{
	stack_t *newnode;
	newnode = global.stack = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(global.file);
		_free(&global.head);
		exit(EXIT_FAILURE);
	}
	if (!isnum(global.cmd[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free(&global.head);
		fclose(global.file);
		free(newnode);
		exit(EXIT_FAILURE);
	}
	newnode->n = atoi(global.cmd[1]);
	newnode->next = *stack1;
	newnode->prev = NULL;
	if ((*stack1) != NULL)
		(*stack1)->prev = newnode;
	*stack1 = newnode;
	line_number++;
}
/**
 * _pop - pops from the stack
 * @stack1: stack to pop from
 * @line_number: not really used
 */
void _pop(stack_t **stack, int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
                exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(tmp);
	if (*stack != NULL)
		(*stack)->prev = NULL;
}
/**
 * _swap - swaps two values in the stack
 * @stack1: stack to swap from
 * @line_number: not really used
 */
void _swap(stack_t **stack1, int line_number)
{
	(void)(stack1);
	(void)(line_number);
	printf("swap \n");
}
