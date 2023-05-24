#include "monty.h"

/**
 * add_top_two - add top two element of a stack_tt
 * @stack: pointer to the list
 * @line_number: line number
 */
void add_top_two(stack_tt **stack, unsigned int line_number)
{
	if (!stack || !*stack || stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;

	delete_top_of_stack(stack, line_number);
}
