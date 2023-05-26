#include "monty.h"

/**
 * rotate_left - move top element to bottom of stack
 * @stack: pointer to the list
 * @line_number: line number
 */
void rotate_left(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *current_node = NULL;
	(void)line_number;

	if (!stack || !*stack)
		return;
	/* Remove top element */
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;

	/* Add to bottom of stack */
	current_node = *stack;

	while (current_node->next)
		current_node = current_node->next;
	current_node->next = temp;
	temp->prev = current_node;
}
