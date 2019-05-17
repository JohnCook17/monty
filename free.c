#include "monty.h"

void _free(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next = NULL;

	free(global.line);
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
