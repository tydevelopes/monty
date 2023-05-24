#include "monty.h"

/**
 * stack_length - returns the number of elements in a stack
 * @stack: pointer to the stack
 * Return: number of elements in the list
 */
size_t stack_length(const stack_t *stack)
{
	size_t length = 0;
	const stack_t *current_node = NULL;

	if (!stack)
		return (length);
	current_node = stack;
	while (current_node)
	{
		length++;
		current_node = current_node->next;
	}
	return (length);
}
