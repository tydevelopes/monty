#include "monty.h"

/**
 * div_top_two - divide top two element of a stack_t
 * @stack: pointer to the list
 * @line_number: line number
 */
void div_top_two(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || stack_length(*stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		execution_failed = 1;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		execution_failed = 1;
		return;
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;

	delete_top_of_stack(stack, line_number);
}
