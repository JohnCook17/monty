#include "monty.h"

void _pall(stack_t **head, int line_number)
{
	stack_t *current = *head;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	printf("PRINT OP Line number = %d\n", line_number);
}

void _pint()
{
	printf("print int \n");
}
