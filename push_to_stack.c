#include "monty.h"

/**
 * push_to_stack - adds a new node at the beginning of a stack
 * @stack: pointer to stack pointer to the list
 * @line_number: line number
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = NULL;

	if (!push_arg || !is_all_digits(push_arg))
	{
		fprintf(stderr, "L%d: usage: push integer %s\n", line_number, opcode);
		execution_failed = 1;
		return;
	}
	current_node = malloc(sizeof(stack_t));
	check_malloc_s(current_node);

	current_node->n = atoi(push_arg);
	current_node->next = NULL;
	current_node->prev = NULL;

	if (!*stack)
		*stack = current_node;
	else
	{
		current_node->next = *stack;
		(*stack)->prev = current_node;
		*stack = current_node;
	}
}
