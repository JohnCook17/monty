#include "monty.h"

void _free(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next = NULL;
	printf("free call\n");
	while (current)
	{
		printf("free\n");
		next = current->next;
		free(current);
		current = next;
	}
}
