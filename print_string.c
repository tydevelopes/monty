#include "monty.h"

/**
 * print_string - prints string starting at top of stack
 * @stack: pointer to the list
 * @line_number: line number
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	const stack_t *current_node = NULL;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}
	(void)line_number;

	current_node = *stack;

	while (current_node)
	{
		if (current_node->n < 0 || current_node->n > 255 || current_node->n == 0)
		{
			break;
		}
		printf("%c\n", current_node->n);
		current_node = current_node->next;
	}
}
