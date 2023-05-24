#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: pointer to begining of list
 */
void free_stack(stack_t *stack)
{
	stack_t *curr_node = NULL;

	if (!stack)
		return;

	curr_node = stack;

	while (stack->next)
	{
		stack = stack->next;
		free(curr_node);
		curr_node = stack;
	}
	free(stack);
}
