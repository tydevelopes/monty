#include "monty.h"

/**
 * delete_top_of_stack - delete top element of a stack_t list
 * @stack: pointer to the list
 * @line_number: line number
 */
void delete_top_of_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		global_vars.execution_failed = 1;
		return;
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
