#include "monty.h"

void _push(stack_t **stack1, int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	newnode->n = atoi(global.cmd[1]);
	newnode->next = *stack1;
	newnode->prev = NULL;
	if((*stack1) != NULL)
		(*stack1)->prev = newnode;
	*stack1 = newnode;
	printf("line number = %d\n", line_number);
	printf("node value %d\n", newnode->n);
}

void _pop()
{
	printf("pop \n");
}

void _swap()
{
	printf("swap \n");
}
