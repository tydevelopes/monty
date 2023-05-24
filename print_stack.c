#include "monty.h"

/**
 * print_stack - prints all elements of a stack_t list
 * @stack: pointer to the list
 * @line_number: line number
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	const stack_t *current_node = NULL;
	(void)line_number;

	current_node = *stack;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
