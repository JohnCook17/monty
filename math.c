#include "monty.h"
/**
 * _add - adds the values of the stacks
 * @stack1: stack to add values of
 * @line_number: not really used
 */
void _add(stack_t **stack, int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
	*stack = (*stack)->next;
	tmp->next->n += tmp->n;
	free (tmp);
}
void _sub(stack_t **stack, int line_number)
{
        stack_t *tmp = *stack;

        if (*stack == NULL || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        *stack = (*stack)->next;
        tmp->next->n -= tmp->n;
        free (tmp);
}
void _div(stack_t **stack, int line_number)
{
        stack_t *tmp = *stack;

        if (*stack == NULL || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        *stack = (*stack)->next;
        tmp->next->n /= tmp->n;
        free (tmp);
}
void _mult(stack_t **stack, int line_number)
{
        stack_t *tmp = *stack;

        if (*stack == NULL || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        *stack = (*stack)->next;
        tmp->next->n *= tmp->n;
        free (tmp);
}
void _mod(stack_t **stack, int line_number)
{
        stack_t *tmp = *stack;

        if (*stack == NULL || !(*stack)->next)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        *stack = (*stack)->next;
        tmp->next->n %= tmp->n;
        free (tmp);
}
/**
 * _nop - no op
 * @stack1: stack to do nothing with
 * @line_number: not used in a function that does nothing
*/
void _nop(stack_t **stack1, int line_number)
{
	(void)(stack1);
	(void)(line_number);
}
