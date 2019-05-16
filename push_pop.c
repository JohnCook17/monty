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
	stack_t *newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
	{
		perror("Error: malloc failed");
		fclose(global.file);
		_free(&global.stack);
		exit(EXIT_FAILURE);
	}
	if (!isnum(global.cmd[1]))
	{
		printf("L:%d usage: push integer\n", line_number);
		_free(&global.stack);
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
void _pop(stack_t **stack1, int line_number)
{
	(void)(stack1);
	(void)(line_number);
	printf("pop \n");
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
