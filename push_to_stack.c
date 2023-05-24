#include "monty.h"

/**
 * push_to_stack - adds a new node at the beginning of a stack
 * @stack: pointer to stack pointer to the list
 * @line_number: line number
 */
void push_to_stack(stack_tt **stack, unsigned int line_number)
{
	stack_tt *current_node = NULL;

	if (!is_all_digits(push_arg) || !push_arg)
	{
		fprintf(stderr, "L%d: usage: push integer %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	current_node = malloc(sizeof(stack_tt));
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
