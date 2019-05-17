#include "monty.h"
/**
 * _pall - print all values in the stack
 * @head: the head of the stack to print
 * @line_number: not really used
 */
void _pall(stack_t **head, int line_number)
{
	stack_t *current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	line_number++;
}
/**
 * _pint - print a given int
 */
void _pint(void)
{
	if (!global.stack->n)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", global.line_number);
	}
	else
		printf("%d\n", global.stack->n);
}
