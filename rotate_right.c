#include "monty.h"

/**
 * rotate_right - move bottom element to top of stack
 * @stack: pointer to the list
 * @line_number: line number
 */
void rotate_right(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;
	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	/* Remove last element */
	current_node = *stack;
	while (current_node->next)
		current_node = current_node->next;
	current_node->prev->next = NULL;
	current_node->prev = NULL;

	/* Add element to top of stack */
	current_node->next = *stack;
	(*stack)->prev = current_node;
	*stack = current_node;
}
